#include "Stack.h"

Stack<T>::Stack()
{
  capacity = 8;
  buffer = new int[capacity];
  numElements = 0;
  topIndex = 0;
}

Stack<T>::~Stack()
{
  buffer = NULL;
  delete[] buffer;
}

bool Stack<T>::empty() const
{
  return numElements == 0;
}

unsigned int Stack<T>::size() const
{
  return numElements;
}

T& Stack<T>::top()
{
  return buffer[topIndex];
}

const T& Stack<T>::top() const
{
  return buffer[topIndex];
}

void Stack<T>::push(const int& x)
{
  if (topIndex == capacity)
  {
    capacity = capacity * 2;
    int * temp = new int[capacity];
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

void Stack<T>::pop()
{
  topIndex--;
}

void Stack<T>::print()
{
    cout << "[ ";
    for (int i = 0; i < numElements; ++i)
    {
        cout << buffer[i] << " ";
    }
    cout << "]" << endl;
}
