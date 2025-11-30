#include <iostream>
using namespace std;

struct Node{
	int data;
	Node* left;
	Node* right;
	Node(int data = 0){ left = NULL, right = NULL; this->data = data; }
};

class BST{
	Node* root;
	void insert(int ele, Node* &t){
		if (t == 0){
			t = new Node(ele);
			return;
		}
		else if (ele > t->data)
			insert(ele, t->left);
		else if (ele < t->data)
			insert(ele, t->right);
	}

	// get fib at index
	int fib(int n){
		if (n < 2)
			return n;
		else
			return fib(n - 1) + fib(n - 2);
	}

	Node* fab(int n){
		if (n != 0){
			insert(n, root);
			fab(n--);
		}
		else
			return root;
	}

	void postorder(Node*t){
		// lrn
		postorder(t->left);
		postorder(t->right);
		cout << t->data <<" ";
	}
	void preorder(Node*t){
		// lnr
		preorder(t->left);
		cout << t->data << " ";
		preorder(t->right);
	}
public:
	BST(){ root = NULL;}
	void postorder(){ postorder(root); }
	void preorder(){ preorder(root); }
	void fabb(int n){ fab(n); postorder(); }
};


int main()
{
	BST t;
	t.fabb(4);

	system("pause");
}


