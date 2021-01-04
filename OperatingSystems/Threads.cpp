#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>
using namespace std;

#define size 10

int i = 0, count = 10;
int buffer[size];
sem_t full, empty;
pthread_mutex_t m;

void *produce(void *arg) {
	while (true) {
		sleep(1);
		sem_wait(&empty);
		pthread_mutex_lock(&m);
		buffer[i] = count++;
		printf("\n\t Produced Item : %d", buffer[i++]);
		pthread_mutex_unlock(&m);
		sem_post(&full);
	}
}

void *consume(void *arg) {
	while (true) {
		sleep(1);
		sem_wait(&full);
		pthread_mutex_lock(&m);
		buffer[i] = 0;
		printf("\n\t Consumed Item : %d", buffer[--i]);
		pthread_mutex_unlock(&m);
		sem_post(&empty);
	}
}

int main() {
	pthread_t producer, consumer;
	sem_init(&empty, 0, size);
	sem_init(&full, 0, 0);
	pthread_mutex_init(&m, NULL);
	pthread_create(&producer, NULL, produce, NULL);
	pthread_create(&consumer, NULL, consume, NULL);
	pthread_exit(NULL);
}
