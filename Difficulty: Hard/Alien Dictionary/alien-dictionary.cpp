//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    string findOrder(vector<string> &words) {
        // code here
        unordered_map<char, unordered_set<char>> adj;
        unordered_map<char, int> indegree;
        for (auto &w : words) {
            for (char c : w) {
                indegree.emplace(c, 0);
                adj.emplace(c, unordered_set<char>());
            }
        }
        
        for (int i = 1; i < (int)words.size(); ++i) {
            const string &prev = words[i-1];
            const string &curr = words[i];
            int minlen = min(prev.size(), curr.size());
            int j = 0;
            while (j < minlen && prev[j] == curr[j]) ++j;
            
            if (j == minlen && prev.size() > curr.size()) {
                return "";
            }
            if (j < minlen) {
                char u = prev[j], v = curr[j];
                if (!adj[u].count(v)) {
                    adj[u].insert(v);
                    indegree[v]++;
                }
            }
        }
        
        queue<char> q;
        for (auto &p : indegree) {
            if (p.second == 0) q.push(p.first);
        }
        
        string order;
        while (!q.empty()) {
            char u = q.front(); q.pop();
            order.push_back(u);
            for (char v : adj[u]) {
                if (--indegree[v] == 0)
                    q.push(v);
            }
        }
        
        if (order.size() != indegree.size())
            return "";
        return order;
    }
};


//{ Driver Code Starts.

bool validate(const vector<string> &original, const string &order) {
    unordered_map<char, int> mp;
    for (const string &word : original) {
        for (const char &ch : word) {
            mp[ch] = 1;
        }
    }
    for (const char &ch : order) {
        if (mp.find(ch) == mp.end())
            return false;
        mp.erase(ch);
    }
    if (!mp.empty())
        return false;

    for (int i = 0; i < order.size(); i++) {
        mp[order[i]] = i;
    }

    for (int i = 0; i < original.size() - 1; i++) {
        const string &a = original[i];
        const string &b = original[i + 1];
        int k = 0, n = a.size(), m = b.size();
        while (k < n and k < m and a[k] == b[k]) {
            k++;
        }
        if (k < n and k < m and mp[a[k]] > mp[b[k]]) {
            return false;
        }
        if (k != n and k == m) {
            return false;
        }
    }
    return true;
}

int main() {
    string str;
    getline(cin, str);
    int t = stoi(str);
    while (t--) {
        getline(cin, str);
        stringstream ss(str);
        string curr;
        vector<string> words;
        while (ss >> curr)
            words.push_back(curr);

        vector<string> original = words;

        Solution ob;
        string order = ob.findOrder(words);

        if (order.empty()) {
            cout << "\"\"" << endl;
        } else {
            cout << (validate(original, order) ? "true" : "false") << endl;
        }
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends