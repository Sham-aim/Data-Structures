#include <iostream>
#include <string>
using namespace std;
struct Node {
    string data;
    Node* next;
    Node(string val) {
        data = val;
        next = nullptr;
    }
};
class LinkedListStack {
private:
    Node* head; 
public:
    LinkedListStack() {
        head = nullptr;
    }
    ~LinkedListStack() {
        clear();
    }
    void push(string data) {
        Node* newNode = new Node(data);
        newNode->next = head;
        head = newNode;
    }
    void pop() {
        if (empty()) {
            return;
        }
        Node* temp = head;
        head = head->next;
        delete temp;
    }
    string top() { 
        if (empty()) {
            return "";
        }
        return head->data;
    }
    bool empty() {
        return (head == nullptr);
    }
    void clear() {
        while (!empty()) {
            pop();
        }
    }
};

LinkedListStack backStack;
LinkedListStack forwardStack;
string currentPage;
void visitPage(string pageName) {
    if (!currentPage.empty()) {
        backStack.push(currentPage);
    }
    currentPage = pageName;
    forwardStack.clear();
}

void clickBack(){
    if (backStack.empty()) {
        return;
    }
    forwardStack.push(currentPage);
    currentPage = backStack.top();
    backStack.pop();
}

void clickForward() {
    if (forwardStack.empty()) {
        return;
    }
    backStack.push(currentPage);
    currentPage = forwardStack.top();
    forwardStack.pop();
}


int main() {
    visitPage("page1.html");
    visitPage("page2.html");
    visitPage("page3.html");
    clickBack();
    clickBack();
    clickBack();
    clickForward();
    clickForward();
    clickForward();
    return 0;
}