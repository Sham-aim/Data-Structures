#include <iostream>
using namespace std;

class Node {
    friend class LinkedL;
private:
    int value;
    Node* next;
public:
    Node(int v) : value(v), next(nullptr) {}
    Node() : value(0), next(nullptr) {}
};

class LinkedL {
private:
    Node* head;
public:
    LinkedL() : head(nullptr) {}

    bool Empty() {
        return head == nullptr;
    }

    void pushfront(int v) {
        Node* new_node = new Node(v);
        new_node->next = head;
        head = new_node;
    }

    void popfront() {
        if (Empty()) return;
        Node* temp = head;
        head = head->next;
        delete temp;
    }

    int top() {
        if (Empty()) {
            cout << "List is empty!" << endl;
            return -1;
        }
        return head->value;
    }

    void print() {
        Node* current = head;
        while (current) {
            cout << current->value << " ";
            current = current->next;
        }
        cout << endl;
    }
};
class Stack {
private:
    LinkedL list;
public:
    bool isEmpty() {
        return list.Empty();
    }

    void push(int v) {
        list.pushfront(v);
    }

    void pop() {
        if (isEmpty()) {
            cout << "Stack Underflow!" << endl;
            return;
        }
        list.popfront();
    }

    int top() {
        return list.top();
    }

    void print() {
        list.print();
    }
};

int main() {
    Stack s;
}
