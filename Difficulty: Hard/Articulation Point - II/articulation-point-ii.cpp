//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:

    vector<vector<int>> constructAdj(int V, vector<vector<int>> &edges) {
        vector<vector<int>> adj(V); 
        
        for (auto &edge : edges) {
           
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }
        return adj;
    }
    void findPoints(vector<vector<int>> &adj, int u, vector<int> &visited,
                    vector<int> &disc, vector<int> &low, 
                    int &time, int parent, vector<int> &isAP) {

        visited[u] = 1;
        disc[u] = low[u] = ++time;
        int children = 0; 
        for (int v : adj[u]) {
            if (!visited[v]) {
                children++;
                findPoints(adj, v, visited, disc, low, time, u, isAP);
                low[u] = min(low[u], low[v]);
                if (parent != -1 && low[v] >= disc[u]) {
                    isAP[u] = 1;
                }
            } 
            
            else if (v != parent) {
                low[u] = min(low[u], disc[v]);
            }
        }
        if (parent == -1 && children > 1) {
            isAP[u] = 1;
        }
    }
    vector<int> articulationPoints(int V, vector<vector<int>> &edges) {
        
        vector<vector<int>> adj = constructAdj(V, edges);
        vector<int> disc(V, 0), low(V, 0), visited(V, 0), isAP(V, 0);
        int time = 0; 
        for (int u = 0; u < V; u++) {
            if (!visited[u]) {
                findPoints(adj, u, visited, disc, low, time, -1, isAP);
            }
        }
        vector<int> result;
        for (int u = 0; u < V; u++) {
            if (isAP[u]) {
                result.push_back(u);
            }
        }
        return result.empty() ? vector<int>{-1} : result;
    }

};


//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >> E;
        vector<vector<int>> edges;
        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            edges.push_back({u, v});
        }
        Solution obj;
        vector<int> ans = obj.articulationPoints(V, edges);
        sort(ans.begin(), ans.end());
        for (auto i : ans)
            cout << i << " ";
        cout << "\n";

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends