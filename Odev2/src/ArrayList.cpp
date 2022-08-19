#include "ArrayList.hpp"

ArrayList::ArrayList(){
	capacity =100;
	count=0;
	items= new int[capacity];
}
int ArrayList::size()const{
	return count;
}
bool ArrayList::isEmpty()const{
	return count==0;
}
int ArrayList::elemanAt(int index){
	if(index<0||index>=count) throw "Index out of range ";
	return items[index];
}
void ArrayList::insert(int index , int item){
	if(index<0||index>count) throw "Index out of range ";
	if(count == capacity) reserve(2*capacity);
	for(int i = count -1 ; i>=index;i--) items[i+1]=items[i];
	items[index]=item;
	count++;
}
void ArrayList::add(int item){
	insert(count,item);
}
void ArrayList::removeAt(int index){
	if(index<0||index>=count) throw "Index out of range ";
	for(int i = index+1 ; i < count;i++){
		items[i-1]=items[i];
	}
	count--;
}
void ArrayList::clear(){
	count = 0;
}
void ArrayList::tersCevir(){
	int tut;
			
	for (int i = 0; i < count / 2; i++) {
		tut = items[i];
		items[i] = items[count - i - 1];
		items[count - i - 1] = tut;
	}
}
void ArrayList::ustuneYaz(int index, int item){
	if(index<0||index>count) throw "Index out of range ";
	items[index]=item;
}
ArrayList::~ArrayList(){
	delete [] items;
}
void ArrayList::reserve(int newCapacity){
	int *newItem = new int[newCapacity];
	for(int i = 0 ; i<count; i++) newItem[i]=items[i];
	delete [] items;
	items = newItem;
	capacity = newCapacity;
}

		
		
		
		
		
		
		
		