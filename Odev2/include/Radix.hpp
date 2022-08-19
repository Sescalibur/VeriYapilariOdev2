#ifndef RADIX_HPP
#define RADIX_HPP

#include "ArrayList.hpp"
#include "Queue.hpp"
#include <cmath>

class Radix{
	private:	
		ArrayList* numbers;
		int length;
		Queue **queues;
		int maxStep;
		
		int MaxStepNumber();
		int StepCount(int);
	public:
		Radix(ArrayList* );
		ArrayList* Sort();
		~Radix();
};

#endif
