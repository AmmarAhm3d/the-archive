#include <iostream>
using namespace std;

//Your task is to design a class for Student.You must take any 5 necessary data members as Roll No, Name, CNIC, Degreeand Address.Now implement all the required functions i.e.getters, setters, print function.

class Student {
	string Roll_No, Name, CNIC, Degree, Address;
public:
	void setRoll_No(string in) {
		Roll_No = in;
	}
	void setName(string in) {
		Name = in;
	}
	void setCNIC(string in) {
		CNIC = in;
	}
	void setDegree(string in) {
		Degree = in;
	}
	void setAddress(string in) {
		Address = in;
	}
	string getRoll_No() {
		return Roll_No;
	}
	string getName() {
		return Name;
	}
	string getCNIC() {
		return CNIC;
	}
	string getDegree() {
		return Degree;
	}
	string getAddress() {
		return Address;
	}

	void print() {
		cout << "Roll-No: " << getRoll_No() << "\nName: " << getName() << "\nCNIC: " << getCNIC() << "\nDegree: " << getDegree() << "\nAddress " << getAddress();
	}

};
//Now create an object of Student in the main, take input from user and print Roll No, Name, CNIC, Degree and Address using getters, setters and print function.
int main()
{
	Student s;
	string in[5];
	cout << "Enter Roll "; cin >> in[0];	
	cout << "Enter Name without spaces "; cin >> in[1];
	cout << "Enter CNIC "; cin >> in[2];
	cout << "Enter Degree "; cin >> in[3];
	cout << "Enter Address "; cin >> in[4];
	s.setRoll_No(in[0]), s.setName(in[1]), s.setCNIC(in[2]), s.setDegree(in[3]), s.setAddress(in[4]);

	s.print();


	return 0;
}