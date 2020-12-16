#include"mypth.h"
#include<pthread.h>
int main(int argc, char* argv[]){
    pthread_t threads[NUMBER_OF_THREADS];
    int status;
    int i;
    for(i=0;i!=NUMBER_OF_THREADS;i++){
        cout<<"creat threads:"<<i<<endl;
        status=pthread_create(&threads[i], NULL,print_hello,&i);
        if(status!=0) exit(-1);
    }
    exit(0);
}