#include <iostream>
using namespace std;

class singlyLinkedList;
struct Node
{
	int data;
	Node* next;
	friend class singlyLinkedList;
};

class singlyLinkedList{
	Node* head;

public:
	singlyLinkedList(){
		head = nullptr;
	}

	//Insert at start 
	void insertAtHead(int const element){
		Node* new_node = new Node;
		new_node->data = element;
		new_node->next = head;
		head = new_node;
	}

	//Insert at end 
	void insertAtTail(int const element){
		Node* new_node = new Node;
		new_node->data = element;
		new_node->next = NULL;
		Node* prev = 0, *curr = head;
		while (curr!=NULL){
			prev = curr; curr = curr->next;
		}
		// if the element is first
		if (prev == 0){
			head = new_node;
		}
		else{
			prev->next = new_node; 
		}
	}

	//Print 
	void print() const{
		Node *curr = head;
		do{
			cout << curr->data << "->";
			curr = curr->next;
		} while (curr != NULL);
	}
	//Delete at Start 
	void eraseAtHead(){
		if (head == NULL)
			;
		else {
			Node *curr = head;
			head = curr->next;
			delete curr;
			curr = 0;
		}
	}
	//Delete at End 
	void eraseAtTail(){
		if (head == 0){
			cout << "List is empty\n";
		}
		else{
			Node* curr = head, *last = 0, *secondLast = 0;
			while (curr != NULL){
				secondLast = last;
				last = curr;
				curr = curr->next;
			}
			if (secondLast == 0){
				head = NULL;
				delete	last;
				last = 0;
			}
			else{
				secondLast->next = NULL;
				delete last;
				last = 0;
			}
		}
	}

	//Distructor
	~singlyLinkedList(){
		while (head!=NULL){
			Node* curr = head;
			head = curr->next;
			delete curr;
			curr = head;
		}
	}

};

int main()
{
	singlyLinkedList l;
		//b.Insert 2, 6, 7 at start
	l.insertAtHead(2); l.insertAtHead(6); l.insertAtHead(7);
		//c.Insert 3, 8, 1 at End
	l.insertAtTail(3); l.insertAtTail(8); l.insertAtTail(1);
		//d.Delete at Start
	l.eraseAtHead();
		//e.Delete at End
	l.eraseAtTail();
		//f.Now print the linked list. (Sample answer 6->2->3->8)
	l.print();

	system("pause");
}