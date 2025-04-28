#include <iostream>
using namespace std;

struct node {
	int data;
	node* next;
	node* prev;
};

class DoubleLinkedCycle {
private:
	node* head;
	node* tail;
public:
	DoubleLinkedCycle() {
		head = nullptr;
		tail = nullptr;
	}

	int size() {
		if (isEmpty) {
			return 0;
		}
		else if (head == tail) {
			return 1;
		}
		else {
			node* temp = head;
			int size = 1;
			while (temp != tail) {
				temp = temp->next;
				size++;
			}
			return size;
		}
	}

	void addNodeStart(int value) {
		node* temp = new node;
		temp->data = value;
		temp->next = head;
		temp->prev = tail;
		if (head == nullptr) {
			head = temp;
			tail = temp;
		}
		else {
			head = temp;
		}
	}

	void addNodeEnd(int value) {
		node* temp = new node;
		temp->data = value;
		temp->next = head;
		temp->prev = tail;
		if (head == nullptr) {
			head = temp;
			tail = temp;
		}
		else {
			tail->next = temp;
			tail = temp;
		}
	}

	void addNodePos(int value, int pos) {
		node* temp = new node;
		temp->data = value;
		if (head == nullptr) {
			head = temp;
			tail = temp;
			temp->next = head;
			temp->prev = tail;
		}
		else {

		}

	}


	void deleteNodeStart() {
		if (isEmpty()) {
			cout << "TUSCIAS delete start" << endl;
		}
		else {
			node* temp = head;
			if (head == tail) {
				head = nullptr;
				tail = nullptr;
			}
			else {
				head = head->next;
				head->prev = tail;
			}
			delete temp;
		}
	}

	void deleteNodeEnd() {
		if (isEmpty()) {
			cout << "TUSCIAS delete end" << endl;
		}
		else {
			node* temp = tail;
			if (head == tail) {
				head = nullptr;
				tail = nullptr;
			}
			else {
				tail = tail->prev;
				tail->next = head;
			}
			delete temp;
		}
	}

	void deleteNodePosition() {
	
	}

	bool isEmpty() {
		return (head == nullptr && tail == nullptr);
	}

	void display() {
		if (isEmpty()) {
			cout << "TUSCIAS display" << endl;
		}
		else {
			node* temp = head;
			cout << temp->data << " ";
			temp = temp->next;
			while (temp != head) {
				cout << temp->data << " ";
				temp = temp->next;
			}
			cout << endl;
		}
	}
	void reverse() {}
};

int main() {
	DoubleLinkedCycle ciklas;

	ciklas.addNodeStart(1);
	ciklas.addNodeStart(2);
	ciklas.addNodeStart(3);
	ciklas.addNodeStart(4);
	ciklas.display();
	cout << ciklas.size();

	ciklas.deleteNodeEnd();
	ciklas.deleteNodeEnd();
	ciklas.deleteNodeStart();
	ciklas.deleteNodeStart();

	ciklas.addNodeEnd(1);
	ciklas.addNodeEnd(2);
	ciklas.addNodeEnd(3);
	ciklas.addNodeEnd(4);
	ciklas.display();


	return 0;
}