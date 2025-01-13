#include <algorithm>
#include <cmath>
#include <cstddef>
#include <cstdio>
#include <iterator>
#include <memory>
#include <vector>

enum PageType
{
  INTERNAL,
  LEAF
};
class BaseNode
{
public:
  int size;
  int max_size;
  PageType type;

  virtual ~BaseNode() {};

  BaseNode(int max_size_, PageType type_) : max_size(max_size_), type(type_) {}

  bool isLeaf() { return type == PageType::LEAF; }

  bool isOverflow() { return size > max_size; }

  bool isUnderFlow() { return size < std::floor((max_size + 1) / 2); }
};

class InternalNode : public BaseNode
{
public:
  std::vector<int> keys;
  std::vector<std::shared_ptr<BaseNode>> children;

  virtual ~InternalNode() {};

  InternalNode(int max_size_) : BaseNode(max_size_, PageType::INTERNAL) {}
};

class LeafNode : public BaseNode
{
public:
  std::vector<int> keys;
  std::vector<std::shared_ptr<char>> values;
  std::shared_ptr<LeafNode> next;

  virtual ~LeafNode() {};

  LeafNode(int max_size_) : BaseNode(max_size_, PageType::LEAF) {}
};

class BPlusTree
{
private:
  std::shared_ptr<BaseNode> root_;
  std::size_t degree;

  // find leaf node
  std::shared_ptr<LeafNode> findLeaf(int key)
  {
    auto current = root_;

    while (!current->isLeaf())
    {
      auto internal_node = std::dynamic_pointer_cast<InternalNode>(current);
      auto it = std::upper_bound(internal_node->keys.begin(),
                                 internal_node->keys.end(), key);
      auto index = std::distance(internal_node->keys.begin(), it);
      current = internal_node->children[index];
    }

    return std::dynamic_pointer_cast<LeafNode>(current);
  }

  void splitLeaf(std::shared_ptr<LeafNode> leaf)
  {
    auto new_leaf = std::make_shared<LeafNode>(degree - 1, LEAF);
    int mid = leaf->keys.size() / 2;

    new_leaf->keys.assign(leaf->keys.begin() + mid, leaf->keys.end());
    new_leaf->values.assign(leaf->values.begin() + mid, leaf->values.end());

    leaf->keys.resize(mid);
    leaf->values.resize(mid);

    new_leaf->next = leaf->next;
    leaf->next = new_leaf;

    insertIntoParent(leaf, new_leaf->keys[0], new_leaf);
  }

  void splitInternal(std::shared_ptr<InternalNode> internal)
  {
    int midIndex = internal->keys.size() / 2;
    int middleKey = internal->keys[midIndex];

    auto newInternal = std::make_shared<InternalNode>(degree - 1, INTERNAL);

    newInternal->keys.assign(internal->keys.begin() + midIndex + 1,
                             internal->keys.end());
    newInternal->children.assign(internal->children.begin() + midIndex + 1,
                                 internal->children.end());

    internal->keys.resize(midIndex);
    internal->children.resize(midIndex + 1);

    insertIntoParent(internal, middleKey, newInternal);
  }

  void insertIntoParent(std::shared_ptr<BaseNode> left, int key,
                        std::shared_ptr<BaseNode> right)
  {
    if (left == root_)
    {
      auto new_root = std::make_shared<InternalNode>(degree - 1, INTERNAL);
      new_root->keys.push_back(key);
      new_root->children.push_back(left);
      new_root->children.push_back(right);
      root_ = new_root;
      return;
    }

    auto parent = findParent(root_, left);
    auto internal = std::dynamic_pointer_cast<InternalNode>(parent);

    auto it =
        std::upper_bound(internal->keys.begin(), internal->keys.end(), key);
    int index = std::distance(internal->keys.begin(), it);

    internal->keys.insert(it, key);
    internal->children.insert(internal->children.begin() + index + 1, right);

    if (internal->keys.size() > internal->max_size)
    {
      splitInternal(internal);
    }
  }

  std::shared_ptr<BaseNode> findParent(std::shared_ptr<BaseNode> current,
                                       std::shared_ptr<BaseNode> target)
  {

    if (current->isLeaf())
    {
      return nullptr;
    }

    auto internal = std::dynamic_pointer_cast<InternalNode>(current);
    for (size_t i = 0; i < internal->children.size(); i++)
    {
      if (internal->children[i] == target)
        return std::dynamic_pointer_cast<BaseNode>(current);
    }

    for (size_t i = 0; i < internal->children.size(); i++)
    {
      auto child = internal->children[i];
      auto parent = findParent(child, target);
      if (parent != nullptr)
      {
        return parent;
      }
    }
    return nullptr;
  }

