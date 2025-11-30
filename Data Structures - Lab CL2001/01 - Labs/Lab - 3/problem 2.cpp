#include<iostream>
using namespace std;

template<class T>
class DoublyLinkedList;

template <class T>
class Node {
    T data=NULL;
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
        this->head = nullptr;
    }
    ~DoublyLinkedList(){
        Node<T>* curr = head;

        while (head != NULL) {
            head = curr->next;
            delete curr;
            curr = head;
        }
    }
    bool insertAtStart(T const element){
        Node<T>* temp = new Node<T>;
        temp->data = element;
        temp->prev = NULL;
        temp->next = head;
        head = temp;
        return 1;
    }
    bool insertAtEnd(T const element){
        Node<T>* temp = new Node<T>;
        temp->data = element;
        temp->next = NULL;
        temp->prev = NULL;
        Node<T>* curr = head;

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
    bool deleteFromStart(){
        if (head == NULL)
            return 0;
        else {
            Node<T>* curr = head;
            head = curr->next;
            delete curr;
            curr = 0;
            return 1;
        }
    }
    bool deleteFromEnd(){
        if (head == NULL) {
            cout << "list is empty" << endl;
            return 0;
        }
        else {

            Node<T>* curr = head;
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
    void print() const{
        Node<T>* curr = head;
        while (curr != NULL) {
            cout << curr->data << " ";
            curr = curr->next;
        }
        cout << endl;
    }

    void printReverse() const {
        Node<T>* last = NULL;
        Node<T>* curr = head;
        while (curr != NULL)
        {
            last = curr;
            curr = curr->next;
        }
        cout << "Data in Reverese direction\n";
        while (last != NULL)
        {
            cout << last->data << "->";
            last = last->prev;
        }
    }
};

int main() {
    DoublyLinkedList <int>l1;
    l1.insertAtEnd(1);
    l1.insertAtEnd(2);
    l1.print();
    l1.printReverse();

    return 0;
}
