#include <bits/stdc++.h>

using namespace std;

class Node
{
public:
    int data;
    Node *next;

public:
    Node(int data1, Node *next1)
    {
        data = data1;
        next = next1;
    }

public:
    Node(int data1)
    {
        data = data1;
        next = nullptr;
    }
};

Node *convertArr2LL(vector<int> arr)
{
    Node *head = new Node(arr[0]);
    Node *mover = head;

    for (int i = 1; i < arr.size(); i++)
    {
        Node *temp = new Node(arr[i]);
        mover->next = temp;
        mover = temp;
    }

    return head;
}
int lengthOfLL(Node *head)
{
    int cnt = 0;
    while (head)
    {
        cnt++;
        head = head->next;
    }

    return cnt;
}
Node *middleNodeBruteForce(Node *head)
{
    if (head == nullptr)
    {
        return nullptr;
    }

    int length = lengthOfLL(head);

    int mid = length / 2;

    Node *temp = head;

    for (int i = 0; i < mid; i++)
    {
        temp = temp->next;
    }
    return temp;
}

Node *middleNodeOptimal(Node *head)
{
    if (head == nullptr)
    {
        return nullptr;
    }

    Node *temp = head;
    Node *fast = temp;
    Node *slow = temp;

    while (fast && fast->next)
    {
        slow = slow->next;
        fast = fast->next->next;
    }

    return slow;
}

void printLL(Node *head)
{
    Node *temp = head;

    while (temp)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
};

int main()
{
    vector<int> v = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    Node *head = convertArr2LL(v);

    Node *middle = middleNodeOptimal(head);

    cout << middle->data << endl;

    return 0;
}