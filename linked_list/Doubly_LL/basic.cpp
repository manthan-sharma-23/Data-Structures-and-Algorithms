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

// Delete Indexed Node from DLL
Node *delete_indexed_node_DLL(Node *head, int index_)
{
    Node *temp = head;
    int cnt = 0;

    if (head->next == nullptr && head->prev == nullptr)
    {
        if (index_ == 0)
        {
            head = nullptr;
            return head;
        }
        else
        {
            return head;
        }
    }

    while (temp)
    {
        if (cnt == index_)
        {
            // head
            if (temp->prev == nullptr)
            {
                temp->next->prev = nullptr;
                head = temp->next;
                return head;
            }

            // tail
            if (temp->next == nullptr)
            {
                temp->prev->next = nullptr;
                return head;
            }

            // regular
            Node *prev = temp->prev;
            Node *next = temp->next;

            prev->next = next;
            next->prev = prev;

            return head;
        }
        temp = temp->next;
        cnt++;
    }

    return head;
};

// optimal approach for reversing a DLL
Node *reverse_DLL(Node *head)
{
    Node *temp = nullptr;
    Node *current = head;

    // Swap next and prev for all nodes
    while (current != nullptr)
    {
        temp = current->prev;
        current->prev = current->next;
        current->next = temp;
        current = current->prev;
    }

    // Before changing head, check for the cases like empty
    // list and list with only one node
    if (temp != nullptr)
    {
        head = temp->prev;
    }

    return head;
}

int main()
{
    vector<int> v = {1, 2, 3, 4, 5, 6, 7};
    Node *head = create_DLL_from_Arr(v);
    print_DLL(head);

    insert_at_end_DLL(head, 8);
    // print_DLL(head);
    insert_at_end_DLL(head, 9);
    // print_DLL(head);
    insert_at_end_DLL(head, 10);
    print_DLL(head);

    // // Delete an index from DLL
    // Node *head_ = delete_indexed_node_DLL(head, 10 - 1);
    // print_DLL(head_);

    // reverse a dll
    Node *rev = reverse_DLL(head);
    print_DLL(rev);

    return 0;
}