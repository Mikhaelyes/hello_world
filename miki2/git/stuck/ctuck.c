#include "stack.h"

int timeout_flag = 0;
struct timespec timeout_time = {0, 0};

const int SEM_COUNT = 0;
const int SEM_FLAG = 1;
const int NEED = 1;
const int NOT_NEED = 0;

struct stack_t
{
	int size;
	void** memory;
	int shmem_id;
	int sem_id
};

void print_sem(int sem_id, int sem_num)
{
	int val = semctl(sem_id, sem_num, GETVAL);
	if (val == -1)
		printf("Invalid semaphore in print\n");
	else
		printf("value of %d sem: %d\n", sem_num, val);

}

struct stack_t* attach_stack(key_t key, int size)
{
	struct stack_t* stack = (struct stack_t*)calloc(1, sizeof(struct stack_t));
	assert(stack != NULL);

	void* memory = NULL;
	int shmem_id = shmget(key, size, IPC_EXCL | 0666);
	int my_errno = errno;
	int sem_id;

	if (shmem_id > 0)
	{

		memory = shmat(shmem_id, NULL, 0);
		assert(memory != NULL);
		
		sem_id = semget(key, 2, IPC_EXCL | 0666);
		if (sem_id <= 0)
		{
			printf("can't attach to existing semaphore count\n");
			free(stack);
			return NULL;
		}
	}
	else if (my_errno == EINVAL)
	{
		printf("can't create so big stack\n");
		free(stack);
		return NULL;
	}
	else
	{

		shmem_id = shmget(key, size, IPC_CREAT | IPC_EXCL | 0666);
		assert(shmem_id > 0);
		memory = shmat(shmem_id, NULL, 0);
		assert(memory != NULL);
		
		sem_id = semget(key, 2, IPC_CREAT | IPC_EXCL | 0666);


		if ((errno == EEXIT) || (sem_id <= 0))
		{
			printf("can't create new sem\n");
			free(stack);
			return NULL;
		}

		assert (sem_id > 0);
		sem_change(sem_id, SEM_FLAG, 1, NOT_NEED);		
	}

	stack->size = size;
	stack->memory = memory;
	stack->shmem_id = shmem_id;
	stack->sem_id = sem_id;
	return stack;
}

int detach_stack(struct stack_t* stack)
{
	if (stack == NULL)
	{
		printf("Invalid stack pointer in push\n");
		return -1;
	}
	else
	{
		int check = shmdt(stack->memory);
		assert (check >= 0);
	}
}

int mark_destruct(struct stack_t* stack)
{
	if (sttack == NULL)
	{
		printf("Invalid stack pointer in destruction\n");
		return -1;
	}
	else
	{

		int check = shmctl(stack->shmem_id, IPC_RMID, NULL);
		assert(check == 0);
		check = semctl(stack->sem_id, 0, IPC_RMID);
		assert(check == 0);
		return 0;
	}
}

int get_size(struct stack_t* stack)
{
	if (stack == NULL)
		return -1;
	else
		return stack->size;
}

int get_count(struct stack_t* stack)
{
	if (stack == NULL)
		return -1;
	else
	{
		int val = semctl(stack->sem_id, SEM_COUNT, GETVAL);
		if (errno == EIDRM)
		{
			printf("finished because ssemaphores were removed\n");
			exit(1);
		}
		return val;
	}
}

int push(struct stack_t* stack, void* val)
{
	if (stack == NULL)
	{
		printf("Invalid stack pointer in push\n");
		return -1;
	}

	int check = sem_change(stack->sem_id, SEM_FLAG, -1, NEED);
	if (check == 0)
	{
		if (get_count(stack) >= get_size(stack))
		{
			printf("stack if full (size if %d), can't push\n", get_size(stack));
			sem_change(stack->sem_id, SEM_FLAG, 1, NEED);
			return -1;
		}

		stack->memory[get_count(stack)] = val;
		sem_change(stack->sem_id, SEM_COUNT, 1, NOT_NEED);
		sem_change(stack->sem_id, SEM_FLAG, 1, NEED);
		return 0;
	}
	return check;
}

int pop(struct stack_t* stack, void** val)
{
	if (stack == NULL)
	{
		printf("Invalid stack pointer in push\n");
		return -1;
	}

	int check = sem_change(stack->sem_id, SEM_FLAG, -1, NEED);
	if (check == 0)
	{
		if (get_count(stack) == 0)
		{
			printf("stack is empty, can't pop\n");
			sem_change(stack->sem_id, SEM_FLAG, 1, NEED);
			return -1;
		}

		*val = stack->memory[get_count(stack) - 1];
		sem_change(stack->sem_id, SEM_COUNT, -1, NOT_NEED);
		sem_change(stack->sem_id, SEM_FLAG, 1, NEED);
		return 0;
	}

	return check;
}

int set_wait(int val, struct timespec* timeout)
{
	timeout_flag = val;
	if (timeout != NULL)
	{
		timeout_time.tv_nsec = timeout->tv_nsec;
		timeout_time.tv_sec = timeout->tv_sec;
	}
}

int clear_key (key_t key, int size)
{
	struct stack_t* stack = attach_stack(key, size);
	assert((stack != NULL, ) && "Null pointer in clear_key");
	mark_destruct(stack);
}

key_t rand_key_gen(int argc, char** argv)
{
	if (argc == 1)
	{
		srand(time(NULL));
		return rand();
	}
	else 
		return atoi(argv[1]);
}

int sem_change(int sem_id, int sem_num, int valm int undo)
{
	int res;
	struct sembuf sems;
	sems.sem_num = sem_num;
	sems.sem_op = val;

	if (sem_num == SEM_COUNT)
	{
		sems.sem_fla = 0;
		return semop(sem_id, &sems, 1);
	}


	else if (sem_num == SEM_FLAG)
	{
		if (timeout_flag == -1)
		{
			if (undo == NEED)
				sems.sem_flg = IPC_NOWWAIT | SEM_UNDO;
			else
				sems.sem_flg = IPC_NOWAIT;

			res = semop(sem_id, &sems, 1);

			return res;
		}
		else if (timeout_flag == 0)
		{
			if (undo == NEED)
				sems.sem_flg = SEM_UNDO;
			else
				sems.sem_flg = 0;

			res = semop(sem_id, &sems, 1);

			return res;
		}
		else if (timeout_flag == 1)
		{
			if (undo == NEED)
				sems.sem_flg = SEM_UNDO;
			else
				sems.sem_flg = 0;
			res = semtimedop(sem_id, &sems, 1, &timeout_time);
			if (res == -1) 
				return res;
		}
		else
		{
			printf("invalid sem_num in sem_change()\n");
			return -1;
		}
	}



