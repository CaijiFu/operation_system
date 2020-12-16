#include"cp.h"
int buffer=0;
const int MAX = 100000;
pthread_mutex_t my_mutex;
pthread_cond_t condc, condp;

int main(int argc, char* argv[]){
    pthread_t pro,con;
    //initialization
    pthread_mutex_init(&my_mutex,0);
    pthread_cond_init(&condc,0);
    pthread_cond_init(&condp,0);
    //create phread
    pthread_create(&pro, NULL, producer,0);
    pthread_create(&con, NULL, consumer,0);
    //wait
    pthread_join(pro,0);
    pthread_join(con,0);
    //dstory
    pthread_cond_destroy(&condc);
    pthread_cond_destroy(&condp);
    pthread_mutex_destroy(&my_mutex);
    exit(0);
}
