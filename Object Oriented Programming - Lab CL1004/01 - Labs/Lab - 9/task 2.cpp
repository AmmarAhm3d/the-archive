#include <iostream>
using namespace std;

class Faculty {
public:
    virtual void print() {
        cout << "Faculty class \n";
    }
};

class Administrator : public virtual Faculty {
public:
    void print() {
        cout << "Administrator class \n";
    }
};

class Teacher : public virtual Faculty {
public:
    void print() {
        cout << "Teacher class \n";
    }
};

class AdministratorTeacher : public Administrator, public Teacher {
public:
    void print() {
        cout << "AdministratorTeacher class \n";
    }
};

class Faculty;

int main()
{
    Faculty* fptr[3];

    Administrator adm;
    Teacher tea;
    AdministratorTeacher admtea;

    fptr[0] = new Administrator (adm);
    fptr[1] = new Teacher (tea);
    fptr[2] = new AdministratorTeacher (admtea);

    for (int i = 0; i < 3; i++) {
        fptr[i]->print();
    }


    
    return 0;
}