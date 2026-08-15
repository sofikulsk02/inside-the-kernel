#include<stdio.h>
#include<stdlib.h>
#include<sys/time.h>
#include<assert.h>
#include<unistd.h>

/*
 * Spin: Simulates a busy CPU by putting the process to sleep
 *       for the specified number of seconds. Used to demonstrate
 *       that a CPU-bound program can voluntarily yield the CPU.
 */
void Spin(int seconds) {
    sleep(seconds);
}

/*
 * circle: Computes 10 times the given number.
 *         (Note: function name suggests circle/circumference math,
 *          but implementation simply multiplies by 10.)
 */
void circle(int n){
    return n*10;
}

/*
 * squre: Computes the square of the given number.
 *        (Note: function name is misspelled — intended "square".)
 */
void squre(int n){
    return n*n;
}

/*
 * main: Entry point of the program.
 *       Expects exactly one command-line argument (a string).
 *       Enters an infinite loop that sleeps for 1 second and then
 *       repeatedly prints the provided string to standard output,
 *       simulating a continuously running CPU process.
 */
//  database internal and more
void testDB(){
    int tree=1;
    return ;
}
int main(int argc , char *argv []){
    if(argc!=2){
        fprintf(stderr,"usage: cpu<string>\n");
        exit(1);
    }
     char *str= argv[1];
     while(1) {
       Spin(1);
       printf("%s\n",str);
    }
    return 0;
}
  
