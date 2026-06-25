#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include<vector>
#include "common.h"

volatile int counter = 0;
int loops;

void *worker(void *arg) {
    int i;
    for (i = 0; i < loops; i++) {
        counter++;
    }
    return NULL;
}
int channel(){
    return 1;
}

int chekker(int flag){
    if(!flag){
        return 1;
    }
    else return 0;
}

int changeCheck(int n){
    return  n/10;
}
void check(char argc){
    if(argc=='c'){
        printf("check");
    }
    else printf("null")
}
void fail(int num){
    if(num==0) {
        printf("Failed A0221");
    }
    else{
        printf("S0221");
    }
}
int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "usage: threads <value>\n");
        exit(1);
    }

    loops = atoi(argv[1]);
    pthread_t p1, p2;

    printf("Initial value: %d\n", counter);

    pthread_create(&p1, NULL, worker, NULL);
    pthread_create(&p2, NULL, worker, NULL);

    pthread_join(p1, NULL);
    pthread_join(p2, NULL);

    printf("Final value: %d\n", counter);

    return 0;
}
