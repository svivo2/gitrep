#include "Queue.h"

template <class T>

Queue<T>::Queue()
{
  head = NULL;
  tail = NULL;
  numElements = 0;
}

Queue<T>::~Queue()
{
  while (head != NULL)
  {
    Node * current = head;
    head = head->next;
    delete current;
  }
}

bool Queue<T>::empty() const
{
  return numElements == 0;
}

unsigned int Queue<T>::size() const
{
  return numElements;
}

T& Queue<T>::front()
{
  return head->elem;
}

const T& Queue<T>::front() const
{
  return head->elem;
}


T& Queue<T>::back()
{
  return tail->elem;
}


const T& Queue<T>::back() const
{
  return head->elem;
}

void Queue<T>::push(const T& x)
{
  if(this->empty())
  {
    head = new Node();
    head->elem = x;
    head->next = tail;
  }
  else
  {
    Node* node = new Node();
    node->elem = x;
    tail->next = node;
    tail = node;
    tail->next = NULL;
  }
  numElements++;
}

void Queue::pop()
{
  Node * cur = head;
  while (cur != tail)
    cur = cur->next;
  tail = NULL;
  delete tail;
  tail = cur;
  tail->next = NULL;
}

void Queue::print()
{
    cout << "[ ";
    for (Node* cur = head; cur != NULL; cur = cur->next)
    {
        cout << cur->elem << " ";
    }
    cout << "]" << endl;
}
