class Solution {
    void solve(stack<int>& s, int& midLen){
        if(midLen == 0){
            s.pop();
            return ;
        }
        int t = s.top();
        s.pop();
        midLen--;
        solve(s,midLen);
        s.push(t);
    }
  public:
    // Function to delete middle element of a stack.
    void deleteMid(stack<int>& s) {
        // code here...
        int n = (s.size()&1) ? (s.size()-1)/2 : s.size()/2;
        solve(s, n);
    }
};