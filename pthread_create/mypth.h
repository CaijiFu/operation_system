#include<iostream>
#include"pthread.h"
using namespace std;
const int NUMBER_OF_THREADS=5;
void* print_hello(void* i){
    cout<<"hello word greeting from thread"<<i<<endl;
    pthread_exit(NULL);
}
