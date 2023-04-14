#ifndef AVL_H
#define AVL_H
#include"AVLNode.h"
template<typename T>
class AVL
{
public:
	AVLNode<T>* root;
	int calculteBalanceFactor(AVLNode<T>* start);
	AVL();
	void setRoot(T inf);
	void LVRDecending(AVLNode<T>* start);
	void insert(T num);
	int maxHeight(AVLNode<T>* node1, AVLNode<T>* node2);
	string getRoation(AVLNode<T>*, int balanceFactor);
	void deleteNodes(T data);
	void LL(AVLNode<T>* pivot, MyStack<AVLNode<T>*> & myStack);
	void RR(AVLNode<T>* pivot, MyStack<AVLNode<T>*>& myStack);
	void LR(AVLNode<T>* pivot, MyStack<AVLNode<T>*>& myStack);
	void RL(AVLNode<T>* pivot, MyStack<AVLNode<T>*>& myStack);
};
#endif;
 