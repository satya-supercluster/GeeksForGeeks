//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

// User function template for C++

struct Node{
    vector<Node*> children;
    bool isEnd;
    Node(){
        children.resize(26);
        for(int i{};i<26;i++){
            children[i]=nullptr;
        }
        isEnd=false;
    }
};

class Trie {
    Node* root;
  public:

    Trie() {
        // implement Trie
        root=new Node();
    }

    void insert(string &word) {
        // insert word into Trie
        Node* p=root;
        for(auto&c:word){
            if(p->children[c-'a']==nullptr){
                p->children[c-'a']=new Node();
            }
            p=p->children[c-'a'];
        }
        p->isEnd=true;
    }

    bool search(string &word) {
        // search word in the Trie
        Node* p=root;
        for(auto&c:word){
            if(p->children[c-'a']==nullptr){
                return false;
            }
            p=p->children[c-'a'];
        }
        return p->isEnd;
    }

    bool isPrefix(string &word) {
        // search prefix word in the Trie
        Node* p=root;
        for(auto&c:word){
            if(p->children[c-'a']==nullptr){
                return false;
            }
            p=p->children[c-'a'];
        }
        return true;
    }
};



//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        int q;
        cin >> q;
        cin.ignore();
        vector<bool> ans;
        Trie ob;
        for (int i = 0; i < q; i++) {
            int x;
            cin >> x;
            string s;
            cin >> s;
            cin.ignore();
            if (x == 1) {
                ob.insert(s);
            } else if (x == 2) {
                ans.push_back(ob.search(s));
            } else if (x == 3) {
                ans.push_back(ob.isPrefix(s));
            }
        }
        cout << boolalpha;
        for (auto it : ans) {
            cout << it << " ";
        }
        cout << endl;
        cout << "~\n";
    }
    return 0;
}

// } Driver Code Ends