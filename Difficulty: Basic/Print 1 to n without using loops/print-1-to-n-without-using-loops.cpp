// User function Template for C++
class Solution {
    void solve(int n, int cnt){
        if(n == cnt){ cout << cnt; return ; }
        
        cout << cnt++ << " ";
        solve(n, cnt);
    }
  public:
    void printTillN(int n) {
        // Write Your Code here
        solve(n,1);
    }
};