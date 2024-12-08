#include <vector>
#include <memory>
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

    BaseNode(int max_size_, PageType type_) : max_size(max_size_), type(type_) {}

    bool isLeaf() { return type == PageType::LEAF; }

    virtual ~BaseNode() {};
};

class InternalNode : public BaseNode
{
public:
    std::vector<int> keys;
    std::vector<int> children;
};

class BPlusTree
{
private:
    std::shared_ptr<BaseNode> root_;
    std::size_t degree;
};

int main() {}