//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    int minCost(vector<vector<int>>& houses) {
        // code here
        int n = houses.size();
        if (n == 0) return 0;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        vector<bool> visited(n, false);
        vector<int> minCost(n, INT_MAX);
        pq.push({0, 0});
        minCost[0] = 0;
        int totalCost = 0;
        
        while (!pq.empty()) {
            auto p = pq.top();
            int cost=p.first,u=p.second;
            pq.pop();
            
            if (visited[u]) continue;
            visited[u] = true;
            totalCost += cost;
            for (int v = 0; v < n; ++v) {
                if (!visited[v]) {
                    int edgeCost = abs(houses[u][0] - houses[v][0]) + abs(houses[u][1] - houses[v][1]);
                    if (edgeCost < minCost[v]) {
                        minCost[v] = edgeCost;
                        pq.push({edgeCost, v});
                    }
                }
            }
        }
        
        return totalCost;
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> edges;

        for (int i = 0; i < n; ++i) {
            vector<int> temp;
            for (int j = 0; j < 2; ++j) {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            edges.push_back(temp);
        }

        Solution obj;

        cout << obj.minCost(edges);
        cout << "\n";
        cout << "~" << endl;
    }
}

// } Driver Code Ends