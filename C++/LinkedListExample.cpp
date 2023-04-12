//John Bae\
/*The purpose of this program is to create and demonstrate a singly-linked list class.*/

#include <iostream>

using namespace std;

class LinkedList {
public:


	class Index {
	public:
		int data;
		Index* next;
		
	};

	Index* head = nullptr;
	

	void append(int x) {
		Index* newIndex, *indexPtr = nullptr;

		newIndex = new Index;
		newIndex->data = x;
		newIndex->next = nullptr;
		if (!head) {
			head = newIndex;
		}
		else {
			indexPtr = head;

			while (indexPtr->next) {
				indexPtr = indexPtr->next;
			}

			indexPtr->next = newIndex;
		}
	}
	void print() {
		Index* indexPtr = nullptr;

		indexPtr = head;
		while (indexPtr) {
			cout << indexPtr->data << endl;
			indexPtr = indexPtr->next;
		}
	}
	void insert(int x) {
		Index* newIndex, *indexPtr, *prevIndex = nullptr;

		newIndex = new Index;
		newIndex->data = x;

		if (!head) {
			head = newIndex;
			newIndex->next = nullptr;
		}
		else {
			indexPtr = head;
			prevIndex = nullptr;
			while (indexPtr != nullptr && indexPtr->data < x) {
				prevIndex = indexPtr;
				indexPtr = indexPtr->next;
			}
			if (!prevIndex) {
				head = newIndex;
				newIndex->next = indexPtr;
			}
			else {
				prevIndex->next = newIndex;
				newIndex->next = indexPtr;
			}
		}
	}
	void remove(int x) {
		Index* indexPtr, * prevIndex = nullptr;

		if (!head) {
			return;
		}
		else {
			indexPtr = head;
			while (indexPtr != nullptr && indexPtr->data != x) {
				prevIndex = indexPtr;
				indexPtr = indexPtr->next;
			}
			if (indexPtr) {
				prevIndex->next = indexPtr->next;
				delete indexPtr;
			}
		}
	}
	void destroy() {
		Index* indexPtr, * nextIndex = nullptr;

		indexPtr = head;
		while (indexPtr != nullptr) {
			nextIndex = indexPtr->next;
			delete indexPtr;
			indexPtr = nextIndex;
		}
	}
	
	
	


};










int main() {

  LinkedList list;
  for(int i = 1;i < 11;i++){
    if(i != 5){
    list.append(i);
    } 
  }

  cout << "Initial Values: " << endl;
  list.print();
  cout << endl;

  list.insert(5);

  cout<< "After insterting 5: " << endl;
  list.print();

  list.remove(3);
  list.remove(8);

  cout << endl << "After removing 3 and 8: " << endl;

  list.print();

  list.append(3);
  list.append(8);
  list.remove(4);

  cout << endl << "After adding 3 and 8 back on the end, then removing 4: " << endl;

  list.print();

  list.destroy();


	return 0;
}