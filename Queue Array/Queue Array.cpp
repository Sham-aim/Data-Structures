//Queue using Array
#include <iostream>
using namespace std;
template <typename T>
class Queue {
private:
	int elements;
	int capacity;
	T* array;
public:
	//cons
	Queue(int c) {
		elements = 0;
		capacity = c;
		array = new T[capacity];
	}
	bool isfull() {
		return capacity == elements;
	}
	void push(T v) {
		if (isfull()) return;
		array[elements] = v;
		elements++;
	}
	void pop() {
		if (elements == 0) return;
		for (int i = 0; i < elements; i++) {
			array[i] = array[i + 1];
		}
		elements--;

	}
	void print() {
		if (elements == 0) return;
		for (int i = 0; i < elements; i++) {
			cout << array[i] << " ";
		}
		cout << endl;
	}
};

int main() {
	Queue<int> q(5);

	q.push(1);
	q.push(2);
	q.push(3);

	q.print();

	q.pop();
	q.pop();
	q.print();

	q.push(4);
	q.push(5);
	q.push(6);
	q.print();


}

