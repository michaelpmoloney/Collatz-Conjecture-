/*Student: Michael Moloney
Class: CSC 4320 MW 2:30-5:30pm
Instructor:Zhisheng Yan
Assignment:Homework 1
Due Date: 2/8/2019*/
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>

//Main Method
int main(int argc, char *argv[])
{
//Declare variable for input argument
	int n;
//Check that input argument was entered
	if (argc == 1) {
		fprintf(stderr,"Usage: ./hw1 <starting value>\n");		
		return -1;
	}
//assign imput argument to variable n
	n = atoi(argv[1]);
//check that n is a positive integer
	if (n<1) {
		fprintf(stderr,"Input must be a positive integer.\n");
		return -1;
	}
//declare process IDs
	pid_t pid, pid1;
//fork a child process
	pid=fork();
//check for fork error
	if (pid<0) {
	fprintf(stderr, "Fork Failed\n");
	return 1;
}
//child process
	else if (pid==0){
//Collatz algorithm with outputs printed
printf("%d, ",n);
while (n>1){
	if (n%2==0){
		n=n/2;
		printf("%d, ",n);
	}
	else{
		n=n*3+1;
		printf("%d, ",n);
	}
}
printf("\n");
//print out returned integer value(should be 0)
//and process ID of child process
pid1=getpid();
		printf("child: pid=%d\n",pid);
		printf("child: pid1=%d\n",pid1);
}
//parent process
	else{
//get process ID of parent
pid1=getpid();
//wait for child process to finish
wait(NULL);
//print child PID, then parent PID
		printf("parent: pid=%d\n",pid);
		printf("parent: pid1=%d\n",pid1);
}
//exit main method
return 0;
}
