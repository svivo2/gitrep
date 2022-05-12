Node::Node(int value, Node *next) {
  // This is the constructor of Node with initialized value and next pointer
  // You do not need to modify this constructor
  this->value = value;
  this->next = next;
}
Node::Node() {
  // This is an empty constructor
  // You do not need to modify this constructor
  this->value = 0;
  this->next = NULL;
}
Node::~Node() {
// This an empty deconstructor
// You do not need to modify this deconstuctor
}

LinkedList::LinkedList() {
// This is an empty constructor
// You do not need to modify this constructor
}
LinkedList::~LinkedList() {
  // This is the deconstructor used to release the current linked list
  // You do not need to modify this constructor
  Node *p = this->header;
  while (p != NULL) {
    Node *q = p->next;
    p->next = NULL;
    delete p;
    p = q;
  }
}

int LinkedList::insertNode(int value) {
  /*
  * This function will insert value into the linked list
  * Return 1 if the function the value is inserted in to the linked list * successfully (basically it should always return 1)
  */
  Node *p = this->header;
  // Your Code Here
  Node * newNode = new Node(value);
  newNode->next = p;
  this->header = newNode;

  return 1;
}
int LinkedList::deleteNode(int value) {
  /*
  * This function will delete value out of linked list if value exists
  * Return 1 if value is deleted successfully
  * Return 0 if the value does not exist
  */
  Node *p = this->header;
  // Your Code Here
  if(p->value == value){
    this->header = p->next;
    delete p;
    return 1;
  }
  else{
    while(p->next != NULL){
      if(p->next->value == value){
        Node *q = p->next;
        p->next = q->next;
        delete q;
        return 1;
      }
      p = p->next;
    }
  }
  return 0;
}
int LinkedList::searchNode(int value) {
  /*
  * This function will search for the value in the linked list
  * Return 1 if the value exists, otherwise return 0
  */
  Node *p = this->header;
  // Your Code Here
  if(p->value == value){
    return 1;
  }
  else{
    while(p->next != NULL){
      if(p->next->value == value){
        return 1;
      }
      p = p->next;
    }
  }
  return 0;
}
int LinkedList::length() {
  /*
  * This function will return the length of linked list
  * Return the current number of nodes in the linked list
  */
  Node *p = this->header;
  // Your Code Here
}

void *createLinkedList() {
 return new(std::nothrow) LinkedList();
}
int insertNode(void *linkedList, int value) {
  LinkedList* linkedList_ = reinterpret_cast<LinkedList*>(linkedList);
  return linkedList_->insertNode(value);
}
int deleteNode(void* linkedList, int value) {
  LinkedList* linkedList_ = reinterpret_cast<LinkedList*>(linkedList);
  return linkedList_->deleteNode(value);
}
int searchNode(void* linkedList, int value) {
  LinkedList* linkedList_ = reinterpret_cast<LinkedList*>(linkedList);
  return linkedList_->searchNode(value);
}
void releaseLinkedList(void* linkedList) {
  delete linkedList;
}
int length(void *linkedList) {
  LinkedList* linkedList_ = reinterpret_cast<LinkedList*>(linkedList);
  return linkedList_->length();
}
