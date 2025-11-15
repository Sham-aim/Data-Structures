#include<iostream>
using namespace std;
class Node {
	friend class DoublyLL;
private:
	int value;
	Node* next;
	Node* prev;
public:
	Node(int n):value(n), next(nullptr), prev(nullptr){}
	Node():value(NULL), next(nullptr), prev(nullptr) {}
};
class DoublyLL {
private:
	Node* head;
	Node* tail;
public:
	DoublyLL():head(nullptr), tail(nullptr){}
	//Empty
	bool Empty() {
		return head == nullptr;
	}
	//Push Front
	void pushfront(int n) {
		Node* node = new Node(n);
		if (Empty()) {
			head =tail= node;
	}
		else {
			head->prev = node;
			node->next = head;
			head = node;
		}
	}
	//Push Back
	void pushback(int n) {
		Node* node = new Node(n);
		if (Empty()) {
			head= tail = node;
		}
		else {
			tail->next = node;
			node->prev = tail;
			tail = node;
		}
	}
	//Insert in Middle
	void insert(int n, int i) {
		if (Empty()) {
			cout << "Already Empty" << endl;
			return;
		}
		int index = 0;
		Node* node = new Node(n);
		for (Node* current = head; current != nullptr; current=current->next) {
			if (index == i) {
				node->next = current->next;
				node->prev = current;
				current->next->prev = node;
				current->next = node;
				return;

			}
			
			index++;
	

		}
	}
	//Print
	void print() {
		if (Empty()) cout << "Empty List" << endl;
		for (Node* current = head; current != nullptr; current = current->next) {
			cout << current->value << " ";
		}
		cout << endl;
	}
	//Pop End
	void popend() {
		if (Empty()) {
			cout << "Already Empty" << endl;
			return;
		}
		if (head == tail) {
			delete head;
			head = tail = nullptr;
			return;
		}
		Node* old = tail;
		tail = tail->prev;
		tail->next = nullptr;
		delete old;
	}
	//Pop Front
	void popfront() {
		if (Empty()) {
			cout << "Already Empty" << endl;
			return;
		}
		if (head == tail) {
			delete head;
			head = tail = nullptr;
			return;
		}
		Node* old = head;
		head = head->next;
		head->prev = nullptr;
		delete old;
	}
	//Erase
	void erase(int n) {
		if (Empty()) {
			cout << "Already Empty" << endl;
			return;
		}
		for (Node* current = head; current != nullptr; ) {
			Node* temp = current->next;
			if (current->value == n) {
				if (current == head && current == tail) {
					delete current;
					head = tail = nullptr;
					
				}
				else if (current == head) {
					head = head->next;
					head->prev = nullptr;
					delete current;
				}
				else if (current == tail) {
					tail = tail->prev;
					tail->next = nullptr;
					delete current;
				}
				else {
					current->next->prev = current->prev;
					current->prev->next = current->next;
					delete current;
				}
			}

			current = temp;
		}
	}

};

	int main() {
		DoublyLL list;
		list.print();
		list.pushfront(7);
		list.pushfront(9);
		list.pushfront(11);
		list.pushfront(13);
		list.print();
		list.insert(15, 2);
		list.print();
	}