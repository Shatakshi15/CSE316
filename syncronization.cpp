#include <pthread.h> 
#include <semaphore.h> 
#include <stdio.h> 
#include<sys/types.h>
#include<stdlib.h>
#include<unistd.h>
int main()
{
   int student1;
   student1 =fork();
   if(student1==0)
   {
   	printf("Student1");
   }
   else
   {
   	pid_t student2=fork();
   	if(student2==0)
   	{
   		printf("Student2");
	   }
	   else
	   {
	   		pid_t student3=fork();
   	if(student3==0)
   	{
   		printf("Student3");
	   }
	   else
	   {
	   	printf("Teacher");
	   }
	   }
   }
}
