#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <string.h>
#include <dirent.h>
#include <sys/inotify.h>

main(int argc, char** argv, char** envp)
{
	int in, watch, ret;
	int mask = IN_CREATE | IN_DELETE | IN_MOVE_SELF;
	char buf[4096];
	struct inotify_event* event;
	if (argc < 2)
        {
                printf("Not enough arguments\n");
                return(0);
        }

	in = inotify_init();
	if (in < 0) {
		perror("inotify_init");
		return -1;
	}

	watch = inotify_add_watch(in, argv[1], mask);
	if (watch < 0) {
		perror("inotify_add_watch");
		return -1;
	}
	ret = read(in, buf, 4096);
	if (ret > 0) {
		event = buf;
		printf("path: %s " event->name);
		if(event->mask & IN_CREATE)
			printf("event: create\n");
		else if(event->mask & IN_DELETE)
			printf("event: delete\n");
		else if (event->mask & IN_MOVE_SELF)
			printf("event: move\n");
		else
			printf("unknown\n");
	}
	close(in);
	return 0;
}
