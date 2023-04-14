#include "AVL.h"
template<typename T>
AVL<T>::AVL()
{
	root = nullptr;
}
template<typename T>
void AVL<T>::setRoot(T inf)
{
	root = new AVLNode<T>(inf);
}
template<typename T>
void AVL<T>::LVRDecending(AVLNode<T>* start)
{
	if (start->left)
	{
		LVRDecending(start->left);
	}
	cout << start->info<<" ";
	if (start->right)
	{
		LVRDecending(start->right);
	}
}
template<typename T>
int AVL<T>::maxHeight(AVLNode<T>* node1, AVLNode<T>* node2)
{
	int h1 = 0;
	int h2 = 0;
	if (node1 != nullptr)
	{
		h1 = node1->height;
	}
	if (node2 != nullptr)
	{
		h2 = node2->height;
	}
	if (h1 > h2)
	{
		return h1;
	}
	return h2;
}
template<typename T>
string AVL<T>::getRoation(AVLNode<T>* pivot,int balanceFactor)
{
	string rotation;
	if (balanceFactor > 0)
	{
		rotation += 'L';
		if (calculteBalanceFactor(pivot->left) > 0)
		{
			rotation += 'L';
		}
		else
		{
			rotation += 'R';
		}
	}
	else
	{
		rotation += 'R';
		if (calculteBalanceFactor(pivot->right) < 0)
		{
			rotation += 'R';
		}
		else
		{
			rotation += 'L';
		}
	}
	return rotation;
}
template<typename T>
void AVL<T>::LL(AVLNode<T>* pivot, MyStack<AVLNode<T>*>&myStack)
{
	AVLNode<T>* LP = pivot->left;
	AVLNode<T>* RLP = LP->right;
	LP->right = pivot;
	pivot->left = RLP;
	AVLNode<T>* PP = nullptr;
	pivot->height = maxHeight(pivot->left, pivot->right) + 1;
	LP->height = maxHeight(LP->left, LP->right) + 1;
	if (pivot != root)
	{
		PP = myStack.pop();
		if (PP->left == pivot)
		{
			PP->left = LP;
		}
		else
			PP->right = LP;
		PP->height = maxHeight(PP->left, PP->right) + 1;
		myStack.push(PP);
	}
	else
	{
		root = LP;
		root->height = maxHeight(root->left, root->right) + 1;
	}
}
template<typename T>
void AVL<T>::RR(AVLNode<T>* pivot, MyStack<AVLNode<T>*>& myStack)
{
	AVLNode<T>* RP = pivot->right;
	AVLNode<T>* LRP = RP->left;
	RP->left = pivot;
	pivot->right = LRP;
	AVLNode<T>* PP = nullptr;
	pivot->height = maxHeight(pivot->left, pivot->right) + 1;
	RP->height = maxHeight(RP->left, RP->right) + 1;
	if (pivot != root)
	{
		PP = myStack.pop();
		if (PP->left == pivot)
		{
			PP->left = RP;
		}
		else
			PP->right = RP;
		PP->height = maxHeight(PP->left, PP->right) + 1;
		myStack.push(PP);
	}
	else
	{
		root = RP;
		root->height = maxHeight(root->left, root->right) + 1;
	}
}
template<typename T>
void AVL<T>::LR(AVLNode<T>* pivot, MyStack<AVLNode<T>*>& myStack)
{
	AVLNode<T>* LP = pivot->left;
	AVLNode<T>* RLP = LP->right;
	AVLNode<T>* LRLP = RLP->left;
	AVLNode<T>* RRLP = RLP->right;
	RLP->left = LP;
	RLP->right = pivot;
	LP->right = LRLP;
	pivot->left = RRLP;
	LP->height = maxHeight(LP->left, LP->right) + 1;
	pivot->height = maxHeight(pivot->left, pivot->right) + 1;
	RLP->height = maxHeight(RLP->left, RLP->right) + 1;
	AVLNode<T>* PP = nullptr;
	if (pivot != root)
	{
		PP = myStack.pop();
		if (PP->left == pivot)
		{
			PP->left = RLP;
		}
		else
		{
			PP->right = RLP;
		}
		PP->height = maxHeight(PP->left, PP->right) + 1;
		myStack.push(PP);
	}
	else
	{
		root = RLP;
		root->height = maxHeight(root->left, root->right) + 1;
	}
}
template<typename T>
void AVL<T>::RL(AVLNode<T>* pivot, MyStack<AVLNode<T>*>& myStack)
{
	AVLNode<T>* RP = pivot->right;
	AVLNode<T>* LRP = RP->left;
	AVLNode<T>* LLRP = LRP->left;
	AVLNode<T>* RLRP = LRP->right;
	LRP->left = pivot;
	LRP->right = RP;
	pivot->right = LLRP;
	RP->left = RLRP;
	RP->height = maxHeight(RP->left, RP->right) + 1;
	pivot->height = maxHeight(pivot->left, pivot->right) + 1;
	LRP->height = maxHeight(LRP->left, LRP->right) + 1;
	AVLNode<T>* PP = nullptr;
	if (pivot != root)
	{
		PP = myStack.pop();
		if (PP->left == pivot)
		{
			PP->left = LRP;
		}
		else
		{
			PP->right = LRP;
		}
		PP->height = maxHeight(PP->left, PP->right) + 1;
		myStack.push(PP);
	}
	else
	{
		root = LRP;
		root->height = maxHeight(root->left, root->right) + 1;
	}
}
template<typename T>
void AVL<T>::insert(T num)
{
	MyStack<AVLNode<int>*> myStack;
	AVLNode<T>* temp =root;
	AVLNode<T>* prev = root;
	while (temp != nullptr)
	{
		if (num < temp->info)
		{
			myStack.push(temp);
			prev = temp;
			temp = temp->left;
			continue;
		}
		if (num >= temp->info)
		{
			if (temp->info == num)
			{
				return;
			}
			myStack.push(temp);
			prev = temp;
			temp = temp->right;
		}
	}
	bool incHeight = false;
	if (prev == nullptr)
	{
		cout << "Previous is Null";
	}
	if (prev&&num>=prev->info)
	{
		prev->right = new AVLNode<T>(num);
		if(prev->left == nullptr)
		incHeight = true;
	}
	else if (prev&&num<prev->info)
	{
		prev->left = new AVLNode<T>(num);
		if(prev->right == nullptr)
		incHeight = true;
	}
	if (incHeight == false)
	{
		return;
	}
	while (!myStack.isEmpty())
	{
		AVLNode<T>* pivot = myStack.pop();

		int balanceFactor = calculteBalanceFactor(pivot);
		if (balanceFactor == 0 || balanceFactor == -1 || balanceFactor == 1)
		{
			pivot->height = maxHeight(pivot->left, pivot->right) + 1;
			continue;
		}
		string rotation=getRoation(pivot,balanceFactor);
		if (rotation == "LL")
		{
			LL(pivot, myStack);
			continue;
		}
		if (rotation == "RR")
		{
			RR(pivot, myStack);
			continue;
		}
		if (rotation == "LR")
		{
			LR(pivot, myStack);
		}
		if (rotation == "RL")
		{
			RL(pivot, myStack);
		}
	}	
}
template<typename T>
int AVL<T>::calculteBalanceFactor(AVLNode<T>* pivot)
{
	int left = 0;
	if (pivot->left)
	{
		left = pivot->left->height;
	}
	int right = 0;
	if (pivot->right)
	{
		right = pivot->right->height;
	}
	int balanceFactor = left - right;
	return balanceFactor;
}
template<typename T>
void AVL<T>::deleteNodes(T data)
{
	AVLNode<T>* temp = root;
	MyStack<AVLNode<int>*>ancester;
	while (temp->info != data)
	{
		if (data > temp->info)
		{
			ancester.push(temp);
			temp = temp->right;
		}
		else if (data < temp->info)
		{
			ancester.push(temp);
			temp = temp->left;
		}
	}
	if (temp->left == nullptr && temp->right == nullptr)
	{
		if (temp == root)
		{
			root = nullptr;
			delete temp;
			return;
		}
		AVLNode<T>* pivot = ancester.pop();
		if (pivot->left == temp)
		{
			pivot->left = nullptr;
			delete temp;
			pivot->height = maxHeight(pivot->left, pivot->right) + 1;
			ancester.push(pivot);
		}
		if (pivot->right == temp)
		{
			delete temp;
			pivot->right = nullptr;
			pivot->height = maxHeight(pivot->left, pivot->right)+1;
			ancester.push(pivot);
		}
	}
	else if ((temp->left == nullptr && temp->right) || (temp->right == nullptr && temp->left))
	{
		if (temp == root)
		{
			if (temp->left != nullptr)
			{
				root = temp->left;
			}
			else
			{
				root = temp->right;
			}
			ancester.push(root);
		}
		else
		{
			AVLNode<T>* pivot = ancester.pop();
			AVLNode<T>* sub = temp->left ? temp->left : temp->right;
			if (pivot->left == temp)
			{
				pivot->left = sub;
			}
			else
			{
				pivot->right = sub;
			}
			pivot->height = maxHeight(pivot->left, pivot->right) + 1;
			ancester.push(pivot);
		}
	}
	else if(temp->left && temp->right)
	{
		AVLNode<T>* succ = temp->right;
		AVLNode<T>* previ = temp->right;
		MyStack < AVLNode<T>*> heightMaintain;
		heightMaintain.push(temp);
		ancester.push(temp);
		while (succ->left != nullptr)
		{
			previ = succ;
			ancester.push(succ);
			heightMaintain.push(succ);
			succ = succ->left;
		}
		temp->info = succ->info;
		if (succ == previ)
		{
			temp->right = succ->right;
		}
		else
		{
			previ->left = succ->right;
		}
		while (!heightMaintain.isEmpty())
		{
			AVLNode<T>* pivot = heightMaintain.pop();
			pivot->height = maxHeight(pivot->left, pivot->right)+1;
		}
		delete succ;
	}
	while (!ancester.isEmpty())
	{
			AVLNode<T>* pivot = ancester.pop();
			int balanceFactor = calculteBalanceFactor(pivot);
			if (balanceFactor == 0 || balanceFactor == -1 || balanceFactor == 1)
			{
				pivot->height = maxHeight(pivot->left, pivot->right) + 1;
				continue;
			}
			string rotation=getRoation(pivot,balanceFactor);
			if (rotation == "LL")
			{
				LL(pivot, ancester);
			}
			if (rotation == "RR")
			{
				RR(pivot, ancester);
			}
			if (rotation == "RL")
			{
				RL(pivot, ancester);
			}
			if (rotation == "LR")
			{
				LR(pivot, ancester);
			}
	}
	
}

