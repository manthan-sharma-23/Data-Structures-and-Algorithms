#include <iostream>
#include <vector>

class BinaryTree
{
public:
    BinaryTree(int size)
    {
        // Initialize the array to hold binary tree nodes
        tree.resize(size, -1); // -1 represents an empty node
        this->size = size;
    }

    void insert(int value, int index)
    {
        // Insert a value at the given index in the binary tree
        if (index >= size)
        {
            std::cout << "Index out of bounds" << std::endl;
        }
        else
        {
            tree[index] = value;
        }
    }

    int getLeftChild(int index) const
    {
        // Calculate the left child index and return its value
        int leftIndex = 2 * index + 1;
        if (leftIndex < size)
        {
            return tree[leftIndex];
        }
        return -1; // Indicate no child exists
    }

    int getRightChild(int index) const
    {
        // Calculate the right child index and return its value
        int rightIndex = 2 * index + 2;
        if (rightIndex < size)
        {
            return tree[rightIndex];
        }
        return -1; // Indicate no child exists
    }

    int getParent(int index) const
    {
        // Calculate the parent index and return its value
        if (index == 0)
        {
            return -1; // Root node has no parent
        }
        int parentIndex = (index - 1) / 2;
        return tree[parentIndex];
    }

    void printTree() const
    {
        // Print the tree for visualization
        std::cout << "Binary Tree Array Representation:" << std::endl;
        for (int i = 0; i < size; ++i)
        {
            if (tree[i] != -1)
            {
                std::cout << "Index " << i << ": " << tree[i] << std::endl;
            }
        }
    }

private:
    std::vector<int> tree;
    int size;
};

int main()
{
    BinaryTree bt(10);

    bt.insert(1, 0); // Root node
    bt.insert(2, 1); // Left child of root
    bt.insert(3, 2); // Right child of root
    bt.insert(4, 3); // Left child of node at index 1
    bt.insert(5, 4); // Right child of node at index 1

    bt.printTree();

    int index = 1;
    std::cout << "Left child of node at index " << index << ": " << bt.getLeftChild(index) << std::endl;
    std::cout << "Right child of node at index " << index << ": " << bt.getRightChild(index) << std::endl;
    std::cout << "Parent of node at index " << index << ": " << bt.getParent(index) << std::endl;

    return 0;
}
