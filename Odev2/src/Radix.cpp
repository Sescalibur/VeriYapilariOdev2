#include "Radix.hpp"

int Radix::MaxStepNumber(){
	int max=0;
	for(int i=0;i<length;i++){
		if(StepCount(numbers->elemanAt(i))>max) max = StepCount(numbers->elemanAt(i));
	}
	return max;
}

int Radix::StepCount(int number){
	number = abs(number);
	int basamak=0;
	while(number>0){
		basamak++;
		number /= 10;
	}
	return basamak;
}

Radix::Radix (ArrayList *numbers){
	this->numbers = new ArrayList();
	this->length = numbers->size();
	for(int i=0;i<length;i++){ this->numbers->add(numbers->elemanAt(i));}
	queues = new Queue*[10];
	for(int j=0;j<10;j++){ queues[j] = new Queue(); }
	maxStep = MaxStepNumber();
}
ArrayList* Radix::Sort(){
	int numberIndex=0;
	// read from array once and add to queues
	for(;numberIndex<length;numberIndex++){
		int stepValue = numbers->elemanAt(numberIndex)%10;
		int num = numbers->elemanAt(numberIndex);
		queues[stepValue]->enqueue(num);
	}
		
	//i starting from 1 because of first digit processed
	for(int i=1;i<maxStep;i++){
		for(int index=0;index<10;index++){
			int len=queues[index]->count();
			for(;len>0;len--){
				int number = queues[index]->peek();
				queues[index]->dequeue();
				int stepValue = (number/(int)pow(10,i))%10;	
				queues[stepValue]->enqueue(number);
				
			}
		}
	}
	ArrayList* ordered = new ArrayList();
	numberIndex=0;
	for(int index=0;index<10;index++){
		while(!queues[index]->isEmpty()){
			int number = queues[index]->peek();
			ordered->add(number);
			queues[index]->dequeue();
		}
	}		
	return ordered;
}

Radix::~Radix(){	
	delete numbers;
	for(int i=0;i<10;i++) delete queues[i];
	delete [] queues;
}
