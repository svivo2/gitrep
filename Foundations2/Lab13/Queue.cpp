#include "Queue.h"

Queue::Queue()
{
  head = NULL;
  tail = NULL;
  numElements = 0;
}

Queue::~Queue()
{
  while (head != NULL)
  {
    Node * current = head;
    head = head->next;
    delete current;
  }
}

bool Queue::empty() const
{
  return numElements == 0;
}

unsigned int Queue::size() const
{
  return numElements;
}

int& Queue::front()
{
  return head->elem;
}

const int& Queue::front() const
{
  return head->elem;
}


int& Queue::back()
{
  return tail->elem;
}


const int& Queue::back() const
{
  return head->elem;
}

void Queue::push(const int& x)
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
