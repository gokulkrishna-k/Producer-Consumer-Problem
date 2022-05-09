#include<thread>
#include<chrono>
#include<iostream>
using namespace std;


int buffer = 0;

bool isProduced = false;

void Producer(){
  while(1){
    if(!isProduced){
      cout << "\nProd -> Current Buffer : " << buffer << endl;
      buffer = 30;
      cout << "\nFilling buffer : " << buffer << endl;
      isProduced = true;
    }
    else {
      cout << "\nProducer waiting for Consumer to consumer...\n";
      std::this_thread::sleep_for (std::chrono::milliseconds(500));
    }
  }
}

void Consumer(){
  while(1){
    if(isProduced){

      cout << "\nCons -> Current Buffer : " << buffer << endl;
      buffer = 0;
      cout << "\nEmptying buffer : " << buffer;
      isProduced = false;
    }
    else {
      cout << "\nConsumer waiting for Producer to produce...\n";
      std::this_thread::sleep_for (std::chrono::milliseconds(2000));
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