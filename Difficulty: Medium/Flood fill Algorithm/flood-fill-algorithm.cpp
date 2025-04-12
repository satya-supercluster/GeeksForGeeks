//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    vector<pair<int,int>> dir={{0,1},{0,-1},{1,0},{-1,0}};
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc,
                                  int newColor) {
        // Code here
        int n=image.size(),m=image[0].size();
        queue<pair<int,int>>q;
        vector<vector<bool>> vis(n,vector<bool>(m,false));
        q.push({sr,sc});
        vis[sr][sc]=true;
        
        while(!q.empty()){
            int sz=q.size();
            for(int i{};i<sz;i++){
                auto e = q.front();
                q.pop();
                for(auto&p:dir){
                    int dx=p.first,dy=p.second;
                    int x=e.first+dx;
                    int y=e.second+dy;
                    if(x>=0 and x<n and y>=0 and y<m and image[x][y]==image[e.first][e.second] and !vis[x][y]){
                        q.push({x,y});
                        vis[x][y]=true;
                    }
                }
                image[e.first][e.second]=newColor;
            }
        }
        return image;
    }
};


//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> image(n, vector<int>(m, 0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++)
                cin >> image[i][j];
        }
        int sr, sc, newColor;
        cin >> sr >> sc >> newColor;
        Solution obj;
        vector<vector<int>> ans = obj.floodFill(image, sr, sc, newColor);
        for (auto i : ans) {
            for (auto j : i)
                cout << j << " ";
            cout << "\n";
        }

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends