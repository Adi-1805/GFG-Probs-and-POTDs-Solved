//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
    long long fact(long long n, vector<long long>& dp){
        if (n == 0) return 1;
        if (dp[n] != -1) return dp[n];
        else return dp[n] = n * fact(n - 1, dp);
    }
  public:
    vector<long long> factorialNumbers(long long n) {
        // Write Your Code here
        vector<long long> dp(1441,-1);
        dp[0] = 1;
        vector<long long> ans;
        for(int i = 1; fact(i,dp) <= n; i++){
            ans.push_back(fact(i,dp));
        }
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        long long N;
        cin >> N;
        Solution ob;
        vector<long long> ans = ob.factorialNumbers(N);
        for (auto num : ans) {
            cout << num << " ";
        }
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends