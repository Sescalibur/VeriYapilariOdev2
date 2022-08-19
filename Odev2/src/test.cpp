#include "ArrayList.hpp"
#include "Node.hpp"
#include "Ekle.hpp"
int main(){
	Ekle *ekle = new Ekle();
	BST *bst =  new BST();
	ekle->DosyaOkuveEkle(bst);
	return 0;
}