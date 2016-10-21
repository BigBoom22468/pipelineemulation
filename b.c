#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>

int main(int argc, char* argv[]){
	
    int size;
    char string[14];
    close(atoi(argv[2]));
    size = read(atoi(argv[1]), string, 14);

    if(size < 0){

        printf("Can\'t read string\n");
        exit(-1);
    }
    printf("%s", string);
    close(atoi(argv[1]));
    return 0;	
}
