//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

// User function Template for C++

class Solution {
  public:
    int maxXor(vector<int> &nums) {
        // code here
        int maxXor = 0, mask = 0;
        for (int b = 20; b >= 0; --b) {
            mask |= (1 << b);
            unordered_set<int> prefixes;
            prefixes.reserve(nums.size());
            for (int x : nums) {
                prefixes.insert(x & mask);
            }
            int candidate = maxXor | (1 << b);
            bool found = false;
            for (int p : prefixes) {
                if (prefixes.count(p ^ candidate)) {
                    found = true;
                    break;
                }
            }
            if (found) {
                maxXor = candidate;
            }
        }
        return maxXor;
    }
};



//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        vector<int> arr(n);
        for (int i = 0; i < n; i++)
            cin >> arr[i];

        Solution ob;
        cout << ob.maxXor(arr) << endl;

        cout << "~"
             << "\n";
    }
}

// } Driver Code Ends