//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    int timer;
    bool isBridgeUtil(int u, int parent, vector<int> adj[], vector<bool> &visited, vector<int> &tin, vector<int> &low, int c, int d) {
        visited[u] = true;
        tin[u] = low[u] = timer++;
        
        for (int v : adj[u]) {
            if (v == parent) continue;
            if (!visited[v]) {
                if (isBridgeUtil(v, u, adj, visited, tin, low, c, d)) return true;
                low[u] = min(low[u], low[v]);
                if (low[v] > tin[u]) {
                    // Found a bridge between u and v
                    if ((u == c && v == d) || (u == d && v == c)) return true;
                }
            } else {
                low[u] = min(low[u], tin[v]);
            }
        }
        return false;
    }
    bool isBridge(int V, vector<vector<int>> &edges, int c, int d) {
        // Code here
        vector<int> adj[V];
        for (auto &edge : edges) {
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }

        vector<bool> visited(V, false);
        vector<int> tin(V, -1), low(V, -1);
        timer = 0;

        for (int i = 0; i < V; ++i) {
            if (!visited[i]) {
                if (isBridgeUtil(i, -1, adj, visited, tin, low, c, d)) {
                    return true;
                }
            }
        }
        return false;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;
        vector<int> adj[V];
        vector<vector<int>> edges(E);
        int i = 0;
        while (i++ < E) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
            edges[i - 1].push_back(u);
            edges[i - 1].push_back(v);
        }

        int c, d;
        cin >> c >> d;

        Solution obj;
        bool l = obj.isBridge(V, edges, c, d);
        if (l)
            cout << "true\n";
        else
            cout << "false\n";

        cout << "~"
             << "\n";
    }

    return 0;
}

// } Driver Code Ends