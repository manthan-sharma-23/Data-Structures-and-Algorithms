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

int main()
{

    vector<int> arr = {10,
                       22,
                       34,
                       45,
                       57};

    Node *head = convertArr2LL(arr);

    Node *next1 = head->next;
    Node *next2 = next1->next;
    Node *next3 = next2->next;
    Node *next4 = next3->next;

    cout << head->data << endl;
    cout << next1->data << endl;
    cout << next2->data << endl;
    cout << next3->data << endl;
    cout << next4->data << endl;
    cout << next4->next << endl;
}
