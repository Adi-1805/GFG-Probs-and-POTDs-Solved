// User function Template for C++
class Solution {
    void solve(int curDigit, int n, vector<int> &res, int num){
        if(n==0){
            res.push_back(num);
            return;
        }
        for(int i = curDigit ; i<=9 ; i++){
            num = num * 10 + i;
            solve(i+1, n-1, res, num);
            num = num / 10;
        }
    }
  public:
    vector<int> increasingNumbers(int n) {
        // Write Your Code here
        vector<int> result;
        if(n == 1){
            for(int i = 0; i < 10; i++){
                result.push_back(i);
            }
            return result;
        }
        solve(1, n, result, 0);
        
        return result; 
    }
};