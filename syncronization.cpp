#include <pthread.h> 
#include <semaphore.h> 
#include <stdio.h> 
#include<sys/types.h>
#include<stdlib.h>
#include<unistd.h>
void *fun1(void *receive);
void *fun2(void *receive);
void *fun3(void *receive);
int main()
{
pthread_mutex_init(&l, NULL); //initializing mutex locks
pthread_t student1, student2,student3;
while(1)
{

pthread_create(&student1, NULL, fun1, NULL);
pthread_create(&student2, NULL, fun2, NULL);
pthread_create(&student3, NULL, fun3, NULL);
pthread_join(student1, NULL);
pthread_join(student2,NULL);
pthread_join(student3,NULL);
}
}
void *fun1(void *receive)
{
    int x;
    pthread_mutex_lock(&l);
    x=shared;
    x++;  
    sleep(1); 
    shared=x; 
    pthread_mutex_unlock(&l);
}
void *fun2(void *receive)
{
    int x;
    pthread_mutex_lock(&l);
    x=shared;
    x++;  
    sleep(1); 
    shared=x; 
    pthread_mutex_unlock(&l);
}
void *fun3(void *receive)
{
    int x;
    pthread_mutex_lock(&l);
    x=shared;
    x++;  
    sleep(1); 
    shared=x; 
    pthread_mutex_unlock(&l);
}
