#include<iostream>
using namespace std;

template<class T,class U>
class DataObject {
	T data;
	U key;
	DataObject* Link;
public:
	DataObject() {
		data = NULL, key = NULL, Link = nullptr;
	}

	DataObject(T data, U key) {
		this->data = data;
		this->key = key;
		Link = nullptr;
	}

	void setData(T data) {
		this->data = data;
	}

	void setKey(U key) {
		this->key = key;
	}

	void setLink(DataObject* Link) {
		this->Link = Link;
	}


	T getData() {
		return this->data;
	}

	U getKey() {
		return this->key;
	}

	DataObject* getLink() {
		return this->Link;
	}

	bool operator==(DataObject const& rhs) {
		if ( (this->data != rhs.data) && (this->key!= rhs.key) )
			return false;
		return true;
	}

	DataObject< U, T > operator=(DataObject< U, T > const& rhs) {
		this->data = rhs.data;
		this->key = rhs.key;
	}

	~DataObject() {
		Link = nullptr;
		delete Link;
	}
};

int main(int argc, char const* argv[])
{
	DataObject<int, char> Obj1 = DataObject<int, char>(97, 'a');
	DataObject<int, char> Obj2 = DataObject<int, char>(Obj1);
	DataObject<int, char> Obj3 = DataObject<int, char>(1, 'x');
	(Obj1 == Obj2) ? cout << "Objects are equal" : cout << "Objects are not equal";
	Obj2.setLink(&Obj1);
	Obj2.setData('b');
	Obj2.setKey(98);
	cout << endl;
	cout << "[ " << Obj1.getData() << " : " << Obj1.getKey() << " : " << Obj1.getLink() << " ]";
	Obj1.~DataObject();
	cout << endl;
	cout << "[ " << Obj2.getData() << " : " << Obj2.getKey() << " : " << Obj2.getLink() << " ]";
	cout << endl;
	cout << "[ " << Obj3.getData() << " : " << Obj3.getKey() << " : " << Obj3.getLink() << " ]";
	Obj3 = Obj2;
	Obj2.~DataObject();
	cout << endl;
	cout << "[ " << Obj3.getData() << " : " << Obj3.getKey() << " : " << Obj3.getLink() << " ]";
	Obj3.~DataObject();
	return 0;
}