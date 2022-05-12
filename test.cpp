while (p != NULL) {
  Node *q = p->next;
  p->next = NULL;
  delete p;
  p = q;
}
