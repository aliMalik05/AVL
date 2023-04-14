#ifndef MYSTACK_H
#define MYSTACK_H
#include<iostream>
using namespace std;
template<typename T>
class MyStack
{
    T* data;
    int capacity;
    int top;
    void reSize(int);
public:
    MyStack();
    MyStack(const MyStack<T>&);
    MyStack& operator = (const MyStack<T>&);
    ~MyStack();
    void push(T);
    T pop();
    T stackTop() const;
    bool isFull() const;
    bool isEmpty() const;
    int getCapacity() const;
    int getNumberOfElements() const;
    void display();
};
#endif;
