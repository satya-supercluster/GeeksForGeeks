//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    int maxPartitions(string &s) {
        // code here
        int n = s.length();
        vector<int> last(26, -1);
        for (int i = 0; i < n; i++) {
            last[s[i] - 'a'] = i;
        }
        
        int count = 0;
        int i = 0;
        while (i < n) {
            int end = last[s[i] - 'a'];
            int j = i;
            while (j < end) {
                end = max(end, last[s[j] - 'a']);
                j++;
            }
            count++;
            i = end + 1;
        }
        return count;
    }
};


//{ Driver Code Starts.

int main() {
    int tc;
    cin >> tc;

    for (int i = 0; i < tc; ++i) {
        string s;
        cin >> s;
        Solution obj;
        cout << obj.maxPartitions(s) << endl;
        cout << "~" << endl;
    }

    return 0;
}

// } Driver Code Ends