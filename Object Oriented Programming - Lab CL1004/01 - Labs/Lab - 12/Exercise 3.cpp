#include <iostream>
using namespace std;

template<class T> class Container
{
    T data;
public:
    Container(char data){
        this->data=data;
    }
    Container(int data){
        this->data=data;
    }
    int increase(){
        return (++data);
    }

    char uppercase(){
        return (toupper(data));
    }

};

int main ()
{
    Container<int> myint (7);
    Container<char> mychar ('j');
    cout << myint.increase() << endl;
    cout << mychar.uppercase() << endl;
    return 0;
}