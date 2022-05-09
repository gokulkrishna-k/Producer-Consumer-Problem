#include<thread>
#include<chrono>
#include<iostream>
#include <semaphore.h>  
using namespace std;

sem_t notEmpty, notFull;


int buffer = 0;


void Producer(){
  while(1){
      sem_post(&notFull);
      std::this_thread::sleep_for (std::chrono::milliseconds(200));
      buffer = 10;
      cout << "\nProd -> Current Item Produced : " << buffer << endl;
      sem_post(&notEmpty);
      std::this_thread::sleep_for (std::chrono::milliseconds(500));
  }
}

void Consumer(){
  while(1){
      sem_post(&notEmpty);
      std::this_thread::sleep_for (std::chrono::milliseconds(1200));
      cout << "\nCons -> Current Item Consumed : " << buffer << endl;
      buffer = 0;
      sem_post(&notFull);
      std::this_thread::sleep_for (std::chrono::milliseconds(500));
  }
}


int main() {
  
  sem_init(&notEmpty, 0, 0);
  sem_init(&notFull, 0, 5);

  thread producer_thread(Producer);
  thread consumer_thread(Consumer);

  producer_thread.join();
  consumer_thread.join();

  return 0;
}