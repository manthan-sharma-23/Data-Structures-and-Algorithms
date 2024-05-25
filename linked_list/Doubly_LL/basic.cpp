#include <bits/stdc++.h>

using namespace std;

class Node
{
public:
    int data;
    Node *next;
    Node *prev;

public:
    Node(int data_, Node *next_, Node *prev_)
    {
        data = data_;
        next = next_;
        prev = prev_;
    }

public:
    Node(int data_, Node *prev_)
    {
        data = data_;
        next = nullptr;
        prev = prev_;
    }

public:
    Node(int data_)
    {
        data = data_;
        next = nullptr;
        prev = nullptr;
    }
};

Node *create_DLL_from_Arr(vector<int> v)
{
    Node *head = new Node(v[0]);
    Node *temp = head;

    for (int i = 1; i < v.size(); i++)
    {
        Node *node = new Node(v[i], temp);
        temp->next = node;
        temp = node;
    }

    return head;
};

void print_DLL(Node *head)
{
    Node *temp = head;
    while (temp)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }

    cout << endl;
}

Node *insert_at_end_DLL(Node *head, int data_)
{
    Node *temp = head;

    while (temp)
    {
        if (temp->next == nullptr)
        {
            Node *new_node = new Node(data_, temp);
            temp->next = new_node;
            break;
        }
        temp = temp->next;
    }

    return head;
};

int main()
{
    vector<int> v = {1, 2, 3, 4, 5, 6, 7};
    Node *head = create_DLL_from_Arr(v);
    print_DLL(head);

    insert_at_end_DLL(head, 8);
    print_DLL(head);
    insert_at_end_DLL(head, 9);
    print_DLL(head);
    insert_at_end_DLL(head, 10);
    print_DLL(head);

    return 0;
}