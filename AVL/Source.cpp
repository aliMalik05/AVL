#include"AVL.h"
#include"LSLL.h"
template<typename T>
void insertIntoAVL(AVL<T>& tree,LSLL<T>& list)
{
	if (list.getHead() != nullptr)
	{
		tree.setRoot(list.getHead()->info);
		Node<T>* temp = list.getHead()->next;
		while (temp != nullptr)
		{
			tree.insert(temp->info);
			temp = temp->next;
		}
	}
}
int main()
{
	LSLL<int> list;
	list.insertAtTail(2);
	list.insertAtTail(7);
	list.insertAtTail(3);
	list.insertAtTail(9);
	AVL<int> tree;
	insertIntoAVL(tree, list);
	tree.LVRDecending(tree.root);





	return 0;
}