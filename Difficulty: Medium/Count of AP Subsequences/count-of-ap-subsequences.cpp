//{ Driver Code Starts

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends


class Solution {
  public:
    int count(vector<int>& arr) {
        // code here
        int n = arr.size();
        int total = n + 1;
        vector<unordered_map<int, int>> dp(n);
    
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < i; ++j) {
                int diff = arr[i] - arr[j];
    
                int count = dp[j].count(diff) ? dp[j][diff] : 0;
                dp[i][diff] += count + 1;
    
                total += count + 1;
            }
        }
    
        return total;
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        vector<int> arr(N);
        for (int i = 0; i < N; i++)
            cin >> arr[i];
        Solution ob;
        cout << ob.count(arr) << endl;

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends