#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>

int main(){

    int x = 0;
    pid_t pid;
    printf("Start: %d\n", x);
    pid = fork();
    if (pid == 0){
        x = 1;
        printf("PID: %d, PPID: %d\n", getpid(), getppid());
        printf("Child: %d\n", x);
        return 0;
    }else{
        x = 2;
        sleep(4);
        printf("PID: %d\n", getpid());
        printf("Parent: %d\n", x);
        return 0;
    }
    return 0;
}