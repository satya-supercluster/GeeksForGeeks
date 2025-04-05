//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    vector<pair<int,int>> dir={{0,1},{0,-1},{-1,-1},{1,0},{-1,0},{1,1},{1,-1},{-1,1}};
    int countIslands(vector<vector<char>>& grid) {
        // Code here
        int n=grid.size(),m=grid[0].size(),ans{};
        function<void(int,int)> dfs=[&](int i,int j)->void{
             grid[i][j]='W';
             for(auto&p:dir){
                 int dx=p.first,dy=p.second;
                 int x=i+dx,y=j+dy;
                 if(x>=0 and x<n and y>=0 and y<m and grid[x][y]=='L'){
                     dfs(x,y);
                 }
             }
        };
        for(int i{};i<n;i++){
            for(int j{};j<m;j++){
                if(grid[i][j]=='L'){
                    ans++;
                    dfs(i,j);
                }
            }
        }
        return ans;
    }
};


//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n, m;
        cin >> n >> m;
        vector<vector<char>> grid(n, vector<char>(m, '#'));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }
        Solution obj;
        int ans = obj.countIslands(grid);
        cout << ans << '\n';

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends