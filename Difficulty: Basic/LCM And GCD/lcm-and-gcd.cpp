//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    long long int gcd(long long int a,long long int b){
        if(a%b == 0) return b;
        return gcd(b,a%b);
    }
    vector<long long> lcmAndGcd(long long A , long long B) {
        // code here
        long long int GCD = gcd(min(A,B),max(A,B));
        return {1LL*(A*B/GCD), GCD};
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        long long A,B;
        
        cin>>A>>B;

        Solution ob;
        vector<long long> ans = ob.lcmAndGcd(A,B);
        cout<<ans[0]<<" "<<ans[1]<<endl;
    }
    return 0;
}
// } Driver Code Ends