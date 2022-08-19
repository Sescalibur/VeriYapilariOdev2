#ifndef NODE_HPP
#define NODE_HPP
#include <iostream>
#include <cmath>
#include "ArrayList.hpp"
using namespace std;
struct Node{
    int data, size, height;
    ArrayList* array;
    Node* left;
    Node* right;
    Node(const int& = 0, const int& = 0, ArrayList* = 0, Node* = 0, Node* = 0);
	int setData(ArrayList *array);
    ~Node();
    void printScreen();
};
class BST{
	private:
		Node* root;
		void searchAndAdd(Node *& subNode,int data,ArrayList *array);
		bool searchAndDelete(Node *& subNode,int data);
		bool deleteNode(Node *&subNode);
		int heightIc(Node *subNode);
		void inorder(Node* subNode);
		void preorder(Node* subNode);
	public:
		BST();
		bool isEmpty()const;
		void Add(int data,ArrayList *array);
		void Delete(int data);
		int height();
		void Clear();
		void inorder();
		void preorder();

		~BST();
		
};

#endif