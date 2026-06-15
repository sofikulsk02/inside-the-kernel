 #include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include "common.h"
int hasToOdd(int num){
  if(num%2==1){
          return true;
  }
  return false;
}
int validation(int num){
  if(num%2==1){
          return 1;
  }
  return 0;
}
int validation(char ch){
  if(ch=='a') return 1;
  else return 0;
}

int  main(int argc,char *argv[])
{
int *p= malloc(sizeof(int)); //a1
 assert(p!= NULL);
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
