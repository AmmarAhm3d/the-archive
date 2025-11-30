#include <iostream>
#include <vector>
#include <cassert>
using namespace std;

template <class v>
class HashMap
{
    //creating an sll class
    struct SLL {
        struct HashItem
        {
            v value;
            HashItem * next;
            HashItem(v val){ this->value=val; this->next=NULL;}

        };
        HashItem* head;
        int occupied;
        SLL(){head=NULL;occupied=0;}
        void insert(v val) {
            HashItem* n= new HashItem(val); //Creates a new Node next to the head, Remember that every old Node is a head to a new Node.
            if(head==NULL ) //if head is NULL then we assign the already created Node n as head.
            { head=n,occupied=1; return; }
            HashItem* temp=head; //Temp is a Node datatype pointer varaible which stores the address of the head.
            while(temp->next!=NULL)
                temp=temp->next; //It collects the next Node in the previous head.
            //Now we are at the last Node
            temp->next=n; //It links the new Node with the link list by giving the Node to the last Node next and the new Node is already consisting NULL at its next.
            occupied=1;
        }

        bool isempty(){
            return occupied==0;
        }
    };

    vector<SLL> hashVector;
    SLL* pSll;
    int currentElements;

public:
    HashMap(){
        currentElements = 0;
        this->hashVector.resize(10);
        pSll = new SLL[10];
    }
    HashMap(int const capacity){
        assert(capacity > 1);
        currentElements = 0;
        this->hashVector.resize(capacity);
        pSll = new SLL[capacity];
    }
    void insert(int const key, v const value){
        int size = hashVector.size();
        int index = key % size;
        if (hashVector[index].isempty()){	//insert a onesize ll
            pSll[index].insert(value);
            hashVector[index] = pSll[index];
            currentElements++;
            return;
        }
        else{	//is occupied
            pSll[index].insert(value);
            currentElements++;
            return;
        }

    }
    bool deleteKey(int const key) const{
        int size = hashVector.size();
        int index = key % size;
        if (!pSll[index].isempty()){
            pSll[index].occupied=1;
            return true;
        }
        else return false;
    }

    v* get(int const key) const {
        int size = hashVector.size();
        int index = key % size;
        if (pSll[index].isempty())return nullptr;
        else{
            // get node
            return &pSll[index].head->value;
        }
    }
    ~HashMap(){
        delete[] pSll;
        pSll = nullptr;
    }
};


int main(){
    HashMap<int> hm(10);
    hm.insert(1, 20);
    cout << *hm.get(1);


    system("pause");
}
