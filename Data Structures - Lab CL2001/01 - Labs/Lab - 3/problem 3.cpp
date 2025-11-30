#include<iostream>
using namespace std;

template<class T>
class DoublyLinkedList;

template <class T>
class Node {
    T data;
    Node<T>* next;
    Node<T>* prev;
    friend class DoublyLinkedList<T>;
public:
    Node<T>() {
        this->next = NULL, this->prev = NULL;
    }
};

template<class T>
class DoublyLinkedList {
    Node<T>* head;
public:
    DoublyLinkedList(){
        this->head = NULL;
    }

    ~DoublyLinkedList(){
        if(head)
        {
            Node<T> *tmp = head;
            while(tmp->next != head)
            {
                Node<T> *t = tmp;
                tmp = tmp->next;
                delete t;
            }
            delete tmp;
            head = nullptr;
        }
    }

    bool insertAtHead(T const element) {
        Node<T>* new_node = new Node<T>;
        Node<T>* curr = head;
        new_node->data = element;
        new_node->next = head;
        new_node->prev = NULL;
        head = new_node;
        while (curr->next != NULL)
            curr = curr->next;

        head->prev = curr;
        curr->next = head;
        return 1;
    }

    bool insertAtTail(T const element){
        Node<T>* new_node = new Node<T>;
        new_node->data = element;
        new_node->next = NULL;
        new_node->prev = NULL;
        Node<T>* curr = head;

        while (curr->next != NULL)
            curr = curr->next;

        if (head == NULL) {
            head = new_node;
            return 1;
        }
        else {
            curr->next = new_node;
            new_node->prev = curr;
            new_node->next = head;
            head->prev = new_node;
            return 0;
        }
    }

    void print() const{
        if (head == NULL) {
            cout << "List is empty..\n";
            return;
        }
        else{
            Node<T>* temp = head;
            while (temp->next!=head){
                cout<<temp->data<<" ";
                temp= temp->next;
            }

        }
    }

    bool isCircular(){
        if(head==NULL)return 1;
        else{
            Node<T>*curr = head->next;
            while (curr != NULL && curr != head){
                curr=curr->next;
            }
            if(curr==head)
                return 0;
        }
    }

    bool deleteAtStart(){

        if (head ==NULL) {
            cout << "Empty list deletion not possible\n";
            return 1;
        }
        Node<T>* curr = head;
        head = curr->next;
        delete curr;
        curr = NULL;
        return 0;
    }

    bool deleteAtTail(){
        if (head ==NULL) {
            cout << "Empty list deletion is not possible\n";
            return 1;
        }
        Node<T>* ptr=head;
        while (ptr->next != NULL)
            ptr=ptr->next;
        ptr->prev->next=NULL;
        delete ptr;
        ptr=NULL;
        cout<<"Last block deleted: ";
        return 0;
    }

};

int main() {
    DoublyLinkedList <int>l1;
    l1.insertAtTail(1);
    l1.print();

    if(l1.isCircular())
        cout<<"Is Circular";
    

    return 0;
}
