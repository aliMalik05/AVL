#include"MyStack.h"
template<typename T>
MyStack<T>::MyStack()
{
	data = nullptr;
	capacity = 0;
	top = 0;
}
template<typename T>
void MyStack<T> ::reSize(int num)
{
	if (num <= 0)
	{
		delete[] data;
		data = nullptr;
		capacity = 0;
		top = 0;
	}
	else
	{
		T* temp = new T[num];
		for (int i = 0; i < capacity && i < num; i++)
		{
			temp[i] = data[i];
		}
		delete[]data;
		data = temp;
		temp = nullptr;
		capacity = num;
	}
}
template<typename T>
MyStack<T>::~MyStack()
{
	delete[]data;
	data = nullptr;
	capacity = 0;
	top = 0;
}
template<typename T>
void MyStack<T>::push(T a)
{
	if (capacity == 0)
	{
		reSize(1);
	}
	if (this->isFull())
	{
		reSize(capacity * 2);
	}
	data[top] = a;
	top++;
}
template<typename T>
bool MyStack<T>::isFull() const
{
	if (top == capacity)
	{
		return true;
	}
	return false;
}
template<typename T>
bool MyStack<T>::isEmpty() const
{
	if (top == 0)
	{
		return true;
	}
	return false;
}
template<typename T>
T  MyStack<T>::pop()
{
	if (!this->isEmpty())
	{
		T temp = data[--top];
		if (top == capacity / 4)
		{
			reSize(capacity / 2);
		}
		return temp;
	}
	else
		exit(0);
}
template<typename T>
T  MyStack<T>::stackTop() const
{
	return data[top - 1];
}
template<typename T>
int MyStack<T>::getCapacity() const
{
	return capacity;
}
template<typename T>
int MyStack<T>::getNumberOfElements() const
{
	return top;
}
template<typename T>
MyStack<T>::MyStack(const MyStack<T>& ref)
{
	if (!ref.data)
	{
		return;
	}
	*this = ref;
}
template<typename T>
MyStack<T>& MyStack<T>::operator = (const MyStack<T>& ref)
{
	if (this == &ref)
	{
		return *this;
	}
	this->~MyStack();
	if (ref.data == nullptr)
	{
		return *this;
	}
	capacity = ref.capacity;
	top = ref.top;
	data = new T[ref.capacity];
	for (int i = 0; i < ref.capacity; i++)
	{
		data[i] = ref.data[i];
	}
	return *this;
}
template<typename T>
void MyStack<T>::display()
{
	for (int i = 0; i < top; i++)
	{
		cout << data[i] << "  ";
	}
	cout << endl;

}