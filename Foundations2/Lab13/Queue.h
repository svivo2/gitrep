/*
 * File:   Queue.h
 * Author: Jon C. Hammer
 *
 * Created on April 1, 2016, 11:22 AM
 */

#ifndef QUEUE_H
#define QUEUE_H

#include <cstdlib>
#include <iostream>
using namespace std;

template <class T>
// Basic Node structure
struct Node
{
    T elem;    // Data
    Node * next; // Pointer to the next node in the chain
};

template <class T>

class Queue
{
public:
    // Constructors
    Queue();
    ~Queue();

    // Capacity
    bool empty() const;
    unsigned int size() const;

    // Element access
    T& front();
    const T& front() const;
    T& back();
    const T& back() const;

    // Modification
    void push(const T& x);
    void pop();

    void print();

private:
    Node<T>* head;               // The front of the queue
    Node<T>* tail;               // The end of the queue
    unsigned int numElements; // The number of elements in the queue
};

template <class T>

Queue<T>::Queue()
{
  head = NULL;
  tail = NULL;
  numElements = 0;
}

template <class T>
Queue<T>::~Queue()
{
  while (head != NULL)
  {
    Node<T> * current = head;
    head = head->next;
    delete current;
  }
}

template <class T>
bool Queue<T>::empty() const
{
  return numElements == 0;
}

template <class T>
unsigned int Queue<T>::size() const
{
  return numElements;
}

template <class T>
T& Queue<T>::front()
{
  return head->elem;
}

template <class T>
const T& Queue<T>::front() const
{
  return head->elem;
}

template <class T>
T& Queue<T>::back()
{
  return tail->elem;
}

template <class T>
const T& Queue<T>::back() const
{
  return head->elem;
}

template <class T>
void Queue<T>::push(const T& x)
{
  if(this->empty())
  {
    head = new Node<T>();
    head->elem = x;
    head->next = tail;
  }
  else
  {
    Node<T>* node = new Node<T>();
    node->elem = x;
    tail->next = node;
    tail = node;
    tail->next = NULL;
  }
  numElements++;
}

template <class T>
void Queue<T>::pop()
{
  Node<T> * cur = head;
  while (cur != tail)
    cur = cur->next;
  tail = NULL;
  delete tail;
  tail = cur;
  tail->next = NULL;
}

template <class T>
void Queue<T>::print()
{
    cout << "[ ";
    for (Node<T>* cur = head; cur != NULL; cur = cur->next)
    {
        cout << cur->elem << " ";
    }
    cout << "]" << endl;
}


#endif /* QUEUE_H */
