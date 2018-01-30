/* Author: Michael O'Connell
   Date: 2017-10-12
 */
#include <stdio.h>
#include <pthread.h>
#include <unistd.h>
#include <string.h>
#include <time.h>

int timeout = 1;
int seconds = 0;

void *timer();

/* Thread function that is called by the worker thread. 
   Prints out the thread number and the counter variable with spacing to make it more clear. */
void *printNumbers(void *arg) {
	int threadNum = *(int*)arg;
	int count = 0;
	char printSpace[64];

	/* Adds printSpace to go between each thread depending on which thread is running */
	for (int i = 1; i < threadNum; ++i) {
		strcat(printSpace, "\t\t");
	}										
	
	while (timeout == 1) {
		printf("%sthread %d: %d\n", printSpace, threadNum, ++count);
	}

	return NULL;
}

/* Main function. Reads input from the user to determine the number of threads and how many
   seconds the program should run for */
int main(void) {
	int threads = 0;
	pthread_t workerThread, timerThread;
	
	while (printf("Enter number of threads (limit 6): ") && scanf("%d", &threads) && threads > 6);
	
	printf("Enter number of seconds: "); 
	scanf("%d", &seconds);

	/* Create timer thread */
	pthread_create(&timerThread, NULL, timer, NULL);

	/* Create X number of worker threads */
	for (int i = 0; i < threads; i++) {
		pthread_create(&workerThread, NULL, printNumbers, &i);
	}

	/* Wait for the thread to finish before continuing */
	pthread_join(timerThread, NULL);

	time_t rawtime;
	struct tm * timeinfo;
	time (&rawtime);
	timeinfo = localtime (&rawtime);
	printf("Finish time: %s", asctime (timeinfo));
	return 0;
}

/* Timer function that is called by the timer thread. Sleeps for the number of seconds
   inputted by the user and then sets the timeout boolean to true */
void *timer() {
	sleep(seconds);
	timeout = 0;
	return NULL;
}