#include<iostream>
using namespace std;
class BST;
class TreeNode
{
	friend class BST;
	int data; // The value in the node 
	TreeNode *left; // Pointer to left child node 
	TreeNode *right; // Pointer to right child node 
};
class BST
{
	TreeNode* root;
	void inOrder(TreeNode* t)
	{
		if (t != 0)
		{
			inOrder(t->left);
			cout << t->data << " ";
			inOrder(t->right);
		}
	}
	void preOrder(TreeNode* t)
	{
		if (t != 0)
		{
			cout << t->data << " ";
			inOrder(t->left);
			inOrder(t->right);
		}
	}
	void postOrder(TreeNode* t)
	{
		if (t != 0)
		{
			inOrder(t->left);
			inOrder(t->right);
			cout << t->data << " ";
		}
	}
	//We are catching the root value by-reference so we dont need any extra function to connect the newly created node
	//to the tree.
	void insert(TreeNode*& t,int val)
	{
		if (t == 0)
		{
			t = new TreeNode;
			t->data = val;
			t->left = nullptr;
			t->right = nullptr;
		}
		else if (val < t->data)
		{
			insert(t->left, val);
		}
		else if (val > t->data)
		{
			insert(t->right, val);
		}
	}
	int minimum(TreeNode* t)
	{
		while (t && t->left != 0)
		{
			t = t->left;
		}
		return t->data;
	}
	int maximum(TreeNode* t)
	{
		while (t && t->right != 0)
		{
			t = t->right;
		}
		return t->data;
	}
public:
	BST()
	{
		root = nullptr;
	}
	~BST()
	{}
	void inOrder()
	{
		inOrder(root);
	}
	void preOrder()
	{
		preOrder(root);
	}
	void postOrder()
	{
		postOrder(root);
	}
	void insert(int val)
	{
		insert(root, val);
	}
	bool search(int val)
	{
		TreeNode* t=root;
		while (t != 0)
		{
			if (t->data == val)
			{
				cout << val<<" exists...!\n";
				return true;
			}
			else if (val < t->data)
				t = t->left;
			else
			t = t->right;
		}
		cout << val << " does not exist...!\n";
		return false;
	}
	int minimum()
	{
		return minimum(root);
	}
	int maximum()
	{
		return maximum(root);
	}
	bool remove(int val)
	{
		TreeNode* curr = root, *parent = 0;
		while (curr != 0 && curr->data != val)
		{
			parent = curr;
			if (val < curr->data)
				curr = curr->left;
			else
				curr = curr->right;
		}
		if (curr == 0)
			return false;
		else
		{
			if (curr->left != 0 && curr->right != 0)
			{
				TreeNode *l = curr->left, *pl = curr;
				while (l->right != 0)
				{
					pl = l;
					l = l->right;
				}
				curr->data = l->data;
				curr = l;
				parent = pl;
			}
			TreeNode* child;
			if (curr->left != 0)
			{
				child = curr->left;
			}
			else
			{
				child = curr->right;
			}
			if (curr == root)
			{
				root = child;
			}
			else
			{
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
};
int main()
{
	BST b1;
	b1.insert(5);
	b1.insert(7);
	b1.insert(4);
	b1.insert(3);
	cout << "Tree's data through In-Order Traversal: ";
	b1.inOrder();
	cout << endl;
	cout << "Tree's data through Pre-Order Traversal: ";
	b1.preOrder();
	cout << endl;
	cout << "Tree's data through Post-Order Traversal: ";
	b1.postOrder();
	cout << endl;
	b1.search(2);
	cout<<"Minimum value of BST is: "<<b1.minimum()<<endl;
	cout << "Maximum value of BST is: " << b1.maximum() << endl;
	b1.remove(5);
	cout << "Tree's data through In-Order Traversal: ";
	b1.inOrder();
	cout << endl;
	cout << "Tree's data through Pre-Order Traversal: ";
	b1.preOrder();
	cout << endl;
	cout << "Tree's data through Post-Order Traversal: ";
	b1.postOrder();
	system("pause");
	return 0;
}