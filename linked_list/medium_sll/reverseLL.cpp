ListNode *reverseHead(ListNode *head)
{
    ListNode *temp = head;

    ListNode *prev = nullptr;

    while (temp)
    {
        ListNode *front = temp->next;
        temp->next = prev;

        prev = temp;

        temp = front;
    }

    return prev;
}
