#include <iostream>
#include <algorithm>
#include <queue>      
#include <stack>      
using namespace std;
template <typename T> class BinaryTree;

template <typename T>
class BinaryNode {
    friend class BinaryTree<T>;
private:
    T element;
    BinaryNode<T>* left;
    BinaryNode<T>* right;

public:
    BinaryNode(const T& data, BinaryNode<T>* l = nullptr, BinaryNode<T>* r = nullptr)
        : element(data), left(l), right(r) {
    }

    T retrieve() const { return element; }
    BinaryNode<T>* leftChild() const { return left; }
    BinaryNode<T>* rightChild() const { return right; }

    int size() const {
        return 1 + (left ? left->size() : 0) + (right ? right->size() : 0);
    }

    int height() const {
        int leftHeight = left ? left->height() : -1;
        int rightHeight = right ? right->height() : -1;
        return 1 + max(leftHeight, rightHeight);
    }
    void printPreorder() const {
        cout << element << " ";
        if (left) left->printPreorder();
        if (right) right->printPreorder();
    }

    void printInorder() const {
        if (left) left->printInorder();
        cout << element << " ";
        if (right) right->printInorder();
    }

    void printPostorder() const {
        if (left) left->printPostorder();
        if (right) right->printPostorder();
        cout << element << " ";
    }

    void clear() {
        if (left) { left->clear(); delete left; left = nullptr; }
        if (right) { right->clear(); delete right; right = nullptr; }
    }
};

template <typename T>
class BinaryTree {
private:
    BinaryNode<T>* root;

public:
    BinaryTree() : root(nullptr) {}
    ~BinaryTree() { clear(); }

    void insert(const T& data) {
        if (root == nullptr) {
            root = new BinaryNode<T>(data);
            return;
        }

        BinaryNode<T>* current = root;
        while (true) {
            if (data < current->element) {
                if (current->left == nullptr) {
                    current->left = new BinaryNode<T>(data);
                    break;
                }
                current = current->left;
            }
            else if (data > current->element) {
                if (current->right == nullptr) {
                    current->right = new BinaryNode<T>(data);
                    break;
                }
                current = current->right;
            }
            else {
                break;
            }
        }
    }

    void clear() {
        if (root) {
            root->clear();
            delete root;
            root = nullptr;
        }
    }

    int size() const { return root ? root->size() : 0; }
    int height() const { return root ? root->height() : -1; }
    bool empty() const { return root == nullptr; }

    void printPreorder() {
        cout << "Recursive Preorder:  ";
        if (root) root->printPreorder();
        cout << endl;
    }

    void printInorder() {
        cout << "Recursive Inorder:   ";
        if (root) root->printInorder();
        cout << endl;
    }

    void printPostorder() {
        cout << "Recursive Postorder: ";
        if (root) root->printPostorder();
        cout << endl;
    }

    void BFS() {
        if (root == nullptr) return;
        queue<BinaryNode<T>*> q;
        q.push(root);

        cout << "Iterative BFS:       ";
        while (!q.empty()) {
            BinaryNode<T>* current = q.front();
            q.pop();

            cout << current->element << " "; // Friend access allows this

            if (current->left != nullptr) q.push(current->left);
            if (current->right != nullptr) q.push(current->right);
        }
        cout << endl;
    }

    void DFS() {
        if (root == nullptr) return;
        stack<BinaryNode<T>*> s;
        s.push(root);

        cout << "Iterative DFS:       ";
        while (!s.empty()) {
            BinaryNode<T>* current = s.top();
            s.pop();

            cout << current->element << " ";

            if (current->right != nullptr) s.push(current->right);
            if (current->left != nullptr) s.push(current->left);
        }
        cout << endl;
    }
};

int main() {
    BinaryTree<int> tree;

    // 

    cout << "--- Building Tree ---" << endl;
    tree.insert(50);
    tree.insert(30);
    tree.insert(70);
    tree.insert(20);
    tree.insert(40);
    tree.insert(60);
    tree.insert(80);

    cout << "Tree Size:   " << tree.size() << endl;
    cout << "Tree Height: " << tree.height() << endl;
    cout << "---------------------" << endl;

    tree.printPreorder();
    tree.printInorder();
    tree.printPostorder();

    cout << "---------------------" << endl;

    tree.BFS();
    tree.DFS();

    return 0;
}