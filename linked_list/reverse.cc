struct Node {
  int data;
  Node *next;
};

void reverseLL(Node *head) {
  Node *prev = nullptr;
  Node *next = nullptr;
  Node *curr = head;

  while (curr) {
    next = curr->next;
    curr->next = prev;
    prev = curr;
    curr = next;
  }

  head = prev;
}
