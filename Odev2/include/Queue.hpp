#ifndef QUEUE_HPP
#define QUEUE_HPP
#include <iostream>
using namespace std;

class Queue{
	private:
		int front;
		int back;
		int capacity;
		int length;
		int *items;
		
		void reserve(int newCapacity);
	public:
		Queue();
		void clear();
		int count() const;
		bool isEmpty() const;
		/// Kuyrukta en öndeki elemanı getirir
		int peek();
		void enqueue(int item);
		void dequeue();
		~Queue();
};
#endif
