#include <iostream>
using namespace std;
template <typename T> class Queue;
template <typename T>
class Node {
private:
	T value;
	Node<T>* next;
public:
	Node(T v) {
		value =v;
		next = nullptr;
	}
	friend class Queue<T>;
};
template <typename T>
class Queue {
private:
	Node<T>* head=nullptr;
	Node<T>* tail = nullptr;
public:
	bool empty() {
		return(head == nullptr);
	}
	void push(T v) {
		Node<T>* nn = new Node<T>(v);
		if (empty()) {
			head = nn;
			tail = nn;
		}
		else {
			tail->next = nn;
			tail = nn;

		}
	}
	void pop() {
		if (empty()) return;
		else {
			Node<T>* temp = head;
			head = head->next;
			delete temp;
		}
	}
	T front() {
		if (empty()) {
			throw runtime_error("Queue is empty");
		}
		return head->value;
	}
	void print() {
		for (Node<T>* curr = head; curr != nullptr; curr = curr->next) {
			cout << curr->value<<" ";
		}
		cout << endl;
	}


};

int main() {
	Queue<int> obj;
	obj.front();//calls a runtime library
	obj.push(1);
	obj.push(1);
	obj.push(1);
	obj.push(1);
	obj.print();


}
