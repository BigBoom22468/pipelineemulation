#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>

int main(int argc, char* argv[]){

    int fd[2];
    pid_t pid;
	char *a, *b;
	a = malloc(sizeof(char)*255);
	b = malloc(sizeof(char)*255);

	
    if(pipe(fd) < 0){
        printf("Can\'t create pipe\n");
        exit(-1);
    }
	sprintf(a, "%d", fd[0]);
	sprintf(b, "%d", fd[1]); 
	
	pid = fork();
    if(pid < 0) {
        printf("Can\'t fork child\n");
        exit(-1);
    }
	
    else {
        if (pid > 0) {
			
            execl(argv[1], "Writer", a, b, NULL);
            perror("Can't exec");
        }
        if (pid == 0) {
			
            execl(argv[2], "Reader", a, b, NULL);
            perror("Can't exec");
        }
    }
	
    return 0;
}
