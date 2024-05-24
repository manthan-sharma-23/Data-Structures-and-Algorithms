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

bool searchAnElementInLL(Node *head, int x)
{
    Node *temp = head;

    while (temp)
    {
        if (temp->data == x)
        {
            cout << "Found " << endl;
            return true;
        }
        temp = temp->next;
    }
    cout << "Not Found" << endl;
    return false;
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

    vector<int> arr = {10,
                       22,
                       34,
                       45,
                       57};

    Node *head = convertArr2LL(arr);

    cout << head << endl;

    // Traverse a linked list
    Node *temp = head;
    while (temp)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }

    // Length of LL
    int lengthLL = lengthOfLL(head);
    cout << endl
         << lengthLL << endl;

    cout << head << endl;

    // Search in ll
    searchAnElementInLL(head, 57);

    cout << endl;
}
