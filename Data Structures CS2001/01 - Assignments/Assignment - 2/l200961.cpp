#include <iostream>
#include <fstream>	// file reading library
#include <chrono>	// time profiling library
                    // map to store key-value pairs in any order
#include <sstream>	// tokenizing library
#include <list>
using namespace std;
using namespace std::chrono;

struct TreeNode {
    string kwrd;        // store keywords
    list<string> urls;
                        // store corresponding urls
    TreeNode* left;         // Pointer to left child node
    TreeNode* right;        // Pointer to right child node
    TreeNode(string kwrd, const string& url){
        this->kwrd=std::move(kwrd), this->urls.push_back(url);
        this->left= nullptr, this->right= nullptr;
    }
};

class BST {
    TreeNode *root;

    void insert(TreeNode*& t, const string& kwrd, const string& url, bool b) {
        if(b){
            TreeNode* t = root;
            while (t != 0) {
                if (t->kwrd == kwrd) { t->urls.push_back(url);return;}
                else if (kwrd < t->kwrd)
                    t = t->left;
                else
                    t = t->right;
            }
        }
        else {
            if (t == 0)
                t = new TreeNode(kwrd, url);

            else if (t->kwrd.compare(kwrd) > 0)
                insert(t->left, kwrd, url, b);

            else if (t->kwrd.compare(kwrd) < 0)
                insert(t->right, kwrd, url, b);

        }

    }

    static TreeNode* minimum(TreeNode* x) {
        if (x == 0)
            return nullptr;
        while (x->left)
            x = x->left;

        return x;
    }

    bool find(const string& in){
        TreeNode* t = root;
        while (t!=0){
            if(t->kwrd == in)
                return true;
            else if(t->kwrd.compare(in) > 0)
                t=t->left;
            else
                t=t->right;
        } return false;
    }

    // helper delete with roots
    void delete_(TreeNode *par, TreeNode *nn, const string& x) {
        TreeNode *t=nn,*prev=root;

        if(t==0){
            cout<<"The tree is empty \n";return;
        }

        // if the current node has the keyword
        if(t->kwrd == x){
            TreeNode *temp = minimum(t->right);

            // copy the contents of inorder successor in the current node
            if(temp!=0){
                t->kwrd = temp->kwrd;
                t->urls = temp->urls;
                delete_(t, t->right, temp->kwrd);
            }
            else{
                // in case the node is head
                if(par->kwrd==t->kwrd)
                    root = par->left;

                else if(par->right!=0&& par->right->kwrd==t->kwrd){
                    par->right = t->left;
                    delete t;
                }
                else if(par->left!=0&& par->left->kwrd==t->kwrd){
                    par->left = t->left;
                    delete t;
                }
            }
            return;
        }

        while(t!=0){
            // if the keyword is lexicographically smaller than the string t->kwrd , then go to the left subtree
            if(t->kwrd.compare(x)>0){
                prev = t;
                t = t->left;
            }
            else if(t->kwrd.compare(x)<0){
                prev = t;
                t = t->right;
            }
            else if(t->kwrd==x){
                TreeNode *temp = minimum(t->right); // fnd the inorder succesor of the current node

                if(temp!=NULL){
                    // copy the contents of the inorder successor
                    t->kwrd = temp->kwrd;
                    t->urls = temp->urls;
                    delete_(t, t->right, temp->kwrd);
                }

                // if the right subtree doesn't exist
                else{
                    if(prev->right!=0&& prev->right->kwrd == t->kwrd){
                        prev->right = t->left;
                        delete t;
                    }
                    else if(prev->left!=0&& prev->left->kwrd == t->kwrd){
                        prev->left = t->left;
                        delete t;
                    }
                }
                return;
            }
        }
    }

public:
    BST() { root = nullptr; }

    void insert(const string& kwrd, const string& urls) {
        insert(root, kwrd, urls, find(kwrd));
    }

    void search(const string& in) {
        TreeNode* t = root;

        while (t != 0) {
            // time profiling starts here
            auto beg = high_resolution_clock::now();

            if (t->kwrd == in) {
                cout << t->urls.size() << " result(s) found ";
                auto end = high_resolution_clock::now();
                auto elapsed = end - beg;
                cout << "in " << int(duration<int, nano>(elapsed).count() * 1e-9) << " seconds"
                     << " and " << duration<double, micro>(elapsed).count() << " microseconds\n";

                int i = 1;
                for (const auto& str : t->urls)
                    cout << i++ << " - " << str << "\n";
                return;
            }

            else if (t->kwrd.compare(in) > 0)
                t = t->left;

            else
                t = t->right;

        }
        cout << "\n" << in << "does not exist...!\n";
    }

    void delete_(const string& kwrd) {
        // call helper delete
        delete_(this->root, this->root, kwrd);
    }


};

int main()
{
//    string fname;
//    cout << "Please enter a filename:\n> "; cin >> fname;

     string fname = "data.txt";
    fstream fin(fname, ios::in);


    if (!fin.is_open()) {
        cout << "Unable to open the file\n"; return 0;
    }

    else {
        auto beg = high_resolution_clock::now();

        BST t;

        string read;
        int count = 0;

        while (fin) {
            getline(fin, read);    // input first line
            stringstream line1(read); // tokenize first line, to extract id and url
            string id, url, kwrd;

            line1 >> id >> url; count++;

            getline(fin, read);    // input second line
            stringstream line2(read); // tokenizing keywords

            while (line2 >> kwrd) { t.insert(kwrd,url); kwrd.erase(); }

            getline(fin, read);     // ignore third line
            read.erase();
        }
        fin.close();


        cout << "File loaded into the BST successfully. " << count
             << " URLs loaded from the file ";
        auto end = high_resolution_clock::now();
        cout << "in " << int(duration<int, nano>(end - beg).count() * 1e-9) << " seconds"
             << " and " << duration<double, micro>(end - beg).count() << " microseconds\n";

        string kwrd;
        while (true) {
            cout << "Please enter a word to search, or enter - to exit: \n> ";
            if (kwrd == "-")break;
            cin >> kwrd;
            t.search(kwrd);
            cout << "Enter tilde (~) to delete keyword\n> ";
            char del; cin >> del;
            if (del == '~') {
                t.delete_(kwrd);
                cout << kwrd << " has been deleted\n";
            }
        }
    }
    return 0;
}