class Solution {
    void solve(int& n, int &sum){
        if(n==0) return ;
        sum += n%10;
        n /= 10;
        return solve(n,sum);
    }
  public:
    int sumOfDigits(int n) {
        // Code here
        int sum = 0;
        solve(n, sum);
        return sum;
        
    }
};