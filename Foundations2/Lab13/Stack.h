/*
 * File:   Stack.h
 * Author: Jon C. Hammer
 *
 * Created on April 1, 2016, 11:24 AM
 */

#ifndef STACK_H
#define STACK_H

#include <iostream>
using namespace std;

template <class T>

class Stack
{
public:
    // Constructors
    Stack();
    ~Stack();

    // Capacity
    bool empty() const;
    unsigned int size() const;

    // Element access
    T& top();
    const T& top() const;

    // Modification
    void push(const T& x);
    void pop();

    void print();

private:
    T* buffer;              // The dynamically-allocated array that holds the stack
    unsigned int numElements; // The number of elements currently on the stack
    unsigned int topIndex;    // The index of the top of the stack (0 initially)
    unsigned int capacity;
};

template <class T>
Stack<T>::Stack()
{
  capacity = 8;
  buffer = new T[capacity];
  numElements = 0;
  topIndex = 0;
}

template <class T>
Stack<T>::~Stack()
{
  buffer = NULL;
  delete[] buffer;
}

template <class T>
bool Stack<T>::empty() const
{
  return numElements == 0;
}

template <class T>
unsigned int Stack<T>::size() const
{
  return numElements;
}

template <class T>
T& Stack<T>::top()
{
  return buffer[topIndex];
}

template <class T>
const T& Stack<T>::top() const
{
  return buffer[topIndex];
}

template <class T>
void Stack<T>::push(const T& x)
{
  if (topIndex == capacity)
  {
    capacity = capacity * 2;
    T * temp = new T[capacity];
    for (int i = 0; i < topIndex; i++)
      temp[i] = buffer[i];
    delete[] buffer;
    buffer = NULL;
    buffer = temp;
    temp = NULL;
    delete[] temp;
  }
  buffer[topIndex++] = x;
}

template <class T>
void Stack<T>::pop()
{
  topIndex--;
}

template <class T>
void Stack<T>::print()
{
    cout << "[ ";
    for (int i = 0; i < numElements; ++i)
    {
        cout << buffer[i] << " ";
    }
    cout << "]" << endl;
}


#endif /* STACK_H */
