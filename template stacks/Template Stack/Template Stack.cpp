#include <iostream>
using namespace std;

template <typename T>
class Node {
public:
    T data;
    Node<T>* next;

    Node(T value) {
        data = value;
        next = nullptr;
    }
};

template <typename T>
class Stack {
private:
    Node<T>* head;

public:
    Stack() {
        head = nullptr;
    }

    bool isEmpty() {
        return head == nullptr;
    }

    void push(T value) {
        Node<T>* newNode = new Node<T>(value);
        newNode->next = head;
        head = newNode;
    }

    void pop() {
        if (isEmpty()) {
            cout << "Stack Underflow!\n";
            return;
        }

        Node<T>* temp = head;
        head = head->next;
        delete temp;
    }

    void display() {
        if (isEmpty()) {
            cout << "Stack is empty!\n";
            return;
        }
        cout << "Stack elements: ";
        Node<T>* current = head;
        while (current != nullptr) {
            cout << current->data << " ";
            current = current->next;
        }
        cout << endl;
    }
};

int main() {
    Stack<int> s;

    s.push(10);
    s.push(20);
    s.push(30);

    s.display();

    s.pop();
    s.display();

    return 0;
}
