#include<stdio.h>
#include<signal.h>
#include<unistd.h>
#include<sys/wait.h>

int ready = 0;

void childReady(int sig){
    ready = 1;
}

int main(){

    pid_t pid;
    pid = fork();
    if(pid == 0){
        printf("Child is working.\n");
        sleep(2);
        //kill(getppid(), SIGKILL);
        sleep(2);
        printf("Child is ready!\n");
        kill(getppid(), SIGUSR1);
    }else{
        printf("Parent is waiting for child!\n");
        signal(SIGUSR1, childReady);
        pause();
        if(ready == 1){
            printf("My child is ready!\n");
        }else{
            printf("I got the wrong signal!\n");
            return 1;
        }
        sleep(2);
        printf("Parent is ready!\n");
    }
    return 0;
}