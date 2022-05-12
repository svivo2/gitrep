struct Node {
  int value;
  Node *next;
  Node(int value, Node *next = NULL);
  Node();
  ~Node();
};

class LinkedList {
private:
Node* header;
public:
  LinkedList();
  ~LinkedList();
  int insertNode(int value);
  int deleteNode(int value);
  int searchNode(int value);
  int length();
};
