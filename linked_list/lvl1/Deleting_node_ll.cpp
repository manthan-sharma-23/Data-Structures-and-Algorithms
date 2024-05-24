#include <bits/stdc++.h>

using namespace std;

class Node
{
public:
    int data;
    Node *next;

public:
    Node(int data1)
    {
        data = data1;
        next = nullptr;
    }

public:
    Node(int data1, Node *next1)
    {
        data = data1;
        next = next1;
    }
};

Node *createLLfromArr(vector<int> v)
{
    Node *head = new Node(v[0]);
    Node *move = head;

    for (int i = 1; i < v.size(); i++)
    {
        Node *temp = new Node(v[i]);
        move->next = temp;
        move = temp;
    }

    return head;
};

Node *deleteNodefromLL(Node *head, Node *node)
{
    Node *temp = head;

    while (temp)
    {
        if (temp->next == node)
        {
            if (temp->next->next == nullptr)
            {
                temp->next = nullptr;
                return head;
            }
            else
            {
                temp->next = temp->next->next;

                return head;
            }
        }
        else
        {
            temp = temp->next;
        }
    }

    return head;
};

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

    vector<int> arr = {1, 2, 33, 4};
    Node *head = createLLfromArr(arr);
    printLL(head);
    deleteNodefromLL(head, head->next->next);
    printLL(head);
    return 0;
}