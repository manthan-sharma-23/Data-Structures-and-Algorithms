struct ListNode {
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
  ListNode *reverse(ListNode *tail) {
    ListNode *curr = tail;
    ListNode *prev = nullptr;
    ListNode *follow;
    while (curr != nullptr) {
      follow = curr->next;
      curr->next = prev;
      prev = curr;
      curr = follow;
    }
    return prev;
  }
  ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
    int n1 = 0, n2 = 0;
    ListNode *Node1 = l1;
    ListNode *Node2 = l2;

    ListNode *curr1 = Node1;
    ListNode *curr2 = Node2;

    while (curr1 != nullptr) {
      n1 = n1 * 10 + curr1->val;
      curr1 = curr1->next;
    }
    while (curr2 != nullptr) {
      n2 = n2 * 10 + curr2->val;
      curr2 = curr2->next;
    }
    int sum = n1 + n2;
    if (sum == 0) {
      ListNode *n = new ListNode(0);
      return n;
    }

    ListNode *head = nullptr;
    ListNode *prev = nullptr;

    while (sum) {
      int digit = sum % 10;
      sum = sum / 10;
      if (!head) {
        head = new ListNode(digit, nullptr);
        prev = head;
      } else {
        ListNode *new_node = new ListNode(digit);
        
      }
    }
    return head;
  }
};