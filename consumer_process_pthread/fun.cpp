#include"cp.h"
extern int buffer;
extern const int MAX;
extern pthread_mutex_t my_mutex;
extern pthread_cond_t condc, condp;
void* producer(void*ptr){
    int i;
    for(i=0;i<=MAX;i++){
        pthread_mutex_lock(&my_mutex);
        while(buffer!=0) pthread_cond_wait(&condp,&my_mutex);
        buffer=i;
        cout<<"produce:"<<i<<endl;
        pthread_cond_signal(&condc);
        pthread_mutex_unlock(&my_mutex);
    }
    pthread_exit(0);
}

void* consumer(void*ptr){
    int i;
    for(i=1;i<=MAX;i++){
        pthread_mutex_lock(&my_mutex);
        while(buffer==0) pthread_cond_wait(&condc, &my_mutex);
        buffer=0;
        cout<<"con:"<<i<<endl;
        pthread_cond_signal(&condp);
        pthread_mutex_unlock(&my_mutex);    

    }
    pthread_exit(0);
}
