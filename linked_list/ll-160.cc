
// Definition for singly-linked list.
#include <cstddef>
#include <cstdlib>

using namespace std;

struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
  int getLength(ListNode *head) {
    int length = 0;
    while (head) {
      length++;
      head = head->next;
    }
    return length;
  }

  ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
    if (!headA || !headB)
      return nullptr;

    int lenA = getLength(headA);
    int lenB = getLength(headB);

    int diff = abs(lenA - lenB);

    ListNode *longer = lenA > lenB ? headA : headB;
    ListNode *shorter = lenA > lenB ? headB : headA;

    while (diff--) {
      longer = longer->next;
    }

    while (longer && shorter) {
      if (longer == shorter) {
        return longer;
      }
      longer = longer->next;
      shorter = shorter->next;
    }

    return nullptr;
  }
};
