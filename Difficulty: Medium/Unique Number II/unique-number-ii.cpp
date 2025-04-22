//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    vector<int> singleNum(vector<int>& arr) {
        // Code here.
        int x=0;
        for(auto&i:arr) x^=i;
        int ind{-1};
        for(int i{};i<30;i++){
            if(x&(1<<i)){
                ind=i;
                break;
            }
        }
        int a{},b;
        for(auto&i:arr){
            if((i>>ind)&1) a^=i;
        }
        b=x^a;
        if(a<b) return {a,b};
        return {b,a};
    }
};


//{ Driver Code Starts.
int main() {
    string ts;
    getline(cin, ts);
    int t = stoi(ts);
    while (t--) {

        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }

        Solution ob;
        vector<int> ans = ob.singleNum(arr);
        for (auto it : ans) {
            cout << it << " ";
        }
        cout << endl;
        cout << "~" << endl;
    }
    return 0;
}
// } Driver Code Ends