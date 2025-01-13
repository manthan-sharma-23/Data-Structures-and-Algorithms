class Node
{
public:
    int data;
    Node *left;
    Node *right;

    Node(int val)
    {
        data = val;

        left = right = nullptr;
    }
};

void bfs(Node *root)
{
}