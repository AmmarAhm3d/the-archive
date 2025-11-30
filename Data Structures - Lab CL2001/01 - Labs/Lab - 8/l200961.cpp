#include <iostream>
using namespace std;
class BST;
class TreeNode {
	friend class BST;
	int data;		 // The value in the node 
	TreeNode* left;  // Pointer to left child node 
	TreeNode* right; // Pointer to right child node 
};

class BST {

	TreeNode* root;
	int Size = 0;

	int* arr = new int[size()];
	int* inOrder(TreeNode* t) {
		if (t != 0) {
			inOrder(t->left);
			arr[Size++] = t->data;
			//cout << t->data << " ";
			inOrder(t->right);
		}
		return arr;

	}
	//We are catching the root value by-reference so we dont need any extra function to connect the newly created node
	//to the tree.
	bool insert(TreeNode*& t, int val)

	{
		if (t == 0)
		{
			t = new TreeNode;
			t->data = val;
			t->left = nullptr;
			t->right = nullptr;
		}
		else if (search(val) == false) {
			if (val < t->data)
			{

				insert(t->left, val);
			}
			else if (val > t->data)
			{

				insert(t->right, val);
			}
		}
		return false;

	}
	int minimum(TreeNode* t) {
		while (t && t->left != 0)
			t = t->left;
		
		return t->data;
	}
	int maximum(TreeNode* t) {
		while (t && t->right != 0)
			t = t->right;
		
		return t->data;
	}

	int maxDepth(TreeNode* t) {
		if (t == NULL)
			return 0;
		else {
			int lDepth = maxDepth(t->left);
			int rDepth = maxDepth(t->right);

			if (lDepth > rDepth)
				return (lDepth + 1);
			else
				return (rDepth + 1);
		}
	}

	int size(TreeNode* t) { 
		if (t == NULL)
			return 0;
		else
			return(size(t->left) + 1 + size(t->right));
	}
	void levelorderPrint(TreeNode* t) {

		int h = maxDepth(root);
		int i;
		for (i = 1; i <= h; i++)
			printCurrentLevel(root, i);
	}
	void printCurrentLevel(TreeNode* t, int level=0)
	{
		if (t == NULL)
			return;
		if (level == 1)
			cout << t->data << " ";
		else if (level > 1) {
			printCurrentLevel(t->left, level - 1);
			printCurrentLevel(t->right, level - 1);
		}
	}
public:

	BST() {
		root = nullptr;
	}
	
	int* inOrder() {
		return inOrder(root);
	}
	
	bool insert(int val) {
		insert(root, val);
		return true;
	}

	bool search(int val) {
		TreeNode* t = root;
		while (t != 0) {
			if (t->data == val)
				return true;
			
			else if (val < t->data)
				t = t->left;
			else
				t = t->right;
		}
		return false;
	}
	
	bool Delete(int val) {
		TreeNode* curr = root, * parent = 0;
		while (curr != 0 && curr->data != val) {
			parent = curr;
			if (val < curr->data)
				curr = curr->left;
			else
				curr = curr->right;
		}
		if (curr == 0)
			return false;
		else {
			if (curr->left != 0 && curr->right != 0) {
				TreeNode* l = curr->left, * pl = curr;
				while (l->right != 0) {
					pl = l;
					l = l->right;
				}
				curr->data = l->data;
				curr = l;
				parent = pl;
			}
			TreeNode* child;
			if (curr->left != 0)
				child = curr->left;
			
			else
				child = curr->right;
			
			if (curr == root)
				root = child;
			
			else {
				if (curr == parent->left)
					parent->left = child;
				else
					parent->right = child;
			}
			delete curr;
			curr = 0;
			return true;
		}
	}
	int kthsmallestelement(int k) {
		int* temp;
		temp = inOrder();
		return temp[k - 1];
	}
	int kthlargestelement(int k) {
		int* temp;
		temp = inOrder();
		int s;
		s = (size() - k);
		return (temp[s]);
	}

	int maxDepth() {
		return maxDepth(root);
	}
	int size() {
		return size(root);
	}
	void levelorderPrint() {
		levelorderPrint(root);
	}


};
int main()
{
	BST t;
	for (int i = 0; i < 10; i++)
		t.insert(i + 1);
	
	t.search(2);

	int k; cout << "enter k "; cin >> k;
	cout << endl << "kth smallest:\t" << t.kthsmallestelement(k) << "\n";

	cout << endl << "kth largest :\t" << t.kthlargestelement(k) << "\n";

	cout << "\n\nheight=\t" << t.maxDepth() << "\n";
	cout << "length=\t" << t.size() << "\n";
	
	cout << "Level order is \n";
	t.levelorderPrint();
	return 0;
}