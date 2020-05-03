
#include <stdio.h>
#include <unistd.h>
#include <signal.h>

void check_term(){
    printf("got SIGTERM, doing nothing :P\n");
}
void main(){
    signal(SIGTERM , check_term);

    while(1){
        
    }
}
