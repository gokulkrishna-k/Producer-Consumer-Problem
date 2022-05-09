#include <bits/stdc++.h>
#include <unistd.h>
#include <thread>
#include <mutex>
#include <condition_variable>

using namespace std;

mutex mtx;

int buffer;

bool data = false;


void* Producer() {
	while (1) {
		if(!data){
			std::unique_lock<std::mutex> lck(mtx);
			sleep(1);
			buffer = rand() % 10;
			cout << "Producer -> " << buffer << endl;
			data = true;
			
		}
	}
}

void* Consumer() {

	while (1) {
		if(data){
			std::unique_lock<std::mutex> lck(mtx);
			sleep(1);
			cout << "Consumer -> " << buffer << endl;
			data = false;
		}
	}
}

int main() {

    thread producer_thread(Producer);
    thread consumer_thread(Consumer);

    producer_thread.join();
    consumer_thread.join();

	return 0;
}
