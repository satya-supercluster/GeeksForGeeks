//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    bool isCyclic(int n, vector<vector<int>> &edges) {
        // code here
        vector<vector<int>>adj(n);
        for(auto&i:edges){
            adj[i[0]].push_back(i[1]);
        }
        vector<int> vis(n,0),pVis(n,0);
        bool p=false;
        function<bool(int)> dfs=[&](int u)->bool{
            vis[u]=true;
            pVis[u]=true;
            bool cycle=false;
            for(auto&child:adj[u]){
                if(!vis[child]){
                    cycle= cycle or dfs(child);
                }
                else if(pVis[child]) cycle=true;
            }
            pVis[u]=false;
            return cycle;
        };
        for(int i{};i<n;i++){
            if(!vis[i]){
                p|=dfs(i);
            }
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
        bool ans = obj.isCyclic(V, edges);
        if (ans)
            cout << "true\n";
        else
            cout << "false\n";
    }
    return 0;
}
// } Driver Code Ends