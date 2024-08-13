//{ Driver Code Starts
// Initial template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function template for C++

class Solution {
  public:
    long long int binExpIter(long long a,int b){
        long long int ans = 1;
        while(b){
            if(b&1){
                ans = ans * a;
            }
            a = a*a;
            b>>=1;
        }
        return ans;
    }
    long long sumOfSeries(long long n) {
        // code here
        long long num = n*(n+1)/2;
        return binExpIter(num,2);
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
        cout << ob.sumOfSeries(N) << "\n";
    }
}
// } Driver Code Ends