#include "AVLNode.h"
template<typename T>
AVLNode<T>::AVLNode():info()
{
	height = 0;
	left = nullptr;
	right = nullptr;
}
template<typename T>
AVLNode<T>::AVLNode(T inf):AVLNode()
{
	info = inf;
	height = 1;
}



