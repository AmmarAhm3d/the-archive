#include<iostream>
using namespace std;

class DoublyLinkedList;
class Node {
	int data;
	Node* next, * prev;
	friend class DoublyLinkedList;
};

class DoublyLinkedList {
	Node* head;
public:
	DoublyLinkedList();
	~DoublyLinkedList();
	bool insertAtStart(int val);
	bool insertAtEnd(int val);
	bool sortedInsert(int val);
	bool deleteFromStart();
	bool deleteFromEnd();
	Node* search(int val);
	bool deleteSpecificValue(int value);
	void display();
};

DoublyLinkedList::DoublyLinkedList() {
    head = nullptr;
}

DoublyLinkedList::~DoublyLinkedList() {
    Node* curr = head;

    while (head != NULL) {
        head = curr->next;
        delete curr;
        curr = head;
    }
}

bool DoublyLinkedList::insertAtStart(int val) {
    Node* temp = new Node;
    temp->data = val;
    temp->prev = NULL;
    temp->next = head;
    head = temp;
    return 1;
}

bool DoublyLinkedList::deleteFromStart() {
    if (head == NULL)
        return 0;
    else {
        Node* curr = head;
        head = curr->next;
        delete curr;
        curr = 0;
        return 1;
    }
}

bool DoublyLinkedList::deleteFromEnd() {
    if (head == NULL) {
        cout << "list is empty" << endl;
        return 0;
    }
    else {

        Node* curr = head;
        while (curr->next != NULL) {
            curr = curr->next;

        }
        curr->prev->next = NULL;
        delete curr;
        curr = NULL;
        cout << "last block deleted:" << endl;
        return 1;
    }
}

bool DoublyLinkedList::insertAtEnd(int val) {
    Node* temp = new Node;
    temp->data = val;
    temp->next = NULL;
    temp->prev = NULL;
    Node* curr = head;

    while (curr->next != NULL) {

        curr = curr->next;

    }
    if (head == NULL) {
        head = temp;
        return 1;
    }
    else {
        curr->next = temp;
        temp->prev = curr;
        return 0;
    }
}

void DoublyLinkedList::display() {
    Node* curr = head;
    while (curr != NULL) {
        cout << curr->data << " ";
        curr = curr->next;
    }
    cout << endl;
}

Node *DoublyLinkedList::search(int val) {
    Node* curr = head;
    if (head == NULL) {
        cout << "List not populated" << endl;
        return 0;
    }
    else {
        while (curr != NULL) {
            if (curr->data == val) {
                return curr;
            }
            curr = curr->next;
        }
    }
}

bool DoublyLinkedList::deleteSpecificValue(int value){
       Node* curr = head;
		if (head == NULL) {
			cout << "not possible";
			return 0;
		}
		else {
			if (curr->next == NULL && curr->data == value) {
				return curr;
			}

			while (curr != NULL) {
				if (curr->data == value) {
					if (curr == head) {
						head = curr->next;
						delete curr;
						curr = 0;
						return 1;
					}
					curr->prev->next = curr->next;
					if (curr->next!=NULL) {
						curr->next->prev = curr->prev;
					}
					delete curr;
					curr = 0;
					return 1;
				}
				curr = curr->next;
			}
		}
	}
	
	bool DoublyLinkedList::sortedInsert(int val) {
		Node* temp = new Node;
		temp->data = val;
		temp->prev = NULL;
		Node* curr = head;
		
        if (head == NULL) {
            head = temp;
            temp->next = NULL;
            return 0;
        }

        if (head->data >= temp->data) {
            head->prev = temp;
            temp->next = head;
            return 1;
        }

        while (curr != NULL) {
            if (curr->data >= temp->data) {
                curr->prev->next = temp;
                temp->prev = curr->prev;
                curr->prev = temp;
                temp->next = curr;
                break;
            }
            else if (curr->next == NULL) {
                curr->next = temp;
                temp->prev = curr;
                break;
            }
            curr = curr->next;
        }



}


int main() {
	DoublyLinkedList l1;

    l1.sortedInsert(1);
    l1.sortedInsert(5);
    l1.sortedInsert(4);

    l1.display();
    return 0;
}
