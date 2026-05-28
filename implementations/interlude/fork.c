#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>

int main(int argc , char * argv[]){
    printf("this is system call (PID:%d)\n",(int) getpid());
    pid_t rc = fork();
    // if forked failed exit
    if(rc<0){
        fprintf(stderr,"fork failed\n");
        exit(1);
    }
    else if(rc==0){
         printf("Child process %d\n",(int) getpid());
    }
    else {
        printf("Parent: child PID=%d, parent PID=%d\n", (int)rc, (int)getpid());
    }
    return 0;
}