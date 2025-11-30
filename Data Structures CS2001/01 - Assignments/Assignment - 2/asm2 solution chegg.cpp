#include<bits/stdc++.h>
using namespace std;

class Node
{
    public:

        string kw;
        vector<string> vec;// vector of urls for a keyword
        Node *left,*right; // pointers for left and right child

        Node(string k,vector<string> v){kw = k;vec = v;left=right=NULL;}
} ;

// bst class
class BST{
    private:
        Node *head;
    public:
        BST(){head =  NULL;}
        BST(Node *temp){head = temp; } // parameterized constructor

        Node* get_head(){return head;}
        void insert_Node(Node *x) //  function to add a node to the bst
        {
            Node *t=head,*prev=head;

            if(t==NULL)
            {
                head = x;return;
            }
            while(t!=NULL)
            {
                if(t->kw.compare(x->kw)>0) // if the keyword is lexicographically smaller than the string t->kw , then go to the left subtree
                {
                    prev = t;
                    t = t->left;
                }
                else if(t->kw.compare(x->kw)<0)
                {
                    prev = t;
                    t = t->right;
                }
                else if(t->kw==x->kw)
                {
                    cout<<"keyword already exists\n";exit(1);
                }
            }

            if(prev->kw.compare(x->kw)>0)
            {
                prev->left = x;
            }
            if(prev->kw.compare(x->kw)<0)
            {
                prev->right = x;
            }
        }
        // the function shows the URLS and returns the number of URLS associated to the given keyword 
        // if no such keyword is found then the function returns 0 
        int search_node(string x)
        {
            Node *t=head;

            if(t==NULL)
            {
                cout<<"The tree is empty\n";return 0;
            }
            while(t!=NULL)
            {
                if(t->kw.compare(x)>0) // if the keyword is lexicographically smaller than the string t->kw , then go to the left subtree
                {
                    t = t->left;
                }
                else if(t->kw.compare(x)<0)
                {
                    t = t->right;
                }
                else if(t->kw==x)
                {
                    cout<<"_________________URLS FOR THIS KEYWORD______________________\n";
                    for(auto c:t->vec)
                    {
                        cout<<c<<"\n";
                    }
                    return t->vec.size();
                }
            }
            return 0;
        }
        // find the node with the lexicographically smallest keyword in the tree with root x		
		Node* helper_find(Node *x)
        {
            if(x==NULL)
            return NULL;
            Node *prev = x;
            while(x->left)
            {
                x = x->left;
            }
            return x;
        }
        // delete the node with keyword x
		
		/*changeto:
		par = parent, head of
		nn = new_node, head of*/
        
		void delete_node(Node *par,Node *nn,string x)
        {
            Node *t=nn,*prev=head;
    
            if(t==NULL)
            {
                cout<<"The tree is empty \n";return;
            }
            
            if(t->kw == x) // if the current node has the keyword
            {
                Node *temp = helper_find(t->right);

                if(temp!=NULL) // copy the contents of inorder succesor in the current node
                {
                    t->kw = temp->kw;
                    t->vec = temp->vec;
                    delete_node(t,t->right,temp->kw);
                }
                else
                {
                    if(par->kw==t->kw)// in case the node is head
                    {
                        head = par->left;
                    }
                    else if(par->right!=NULL && par->right->kw==t->kw)
                    {
                        par->right = t->left;
                        delete(t);
                    }
                    else if(par->left!=NULL && par->left->kw==t->kw)
                    {
                        par->left = t->left;
                        delete(t);
                    }
                }
                return;
            }

            while(t!=NULL)
            {
                // if the keyword is lexicographically smaller than the string t->kw , then go to the left subtree
                if(t->kw.compare(x)>0) 
                {
                    prev = t;
                    t = t->left;
                }
                else if(t->kw.compare(x)<0)
                {
                    prev = t;
                    t = t->right;
                }
                else if(t->kw==x)
                {
                    Node *temp = helper_find(t->right); // fnd the inorder succesor of the current node

                    if(temp!=NULL)
                    {
                        // copy the contents of the inorder successor
                        t->kw = temp->kw;
                        t->vec = temp->vec;
                        delete_node(t,t->right,temp->kw);
                    }
                    else // if the right subtree doesn't exist
                    {
                        if(prev->right!=NULL && prev->right->kw == t->kw)
                        {
                            prev->right = t->left;
                            delete(t);
                        }
                        else if(prev->left!=NULL && prev->left->kw == t->kw)
                        {
                            prev->left = t->left;
                            delete(t);
                        }
                    }
                    return;
                }
            }
        }
};
int main()
{
    string file_name;
    cout<<"Enter the file name : ";
    // prompt the user to enter the file name
    cin>>file_name;

    fstream ptr;
    ptr.open(file_name,ios::in);

    unordered_map<string,vector<string> > mp; // the map will store the keywords and the corresponding vector of URLs
    int i=0;
    string temp;

    if(!ptr)
    {
        cout<<"Unable to open the file\n";exit(1);
    }
    else
    {
        cout<<"File opened successfully\n";
    }
    while(getline(ptr,temp))
    {
        if(temp.size()==0)
            break;
        stringstream chk(temp); // tokenize the first line of every data ite, to extract the URL
        string id,url,kw;
        getline(chk,id,' ');
        getline(chk,url,' ');

        getline(ptr,temp); // skip the single blank line between the two lines of the content

        getline(ptr,temp);

        stringstream chk2(temp); // extract the keywords of the data item

        while(getline(chk2,kw,' '))
        {
            mp[kw].push_back(url);
        }
        getline(ptr,temp);
    }
    BST *tr= new BST();
    // construct the binary search tree by adding all the nodes.
    for(auto p:mp)
    {
        Node *nd= new Node(p.first,p.second);
        tr->insert_Node(nd);
    }
    
    cout<<"provide the keyword to search for : ";
    string kk;
    cin>>kk;
    // cout<<mp["KEY3"].size()<<" sz\n";
    int f = tr->search_node(kk);
    if(f!=0)
    {
        cout<<f<<" results found\n";
    }
    else
    {
        cout<<"No results found\n";
    }
    
    cout<<"\nNow deleteing keyword "<<kk<<"\n";
    
    tr->delete_node(tr->get_head(),tr->get_head(),kk);

    cout<<"Search Keyword "<<kk<<"\n";
    f = tr->search_node(kk);
    if(f!=0)
    {
        cout<<f<<" results found\n";
    }
    else
    {
        cout<<"No results found\n";
    }
    
}