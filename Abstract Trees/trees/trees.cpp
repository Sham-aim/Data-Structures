#include <iostream>
#include <list>
#include <algorithm>
using namespace std;

template <typename Type>
class Simple_tree {
private:
    Type node_value;
    Simple_tree* parent_node;
    list<Simple_tree*> children;

public:
    Simple_tree(Type const& obj, Simple_tree* p=nullptr) :
        node_value(obj),
        parent_node(p) {
    }

    Type value() const {
        return node_value;
    }

    Simple_tree* parent() const {
        return parent_node;
    }

    int degree() const {
        return children.size();
    }

    bool is_root() const {
        return (parent() == nullptr);
    }

    bool is_leaf() const {
        return (degree() == 0);
    }

        Simple_tree* child(int n) const {
            if (n < 0 || n >= degree()) {
                return nullptr;
            }

            auto it = children.begin();
            advance(it, n);
            return *it;
        }
    

    int size() const {
        int tree_size = 1;
        for (auto child : children) {
            tree_size += child->size();
        }
        return tree_size;
    }

    int height() const {
        int max_child_height = -1;
        for (auto child : children) {
            max_child_height = max(max_child_height, child->height());
        }
        return 1 + max_child_height;
    }

    void insert(Type const& obj) {
        children.push_back(new Simple_tree(obj, this));
    }

    void detach() {
        if (is_root()) {
            return;
        }

        auto& siblings = parent_node->children;
        siblings.remove(this);
        parent_node = nullptr;
    }

    void attach(Simple_tree<Type>* tree) {
        if (tree == nullptr) return;

        if (!tree->is_root()) {
            tree->detach();
        }

        tree->parent_node = this;
        children.push_back(tree);
    }

    ~Simple_tree() {
        for (auto child : children) {
            delete child;
        }
    }
};

int main() {
   
        Simple_tree<int> root(1);
        root.insert(2);
        root.insert(3);
        Simple_tree<int>* child1 = root.child(0);
        if (child1) {
            child1->insert(4);
            child1->insert(5);
        }
        Simple_tree<int>* child2 = root.child(1);
        if (child2) {
            child2->insert(6);
            child2->insert(7);
        }

        cout << "Root value: " << root.value() << endl;
        cout << "Root degree: " << root.degree() << endl;
        cout << "Tree size: " << root.size() << endl;
        cout << "Tree height: " << root.height() << endl;

        return 0;
    }
