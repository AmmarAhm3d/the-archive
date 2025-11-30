#include <iostream>
using namespace std;

// we implement fixed size here
static int SIZE=100;

class cqueue;
struct Node {
	friend class cqueue;
	int data;
	Node* next;
    Node(){
        next=NULL;
    }
};

class cqueue{
    Node* front;
    Node* rear;
    int currqsize;
public:
    cqueue(){
        front=rear=0;
        currqsize=0;
    }

    int size(){//O(constant)
        return currqsize;
    }

    bool isEmpty(){//O(1)
        return (front==NULL);
    }

    bool FRONT(int &e){//O(1)
        if(isEmpty())
            return false;
        else{
            e=front->data;
            return true;
        }
    }

    void dequeue(){//O(constant)
        if(isEmpty()){
            cout<<"Queue is empty, exiting\n";
        }
        else if(front==rear){
            delete front;
            front=rear=NULL;
            currqsize--;
        }
        else {
            Node *temp = front;
            front = front->next;
            rear->next = front;
            delete temp;
            currqsize--;
        }
     }

    void enqueue(int const& e) {//O(constant)
        if(size()==SIZE){
            cout<<"Queue is full, exiting\n";
        }
        else {
            Node *new_node = new Node;
            new_node->data = e;
            new_node->next= NULL;

            if (isEmpty()) {
                front = new_node;
                rear = new_node;
            }
            else
                rear->next = new_node;
            rear = new_node;
            rear->next = front;

            currqsize++;
        }
    }

    void disp(){//O(n)
        if(isEmpty())
            cout<<"Queue is empty, exiting";
        else{
            Node*temp=front;
            for(;temp->next!=front;temp=temp->next){
                cout<<" "<<temp->data;
            }
            cout<<" "<<temp->data<<"\n";
        }
    }
};


int main() 
{
    cqueue q;
    if(q.isEmpty())
        cout<<"E \n";
    q.enqueue(3);q.enqueue(5);q.enqueue(2);
    if(q.isEmpty())
        cout<<"E";
    q.enqueue(5);q.enqueue(6);
    q.disp();
    cout<<"Current size "<<q.size();
    int n=0;q.FRONT(n);
    cout<<"\nFRONT is "<<n<<"\n";
    q.enqueue(7);q.dequeue();q.dequeue();
    q.disp();
	return 0;
}