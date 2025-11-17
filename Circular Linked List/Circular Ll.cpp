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
    Node* tail; 

public:
    LinkedL() : head(nullptr), tail(nullptr) {}

    // Empty
    bool Empty() {
        return head == nullptr;
    }

    // Push Front
    void pushfront(int v) {
        Node* new_node = new Node(v);
        if (Empty()) {
            head = tail = new_node;
            new_node->next = new_node;
        }
        else {
            new_node->next = head;
            head = new_node;
            tail->next = head;
        }
    }

    // Push End
    void pushend(int v) {
        Node* node = new Node(v);
        if (Empty()) {
            head = tail = node;
            node->next = node;
        }
        else {
            tail->next = node;
            node->next = head;
            tail = node;
        }
    }

    // Pop Front
    void popfront() {
        if (Empty()) return;

        if (head == tail) {
            delete head;
            head = tail = nullptr;
            return;
        }

        Node* old = head;
        head = head->next;
        tail->next = head;
        delete old;
    }

    // Pop End
    void popend() {
        if (Empty()) return;

        if (head == tail) {
            delete head;
            head = tail = nullptr;
            return;
        }
        Node* prev = head;
        while (prev->next != tail) {
            prev = prev->next;
        }
        prev->next = head;
        delete tail;
        tail = prev;
    }
   
    int size() {
        if (Empty()) return 0;
        int cnt = 0;
        Node* cur = head;
        while (true) {
            ++cnt;
            cur = cur->next;
            if (cur == head) break;
        }
        return cnt;
    }

    int count(int n) {
        if (Empty()) return 0;
        int cnt = 0;
        Node* cur = head;
        while (true) {
            if (cur->value == n) ++cnt;
            cur = cur->next;
            if (cur == head) break;
        }
        return cnt;
    }

    void print() {
        if (Empty()) {
            cout << "List is Empty" << endl;
            return;
        }
        Node* cur = head;
        while (true) {
            cout << cur->value << endl;
            cur = cur->next;
            if (cur == head) break;
        }
    }
void erase(int v) {
    if (Empty()) return;
    Node* current = head;
    Node* prev = tail;

    while (true) {
        if (current->value == v) {
            if (current == head) {
                if (head == tail) {
                    delete head;
                    head = tail = nullptr;
                    return;
                }
                head = head->next;
                tail->next = head;
                delete current;
                current = head;
            }
            else {
                if (current == tail) {
                    tail = prev;
                }
                prev->next = current->next;
                delete current;
                current = prev->next;
            }
        }
        else {
            prev = current;
            current = current->next;
        }

        if (current == head) break;
    }
}


    void clear() {
        if (Empty()) return;
        while (!Empty()) popfront();
    }

    ~LinkedL() {
        clear();
    }
};

int main() {
    LinkedL list;

    list.pushfront(6);
    list.pushfront(7);
    list.pushfront(8);
    list.pushfront(6);
    list.pushfront(7);
    list.pushfront(8);

    cout << "Size: " << list.size() << endl;
    cout << "Count(0): " << list.count(0) << endl;


    return 0;
}

