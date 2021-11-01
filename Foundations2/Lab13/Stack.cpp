#include "Stack.h"

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
