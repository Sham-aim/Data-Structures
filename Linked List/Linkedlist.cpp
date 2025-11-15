#include <iostream>
using namespace std;
class Node {
	friend class LinkedL;
private:
	int value;
	Node * next;
public:
	Node(int v) :value(v), next(nullptr) {};
	Node() :value(NULL), next(nullptr) {};
	
};
class LinkedL {
private:
	Node* head;
public:
	//Constructor
	LinkedL() :head(nullptr) {};
	//Empty
	bool Empty() {
		return head == nullptr;
	}
	//Push Front
	void pushfront(int v) {
		Node* new_node = new Node(v);
		if (Empty()) {
			head = new_node;
		}
		else {
			new_node->next = head;
			head = new_node;
		}
	}
	//Push End
	void pushend(int v) {
		Node* node = new Node(v);
		if (Empty()) {
			head = node;
		}
		else {
			Node* last=head;
			for (Node* current = head; current != nullptr; current = current->next) {
				last = current;
			}
			last->next= node;
		}
	}
	//Pop Front
	void popfront(){
		if (Empty()) {
			return;
		}
		Node* old = head;
		head = head->next;
		delete old;
	}
	//Pop End
	void popend() {
		if (Empty()) {
			return;
		}
		else if(head->next == nullptr) {
			delete head;
			head = nullptr;
			return;
		}
		Node* prev = head;
		while (prev->next->next != nullptr) {
			prev = prev->next;
		}
		Node* last = prev->next;
		prev->next = nullptr;
		delete last;
	}
	//Size Function
	int size() {
		int size = 0;
		if (Empty()) return size;
		for (Node* node = head; node != nullptr; node = node->next) {
			size++;
		}
		return size;
	}
	//Count Function
	int count(int n) {
		int count = 0;
		if (Empty()) return 0;

		for (Node* node = head; node != nullptr; node = node->next) {
			if (node->value == n) count++;
		}
		return count;
	}
	//Printing Function
	void print() {
		if (Empty()) cout << "List is Empty" << endl;
		for (Node* node = head; node != nullptr; node = node->next) {
			cout << node->value<<endl;
		}
	}
	//Erase
	void erase(int v) {
		if (Empty()) return;

		Node* node = head;
		Node* prev = nullptr;

		while (node != nullptr) {
			if (node->value == v) {
				Node* temp = node;
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

int main(){
	LinkedL list;
	
	list.pushfront(6);
	list.pushfront(7);
	list.pushfront(8);
	list.pushfront(6);
	list.pushfront(7);
	list.pushfront(8);
	cout << list.size() << endl;
	cout << list.count(0) << endl;
	
	
}