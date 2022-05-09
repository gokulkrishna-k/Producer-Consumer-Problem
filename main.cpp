#include <bits/stdc++.h>
#include <semaphore.h>
#include <unistd.h>
#include <thread>
using namespace std;

int items = 0;

sem_t notEmpty, notFull;

void* Producer() {
	while (1) {
		sem_wait(&notFull);
		sleep(0.2);
		cout << "Producer produces item.Items Present = " << ++items << endl;
		sem_post(&notEmpty);
		sleep(0.5);
	}
}

void* Consumer() {
	while (1) {
		sem_wait(&notEmpty);
		sleep(0.9);
		cout << "Consumer consumes item.Items Present = " << --items << endl;
		sem_post(&notFull);
		sleep(1);
	}
}

int main() {
    sem_init(&notEmpty, 0, 0);
    sem_init(&notFull, 0, 1);


    thread producer_thread(Producer);
    thread consumer_thread(Consumer);

    producer_thread.join();
    consumer_thread.join();
	return 0;
}
