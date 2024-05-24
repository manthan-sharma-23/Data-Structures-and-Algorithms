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
    Node *temp = head;

    for (int i = 1; i < v.size(); i++)
    {
        Node *node = new Node(v[i]);
        temp->next = node;

        temp = node;
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

void insert_Node_LL(Node *head, int node_data)
{

    Node *temp = head;

    while (temp)
    {
        if (temp->next == nullptr)
        {
            Node *new_node = new Node(node_data);
            temp->next = new_node;
            return;
        }
        temp = temp->next;
    }
};

int main()
{

    vector<int> v = {1, 2, 4, 5, 6};
    Node *head = createLLfromArr(v);
    printLL(head);
    insert_Node_LL(head, 88);
    printLL(head);

    return 0;
}