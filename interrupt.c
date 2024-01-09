#include<stdio.h>
#include<signal.h>
#include<unistd.h>

void kiiras(int sig){
    printf("\n Elkaptam a jelet!\n");
    signal(SIGINT, SIG_DFL);
}

int main(){

    signal(SIGINT, kiiras);
    for(int i = 0; i < 100; i++){
        sleep(1);
        printf("Ima sleep: %d\n", i);
    }
    return 0;
}