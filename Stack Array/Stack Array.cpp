#include <iostream>
using namespace std;

class Stack {
private:
    int* arr;      
    int capacity;  
    int size;       

public:
   
    Stack(int cap) {
        capacity = cap;
        arr = new int[capacity];
        size = 0;
    }
    ~Stack() {
        delete[] arr;
    }

    bool isEmpty() {
        return size == 0;
    }

    bool isFull() {
        return size == capacity;
    }

    void push(int value) {
        if (isFull()) {
            cout << "Stack Overflow!" << endl;
            return;
        }
        arr[size] = value;
        size++;
    }
    void pop() {
        if (isEmpty()) {
            cout << "Stack Underflow!" << endl;
            return;
        }
        size--;
    }
    int top() {
        if (isEmpty()) {
            cout << "Stack is empty!" << endl;
            return -1;
        }
        return arr[size - 1];
    }



 
};

int main() {
}
