 #include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include "common.h"

int  main(int argc,char *argv[]){
int *p= malloc(sizeof(int)); //a1
 assert(p!= NULL);
 printf("(%d) successfully allocated int on the heap\n", getpid());
 printf("(%d) sizeof(int) = %lu byte(s)\n", getpid(), (unsigned long)sizeof(int));
 printf("(%d) argc = %d\n", getpid(), argc);
 if (argc > 1) {
     printf("(%d) argv[1] = \"%s\"\n", getpid(), argv[1]);
 }
 printf("(%d)memoryaddress of p:%08x\n",
getpid(), (unsigned)p); //a2
*p = 0; //a3 
while(1) {
 Spin(1);
 *p= *p + 1;
printf("(%d)p:%d\n", getpid(), *p); //a4
}
   return 0;
 }
