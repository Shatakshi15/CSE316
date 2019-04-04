#include <pthread.h> 
#include <semaphore.h> 
#include <stdio.h> 
#include<sys/types.h>
#include<stdlib.h>
#include<unistd.h>
void *fun1(void *receive);
void *fun2(void *receive);
void *fun3(void *receive);
pthread_mutex_t l;
int shared=1;
struct resource
{
	int pen;
	int paper;
	int q_paper;
};
int turn=0;
int main()
{
pthread_mutex_init(&l, NULL); //initializing mutex locks
pthread_t student1, student2,student3;
struct resource send;
while(1)
{
   	if(turn==0)
	{
		send.paper=1;
		send.q_paper=1;
		turn++;
	}
		if(turn==1)
	{
		send.pen=1;
		send.q_paper=1;
		turn++;
	}
		if(turn==2)
	{
		send.paper=1;
		send.pen=1;
		turn=0;
	}
pthread_create(&student1, NULL, fun1, &send);
pthread_create(&student2, NULL, fun2, &send);
pthread_create(&student3, NULL, fun3, &send);
pthread_join(student1, NULL);
pthread_join(student2,NULL);
pthread_join(student3,NULL);
}
}
void *fun1(void *receive)
{
    int x;
    int pen=1;
    //struct resource *check=receive;
   // if(receive->paper==1)&&(receive->q_paper==1)
   // {
    pthread_mutex_lock(&l);
    x=shared;
    x++;  
    sleep(2); 
    shared=x; 
    pthread_mutex_unlock(&l);
    printf("student 1 completed work\n");
  //}
}
void *fun2(void *receive)
{
    int x;
    int paper =2;
    pthread_mutex_lock(&l);
    x=shared;
    x++;  
    sleep(2); 
    shared=x; 
    pthread_mutex_unlock(&l);
     printf("student 2 completed work\n");
}
void *fun3(void *receive)
{
    int x;
    int q_paper=3;
    pthread_mutex_lock(&l);
    x=shared;
    x++;  
    sleep(2); 
    shared=x; 
    pthread_mutex_unlock(&l);
     printf("student 3 completed work\n");
}
