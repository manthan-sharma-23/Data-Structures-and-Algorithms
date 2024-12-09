#include <algorithm>
#include <cstddef>
#include <cstdio>
#include <iterator>
#include <memory>
#include <vector>

enum PageType { INTERNAL, LEAF };
class BaseNode {
public:
  int size;
  int max_size;
  PageType type;

  virtual ~BaseNode() {};

  BaseNode(int max_size_, PageType type_) : max_size(max_size_), type(type_) {}

  bool isLeaf() { return type == PageType::LEAF; }

  bool isOverflow() { return size > max_size; }
};

class InternalNode : public BaseNode {
public:
  std::vector<int> keys;
  std::vector<std::shared_ptr<BaseNode>> children;

  virtual ~InternalNode() {};

  InternalNode(int max_size_) : BaseNode(max_size_, PageType::INTERNAL) {}
};

class LeafNode : public BaseNode {
public:
  std::vector<int> keys;
  std::vector<char *> values;
  std::shared_ptr<LeafNode> next;

  virtual ~LeafNode() {};

  LeafNode(int max_size_) : BaseNode(max_size_, PageType::LEAF) {}
};

class BPlusTree {
private:
  std::shared_ptr<BaseNode> root_;
  std::size_t degree;

  // find leaf node
  std::shared_ptr<LeafNode> findLeaf(int key) {
    auto current = root_;

    while (!current->isLeaf()) {
      auto internal_node = std::dynamic_pointer_cast<InternalNode>(current);
      auto it = std::upper_bound(internal_node->keys.begin(),
                                 internal_node->keys.end(), key);
      auto index = std::distance(internal_node->keys.begin(), it);
      current = internal_node->children[index];
    }

    return std::dynamic_pointer_cast<LeafNode>(current);
  }

  void splitLeaf(std::shared_ptr<LeafNode> leaf) {
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

  void splitInternal(std::shared_ptr<InternalNode> internal) {
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
                        std::shared_ptr<BaseNode> right) {
    if (left == root_) {
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

    if (internal->keys.size() > internal->max_size) {
      splitInternal(internal);
    }
  }

  std::shared_ptr<BaseNode> findParent(std::shared_ptr<BaseNode> current,
                                       std::shared_ptr<BaseNode> target) {

    if (current->isLeaf()) {
      return nullptr;
    }

    auto internal = std::dynamic_pointer_cast<InternalNode>(current);
    for (size_t i = 0; i < internal->children.size(); i++) {
      if (internal->children[i] == target)
        return current;
    }

    for (size_t i = 0; i < internal->children.size(); i++) {
      auto child = internal->children[i];
      auto parent = findParent(child, target);
      if (parent != nullptr) {
        return parent;
      }
    }

    return nullptr;
  }

public:
  bool insert(int key, char *value) {
    if (root_ == nullptr) {
      root_ = std::make_shared<LeafNode>(degree - 1, LEAF);
      return true;
    }

    std::shared_ptr<LeafNode> leaf = findLeaf(key);
    auto it = std::lower_bound(leaf->keys.begin(), leaf->keys.end(), key);
    int index = std::distance(leaf->keys.begin(), it);
    if (leaf->keys[index] == key) {
      printf("Key already exists\n");
      return 0;
    }
    leaf->keys.insert(it, key);
    leaf->values.insert(leaf->values.begin() + index, value);

    if (leaf->isOverflow()) {
      splitLeaf(leaf);
    }

    return 0;
  }

  char *search(int key) {
    std::shared_ptr<LeafNode> leaf = findLeaf(key);
    auto it = std::lower_bound(leaf->keys.begin(), leaf->keys.end(), key);
    int index = std::distance(leaf->keys.begin(), it);
    if (leaf->keys[index] == key) {
      return leaf->values[index];
    }
    return nullptr;
  }

  std::vector<char *> rangedSearch(int lowerKey, int higherKey) {
    std::vector<char *> result;
    std::shared_ptr<LeafNode> leaf = findLeaf(lowerKey);
    auto it = std::lower_bound(leaf->keys.begin(), leaf->keys.end(), lowerKey);
    int index = std::distance(leaf->keys.begin(), it);

    while (leaf != nullptr) {
      for (int i = index; i < leaf->keys.size(); i++) {
        int key = leaf->keys[i];
        if (key >= lowerKey && key <= higherKey) {
          result.push_back(leaf->values[i]);
        }

        if (key > higherKey)
          return result;
      }
      leaf = leaf->next;
    }

    return result;
  };
};

int main() {}
