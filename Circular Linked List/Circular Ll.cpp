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
            new_node->next = new_node; // circular link to itself
        }
        else {
            new_node->next = head;
            head = new_node;
            tail->next = head; // maintain circular link
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

        if (head == tail) { // single node
            delete head;
            head = tail = nullptr;
            return;
        }

        Node* old = head;
        head = head->next;
        tail->next = head; // keep circular
        delete old;
    }

    // Pop End
    void popend() {
        if (Empty()) return;

        if (head == tail) { // single node
            delete head;
            head = tail = nullptr;
            return;
        }

        // find node before tail
        Node* prev = head;
        while (prev->next != tail) {
            prev = prev->next;
        }
        prev->next = head;
        delete tail;
        tail = prev;
    }
    // Size Function
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

    // Count Function
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

    // Printing Function
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
        bool started = false;

        // loop until we've gone full circle (watch for head changes and emptying)
        while (!Empty() && (!started || current != head)) {
            started = true;
            Node* next = current->next;

            if (current->value == v) {
                // single-node list
                if (current == head && current == tail) {
                    delete current;
                    head = tail = nullptr;
                    return; // list empty now
                }
                // removing head
                else if (current == head) {
                    head = next;
                    tail->next = head;
                    delete current;
                    current = next;
                    // prev stays as tail
                }
                // removing tail
                else if (current == tail) {
                    prev->next = next; // next == head
                    delete current;
                    tail = prev;
                    current = next;
                }
                // removing middle node
                else {
                    prev->next = next;
                    delete current;
                    current = next;
                    // prev stays the same
                }
            }
            else {
                // not deleting: advance prev and current
                prev = current;
                current = next;
            }

            // if list became empty during deletions, break
            if (head == nullptr) break;
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

    cout << "Contents:" << endl;
    list.print();

    cout << "--- erase 8 ---" << endl;
    list.erase(8);
    list.print();
    cout << "Size after erase: " << list.size() << endl;

    return 0;
}

