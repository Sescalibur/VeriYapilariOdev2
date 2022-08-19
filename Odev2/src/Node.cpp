#include "Node.hpp"

Node::Node(const int& data,const int& size,ArrayList* array, Node* left, Node* right){
    this->data = data;
    this->size = size;
    this->array = array;
    this->left = left;
    this->right = right;
    this->height = 0;
}

Node::~Node(){
    if(this->array != NULL){
        delete [] this->array;
    }
}

void Node::printScreen(){
    // for(int i=0; i<this->size; i++){
        // cout << this->array[i] << " ";
    // }
}

BST::BST(){
	root=NULL;
}
bool BST::isEmpty()const{
	return root==NULL;
}
void BST::Add(int data,ArrayList *array){
	searchAndAdd(root,data,array);
}
void BST::searchAndAdd(Node *& subNode,int data,ArrayList* array){
	if(subNode==NULL) subNode = new Node(data,0,array); 
	else if(data< subNode->data) searchAndAdd(subNode->left,data,array);
	else if(data > subNode->data) searchAndAdd(subNode->right,data,array);
	else return;
}
bool BST::searchAndDelete(Node *& subNode,int data){
	if(subNode==NULL) return false;
	if(subNode->data == data) return deleteNode(subNode);
	else if(data< subNode->data) return searchAndDelete(subNode->left,data);
	else return searchAndDelete(subNode->right,data);
}
bool BST::deleteNode(Node *&subNode){
	Node *delNode = subNode;
	if(subNode->right == NULL) subNode = subNode->left;
	else if(subNode->left == NULL) subNode=subNode->right;
	else{
		delNode = subNode->left;
		Node* parent = subNode;
		while(delNode->right!=NULL){
			parent = delNode;
			delNode = delNode->right;
		}
		subNode->data = delNode->data;
		if(parent == subNode) subNode->left = delNode->left;
		else parent->right =delNode->left;
	}
	delete delNode;
	return true;
}
void BST::Delete(int data){
	if(searchAndDelete(root,data)==false) throw "Item not found";
}
int BST::heightIc(Node *subNode){
	if(subNode==NULL) return-1;
	return 1+max(heightIc(subNode->left),heightIc(subNode->right));
}

int BST::height(){
	return heightIc(root);
}

void BST::Clear(){
	while(!isEmpty()) deleteNode(root);
}

void BST::inorder(){
	inorder(root);
}

void BST::inorder(Node* subNode){
	if(subNode != NULL){
		inorder(subNode->left);
		cout<<subNode->data<<" " ;
		inorder (subNode->right);
	}
} 
void BST::preorder(){
	preorder(root);
}

void BST::preorder(Node* subNode){
	if(subNode != NULL){
		cout<<subNode->data<<" " ;
		preorder(subNode->left);
		preorder (subNode->right);
	}
} 

int Node::setData(ArrayList *array){
	int toplam;
	for(int i = 0 ; i < array->size();i++){
		toplam += array->elemanAt(i);
	}
	return data=toplam;
}

BST::~BST(){
	Clear();
}




