#include <iostream>
using namespace std;
template <typename T> class LinkedL;

template <typename T>
class Node {
    friend class LinkedL<T>;
private:
    T value;
    Node<T>* next;

public:
    Node(T v) : value(v), next(nullptr) {}
};

template <typename T>
class LinkedL {
private:
    Node<T>* head;

public:
    LinkedL() : head(nullptr) {}

    ~LinkedL() {
        Node<T>* current = head;
        while (current != nullptr) {
            Node<T>* next = current->next;
            delete current;
            current = next;
        }
        head = nullptr;
    }

    bool Empty() const {
        return head == nullptr;
    }

    void pushfront(T v) {
        Node<T>* new_node = new Node<T>(v);
        if (Empty()) {
            head = new_node;
        }
        else {
            new_node->next = head;
            head = new_node;
        }
    }
    void pushend(T v) {
        Node<T>* node = new Node<T>(v);
        if (Empty()) {
            head = node;
        }
        else {
            Node<T>* last = head;
            while (last->next != nullptr) {
                last = last->next;
            }
            last->next = node;
        }
    }
    void popfront() {
        if (Empty()) {
            return;
        }
        Node<T>* nn = head;
        head = head->next;
        delete nn;
    }

    void popend() {
        if (Empty()) {
            return;
        }
        else if (head->next == nullptr) {
            delete head;
            head = nullptr;
            return;
        }
        Node<T>* prev = head;
        while (prev->next->next != nullptr) {
            prev = prev->next;
        }
        Node<T>* last = prev->next;
        prev->next = nullptr;
        delete last;
    }

    int size() const{
        int list_size = 0;
        for (Node<T>* node = head; node != nullptr; node = node->next) {
            list_size++;
        }
        return list_size;
    }

    int count(T n) const {
        int count = 0;
        for (Node<T>* node = head; node != nullptr; node = node->next){
            if (node->value == n) count++;
    }
        return count;
    }
    void print() const {
        if (Empty()) {
            cout << "List is Empty" << endl;
            return;
        }
        for (Node<T>* node = head; node != nullptr; node = node->next) {
            cout << node->value << " ";
        }
        cout << endl;
    }
    void erase(T v) {
        if (Empty()) return;

        Node<T>* node = head;
        Node<T>* prev = nullptr;

        while (node != nullptr) {
            if (node->value == v) {
                Node<T>* temp = node;
                if (node == head) {
                    head = head->next;
                    node = head;
                }
                else {
                    prev->next = node->next;
                    node = node->next;
                }
                delete temp;
            }
            else {
                prev = node;
                node = node->next;
            }
        }
    }
};

int main() {

}
