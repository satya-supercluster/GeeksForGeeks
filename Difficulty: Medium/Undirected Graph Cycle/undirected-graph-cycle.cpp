//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    bool bfs(int s,vector<vector<int>>& adj)  {
        int V = adj.size();
        queue<int> q;  
        vector<bool> visited(V, false);
        visited[s] = true;
        q.push(s);
        while (!q.empty()) {
            int curr = q.front();
            q.pop();
            for (int x : adj[curr]) {
                if (!visited[x]) {
                    visited[x] = true;
                    q.push(x);
                }
                else return true;
            }
        }
    
        return false;
    }
    bool isCycle(int V, vector<vector<int>>& edges) {
        // Code here
        vector<vector<int>> adj(V);
        for (auto it : edges)
        {
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }
        bool p=false;
        for(int i{};i<V;i++){
            p|=bfs(i,adj);
        }
        return p;
    }
};


//{ Driver Code Starts.

int main() {
    int tc;
    cin >> tc;
    cin.ignore();
    while (tc--) {
        int V, E;
        cin >> V >> E;
        cin.ignore();
        vector<vector<int>> edges;
        for (int i = 1; i <= E; i++) {
            int u, v;
            cin >> u >> v;
            edges.push_back({u, v});
        }

        Solution obj;
        bool ans = obj.isCycle(V, edges);
        if (ans)
            cout << "true\n";
        else
            cout << "false\n";

        cout << "~"
             << "\n";
    }
    return 0;
}

// } Driver Code Ends