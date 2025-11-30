#include <iostream>
using namespace std;

class Stack;
struct Node {
    friend class Stack;
    int data;
    Node* next;
};

class Stack {
    Node *top;
    int size;

public:
    Stack() {
        top = 0;
        size = 0;
    }

    int SIZE() {//O(1)
        return size;
    }

    bool isEmpty() {//O(1)
        return !top;
    }

    bool TOP(int&arg) {//O(1)
        if (top == 0)
            return false;
        else {
            arg=top->data;
            return true;
        }
    }

    void display() {//O(n)
        Node *ptr = top;
        if (top == 0)cout << "Empty Stack";
        else {
            while (ptr != NULL) {
                cout << ptr->data << " ";
                ptr = ptr->next;
            }
            cout<<"\n";
        }
    }

    void pop() {//O(1)
        if (top) {
            Node *tmp(top);
            top = top->next;
            delete tmp;
            size--;
        } else
            cout << "Stack is Empty " << endl;
    }

    void push(int e) {//O(1)

        if (top == 0) {
            Node *new_node = new Node;
            new_node->data = e;
            top = new_node;
            top->next = 0;
        } else {
            Node *node = new Node;
            node->data = e;
            node->next = top;
            top = node;
        }
        size++;
    }

    void sort() {//O(n^2)
        Node *index1, *index2;
        for (index1 = top; index1->next != NULL; index1 = index1->next) {
            for (index2 = index1->next; index2 != NULL; index2 = index2->next) {
                if (index1->data > index2->data) {
                    int temp = index1->data;
                    index1->data = index2->data;
                    index2->data = temp;
                }
            }
        }

    }

    bool delMid() {//O(n)
        // case of empty stack
        if (top == 0)
            return false;
        // case of single stack
        if (top->next == 0 ||size==1) {
            cout<<"Single stack deletion not possible, exiting";
            return false;
        }

        int s = size / 2;

        // case of odd size
        if (s % 2 != 0) {
            cout << "no mid value, exiting\n";
            return false;
        }
        else {
            Node*curr=top;
            Node*prev=curr;
            for(int i=0;i<s;i++,curr=curr->next){
                prev=curr;
            }
            prev->next=curr->next;
            delete curr;
            curr=0;
            return true;
        }
    }

    bool isPalindrome(){//O(n/2)
        int s=size;
        if(s%2==0){
            cout<<"No palindrome exists\n";
            return false;
        }
        else{
            /*Our logic is to equate lhs and rhs of stack,
             * works on odd size only*/

            s/=2;

            int i=0,sumLHS=0;
            Node*curr=top;

            for(;i<s;i++,curr=curr->next)
                sumLHS+=curr->data;
            // hop to rhs
            curr=curr->next;
            int sumRHS=0;

            for(;i<size-1;i++,curr=curr->next)
                sumRHS+=curr->data;

            if(sumLHS==sumRHS){
                cout<<"is palindrome\n";
                return true;
            }
            else
                cout<<"not palindrome\n";
            return false;

        }
    }

    void sumforK(int k){//O(n^2)
        if(!isEmpty()){
            Node*curr=  top;

            for(;curr!=NULL;curr=curr->next){
                Node*temp=top->next;
                for(;temp!=NULL;temp=temp->next)
                    if((curr->data)+(temp->data)==k)
                        cout<<"("<<curr->data<<","<<temp->data<<")\n";
            }

        }
    }
};

int main()
{
    Stack s;
    s.push(1);
    s.push(2);
    s.push(3);
    s.push(2);
    s.push(1);
    s.display();
    s.isPalindrome();
    s.sumforK(5);
    cout<<"\nCurrent size is "<<s.SIZE()<<"\n";
    s.delMid();
    s.display();


    return 0;
}