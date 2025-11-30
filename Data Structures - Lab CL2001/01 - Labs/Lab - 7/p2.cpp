#include<iostream>
using namespace std;
class linklist;
class node
{
    friend class linklist;
    int data;
    node* next;
};
class linklist
{
    node* head;
    node* tail;
    bool check = 0;
    int count = 0;
    int* arr;
    int* arr1;

public:
    linklist()
    {
        head = 0;
        tail = 0;
    }
    void insertatstart(int n)
    {
        node* temp = new node;
        temp->data = n;
        temp->next = 0;
        if (head == 0)
        {
            head = temp;
            tail = temp;
        }
        else
        {
            temp->next = head;
            head = temp;

        }
    }
    void display()
    {
        node* curr = new node;
        curr = head;
        while (curr != 0)
        {
            cout << curr->data << " ";
            curr = curr->next;
        }

    }
    void checksize()
    {
        node* curr = new node;
        curr = head;
        while (curr != 0)
        {
            count++;
            curr = curr->next;
        }
        arr1 = new int[count];
        arr = new int[count];
    }
    void copyarray()
    {
        node* curr = new node;
        curr = head;
        int k = 0;
        int j = 0;

        while (curr != 0)
        {
            arr[k] = curr->data;
            k++;
            curr = curr->next;
        }
        curr = head;
        while (curr != 0)
        {
            arr1[j] = curr->data;
            j++;
            curr = curr->next;
        }
    }
    bool palindrome(int i, int j)
    {

        if (i < 5 && j>0)
        {
            if (arr[i] == arr[j])
            {

                palindrome(i + 1, j - 1);
                cout << "h";
                return 1;

            }
            else {
                return 0;

            }
        }
        else {
            return 0;
        }


    }



};
int main()
{
    int x;
    linklist l1;
    l1.insertatstart(1);
    l1.insertatstart(2);
    l1.insertatstart(3);
    l1.insertatstart(2);
    l1.insertatstart(1);
    l1.display();
    cout << endl;
    l1.checksize();
    l1.copyarray();
    cout << endl;
    cout<<l1.palindrome(0, 4);









    return 0;
}