  void handleLeafUnderFlow(std::shared_ptr<LeafNode> leaf)
  {
    auto parent = findParent(root_, leaf);
    if (!parent)
    {
      return;
    }

    auto internal = std::dynamic_pointer_cast<InternalNode>(parent);
    int idx = std::distance(
        internal->children.begin(),
        std::find(internal->children.begin(), internal->children.end(), leaf));

    auto leftSibling =
        idx > 0
            ? std::dynamic_pointer_cast<LeafNode>(internal->children[idx - 1])
            : nullptr;

    auto rightSibling =
        idx < internal->children.size() - 1
            ? std::dynamic_pointer_cast<LeafNode>(internal->children[idx + 1])
            : nullptr;

    if (leftSibling && !leftSibling->isUnderFlow())
    {
      borrowFromLeft(leaf, leftSibling, internal, idx);
      return;
    }

    if (rightSibling && !rightSibling->isUnderFlow())
    {
      borrowFromRight(leaf, rightSibling, internal, idx);
      return;
    }

    if (leftSibling)
    {
      mergeLeaves(leftSibling, leaf, internal, idx - 1);
    }
    else if (rightSibling)
    {
      mergeLeaves(leaf, rightSibling, internal, idx);
    }
  }

  void borrowFromLeft(std::shared_ptr<LeafNode> leaf,
                      std::shared_ptr<LeafNode> leftSibling,
                      std::shared_ptr<InternalNode> parent, int idx)
  {
    leaf->keys.insert(leaf->keys.begin(), leftSibling->keys.back());
    leaf->values.insert(leaf->values.begin(), leftSibling->values.back());
    leftSibling->keys.pop_back();
    leftSibling->values.pop_back();
    parent->keys[idx] = leaf->keys[0];
  }

  void borrowFromRight(std::shared_ptr<LeafNode> leaf,
                       std::shared_ptr<LeafNode> rightSibling,
                       std::shared_ptr<InternalNode> parent, int idx)
  {
    leaf->keys.push_back(rightSibling->keys[0]);
    leaf->values.push_back(rightSibling->values[0]);
    rightSibling->keys.erase(rightSibling->keys.begin());
    rightSibling->values.erase(rightSibling->values.begin());
    parent->keys[idx + 1] = rightSibling->keys[0];
  }

  void borrowFromLeft(std::shared_ptr<InternalNode> leaf,
                      std::shared_ptr<InternalNode> leftSibling,
                      std::shared_ptr<InternalNode> parent, int idx)
  {
    leaf->keys.insert(leaf->keys.begin(), leftSibling->keys.back());
    leaf->children.insert(leaf->children.begin(), leftSibling->children.back());
    leftSibling->keys.pop_back();
    leftSibling->children.pop_back();
    parent->keys[idx] = leaf->keys[0];
  }

  void borrowFromRight(std::shared_ptr<InternalNode> leaf,
                       std::shared_ptr<InternalNode> rightSibling,
                       std::shared_ptr<InternalNode> parent, int idx)
  {
    leaf->keys.push_back(rightSibling->keys[0]);
    leaf->children.push_back(rightSibling->children[0]);
    rightSibling->keys.erase(rightSibling->keys.begin());
    rightSibling->children.erase(rightSibling->children.begin());
    parent->keys[idx + 1] = rightSibling->keys[0];
  }

  void mergeLeaves(std::shared_ptr<LeafNode> left,
                   std::shared_ptr<LeafNode> right,
                   std::shared_ptr<InternalNode> parent, int idx)
  {
    left->values.insert(left->values.end(), right->values.begin(),
                        right->values.end());
    left->keys.insert(left->keys.end(), right->keys.begin(), right->keys.end());
    left->next = right->next;

    parent->keys.erase(parent->keys.begin() + idx);
    parent->children.erase(parent->children.begin() + idx + 1);

    if (parent->isUnderFlow())
    {
      handleInternalUnderFlow(parent);
    }
  }

