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
while(turn<3)
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
		turn++;
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
    struct resource *check=(struct resource *)receive;
   if((check->paper==1)&&(check->q_paper==1))
    {
    pthread_mutex_lock(&l);
    x=shared;
    x++; 
    printf("Teacher has given paper and question paper and I have pen\n");
    sleep(5); 
    shared=x; 
     printf("student 1 completed assignment\n");
    pthread_mutex_unlock(&l);
   
  }
}
void *fun2(void *receive)
{
    int x;
    int paper =2;
    pthread_mutex_lock(&l);
    x=shared;
    x++;  
    printf("Teacher has given pen and question paper and I have paper\n");
    sleep(5); 
    shared=x; 
    printf("student 2 completed assignment\n");
    pthread_mutex_unlock(&l);
     
}
void *fun3(void *receive)
{
    int x;
    int q_paper=3;
    pthread_mutex_lock(&l);
    x=shared;
    x++;  
     printf("Teacher has given pen and paper and I have question paper\n");
    sleep(5); 
    shared=x; 
     printf("student 3 completed assignment\n");
    pthread_mutex_unlock(&l);
    
}
