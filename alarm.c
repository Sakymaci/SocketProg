#include<stdio.h>
#include<stdlib.h>
#include<signal.h>
#include<unistd.h>

void terminate(int sig){
    printf("Timed out!\n");
    kill(getpid(), SIGKILL);
}


int main(){
    int x;
    signal(SIGALRM, terminate);
    alarm(2);
    printf("Write a number!\n");
    scanf("%d", &x);
    printf("%d remained\n", alarm(0));
    sleep(3);
    printf("The number is: %d", x);
    return 0;
}