  void handleInternalUnderFlow(std::shared_ptr<InternalNode> internal)
  {
    auto parent =
        std::dynamic_pointer_cast<InternalNode>(findParent(root_, internal));
    if (!parent)
    {
      return;
    }

    int idx = std::distance(
        parent->children.begin(),
        std::find(parent->children.begin(), parent->children.end(), internal));

    // Check if we can borrow from left sibling
    auto leftSibling =
        (idx > 0)
            ? std::dynamic_pointer_cast<InternalNode>(parent->children[idx - 1])
            : nullptr;
    if (leftSibling &&
        leftSibling->keys.size() > std::ceil(internal->max_size / 2.0))
    {
      borrowFromLeft(internal, leftSibling, parent, idx);
      return;
    }

    // Check if we can borrow from right sibling
    auto rightSibling =
        (idx < parent->children.size() - 1)
            ? std::dynamic_pointer_cast<InternalNode>(parent->children[idx + 1])
            : nullptr;
    if (rightSibling &&
        rightSibling->keys.size() > std::ceil(internal->max_size / 2.0))
    {
      borrowFromRight(internal, rightSibling, parent, idx);
      return;
    }

    // If no borrowing possible, merge with a sibling
    if (leftSibling)
    {
      mergeInternalNodes(leftSibling, internal, parent, idx - 1);
    }
    else if (rightSibling)
    {
      mergeInternalNodes(internal, rightSibling, parent, idx);
    }
  }

  void mergeInternalNodes(std::shared_ptr<InternalNode> left,
                          std::shared_ptr<InternalNode> right,
                          std::shared_ptr<InternalNode> parent, int idx)
  {
    // Merge the right sibling into the left node
    left->keys.push_back(parent->keys[idx]);
    left->keys.insert(left->keys.end(), right->keys.begin(), right->keys.end());
    left->children.insert(left->children.end(), right->children.begin(),
                          right->children.end());

    // Remove the merged key and child pointer from the parent
    parent->keys.erase(parent->keys.begin() + idx);
    parent->children.erase(parent->children.begin() + idx + 1);

    // If the parent is now underflowed, handle it recursively
    if (parent->isUnderFlow())
    {
      handleInternalUnderFlow(parent);
    }
  }

public:
  bool insert(int key, char *value)
  {
    if (root_ == nullptr)
    {
      root_ = std::make_shared<LeafNode>(degree - 1, LEAF);
      return true;
    }

    std::shared_ptr<LeafNode> leaf = findLeaf(key);
    auto it = std::lower_bound(leaf->keys.begin(), leaf->keys.end(), key);
    int index = std::distance(leaf->keys.begin(), it);
    if (leaf->keys[index] == key)
    {
      printf("Key already exists\n");
      return 0;
    }
    leaf->keys.insert(it, key);
    leaf->values.insert(leaf->values.begin() + index,
                        std::make_shared<char>(value));

    if (leaf->isOverflow())
    {
      splitLeaf(leaf);
    }

    return 0;
  }

  std::shared_ptr<char> search(int key)
  {
    std::shared_ptr<LeafNode> leaf = findLeaf(key);
    auto it = std::lower_bound(leaf->keys.begin(), leaf->keys.end(), key);
    int index = std::distance(leaf->keys.begin(), it);
    if (leaf->keys[index] == key)
    {
      return leaf->values[index];
    }
    return nullptr;
  }

  std::vector<std::shared_ptr<char>> rangedSearch(int lowerKey, int higherKey)
  {

    std::vector<std::shared_ptr<char>> result;
    std::shared_ptr<LeafNode> leaf = findLeaf(lowerKey);
    auto it = std::lower_bound(leaf->keys.begin(), leaf->keys.end(), lowerKey);
    int index = std::distance(leaf->keys.begin(), it);

    while (leaf != nullptr)
    {
      for (int i = index; i < leaf->keys.size(); i++)
      {
        int key = leaf->keys[i];
        if (key >= lowerKey && key <= higherKey)
        {
          result.push_back(leaf->values[i]);
        }

        if (key > higherKey)
          return result;
      }
      leaf = leaf->next;
    }

    return result;
  };

  void remove(int key)
  {
    auto leaf = findLeaf(key);
    if (!leaf)
    {
      return;
    }
    auto it = std::lower_bound(leaf->keys.begin(), leaf->keys.end(), key);
    if (it == leaf->keys.end() || *it != key)
    {
      return;
    }

    int index = std::distance(leaf->keys.begin(), it);
    leaf->keys.erase(it);
    leaf->values.erase(leaf->values.begin() + index);

    if (leaf->isUnderFlow())
    {
      handleLeafUnderFlow(leaf);
    }
  }
};

int main()
{

  BPlusTree tree;
}
