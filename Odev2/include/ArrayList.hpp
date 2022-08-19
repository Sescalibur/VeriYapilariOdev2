/**
        * @file  ArrayList.hpp  
		* @description ArrayListin baslik dosyasi.  
		* @course  1/A 
		* @assignment  1   
		* @date  31.07.2022  
		* @author  Samet Emin Sevil   
*/
#ifndef ARRAYLIST_HPP
#define ARRAYLIST_HPP

#include <iostream>
#include <fstream>
#include <sstream>
using namespace std;


class ArrayList{
	private:
		int *items;
		int count;
		int capacity;
		void reserve(int newCapacity);
	public:
		ArrayList();
		int size()const;
		bool isEmpty()const;
		int elemanAt(int index);
		void insert(int index , int item);
		void add(int item);
		void removeAt(int index);
		void clear();
		void tersCevir();
		void ustuneYaz(int index, int item);
		~ArrayList();
		
};






#endif