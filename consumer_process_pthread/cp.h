#ifndef CP_H
#define CP_H
#include<iostream>
#include<pthread.h>
using namespace std;

extern int buffer;
extern const int MAX;
extern pthread_mutex_t my_mutex;
extern pthread_cond_t condc, condp;

void* producer(void*ptr);
void* consumer(void*ptr);
#endif
