#ifndef AVLNODE_H
#define AVLNode_H
#include"MyStack.h"
#include<string>
template<typename T>
class AVLNode
{
public:
	T info;
	int height;
	AVLNode<T>* left;
	AVLNode<T>* right;
	AVLNode();
	AVLNode(T inf);
};
#endif;

