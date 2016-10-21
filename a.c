#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>

int main(int argc, char* argv[]){
	
    int size;
    close(atoi(argv[1]));
    size = write(atoi(argv[2]), "Hello, world!", 14);

    if(size != 14){

        printf("Can\'t write all string\n");
        exit(-1);
    }
    close(atoi(argv[2]));
    return 0;
}
