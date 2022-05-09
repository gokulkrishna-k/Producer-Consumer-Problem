#include <bits/stdc++.h>
#include <unistd.h>
#include <thread>
#include <mutex>

using namespace std;

mutex mtx;

int items = 0;

void* Producer() {
	while (1) {
		mtx.lock();
		cout << "Producer produces item.Items Present = " << ++items << endl;
		mtx.unlock();
	}
}

void* Consumer() {

	while (1) {
		mtx.lock();
		cout << "Consumer consumes item.Items Present = " << --items << endl;
		mtx.unlock();
	}
}

int main() {

    thread producer_thread(Producer);
    thread consumer_thread(Consumer);

    producer_thread.join();
    consumer_thread.join();

	return 0;
}
