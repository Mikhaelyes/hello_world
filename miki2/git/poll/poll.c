#include <stdio.h>
#include <stdlib.h>
#include <poll.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <assert.h>

const size_t size = 20000;

int enablepolls(int num, struct pollfd* pollfds, char** argv)
{
	for (int i = 0; i < num; i++)
        {
                pollfds[i].fd = open(argv[i + 1], O_NONBLOCK | O_RDONLY);
        	assert (pollfds[i].fd > 0 && "No fifo");
        	pollfds[i].events = POLLIN;
        	pollfds[i].revents = 0;
        }
	return 0;
}

int main(int argc, char** argv)
{
    int num = argc - 1;
    int i;
    if(num < 0) {
	    printf("Not enough arguments\n");
    }
    struct pollfd* pollfds = (struct pollfd*)malloc(num * sizeof(struct pollfd));
    int rpoll;
    int sread;
    char buf[size];
    enablepolls(num, pollfds, argv);

    while (rpoll = poll(pollfds, num, -1))
    {
    for (int i = 0; i < num; i++)
        if (pollfds[i].revents & POLLIN)
        {
            sread = read(pollfds[i].fd, buf, size);
            if (sread > 0)
            {
                buf[sread] = '\0';
                printf("fifo: %s\t read: %s", argv[i + 1], buf);
            }
        }
    }
    free(buf);
    free(pollfds);
    return 0;
}
