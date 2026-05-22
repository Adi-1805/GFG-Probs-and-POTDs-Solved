class Solution {
    
  public:
    vector<int> primeFac(int n) {
        // code here
        vector<int> ans;
        for(int i = 2; i*i <= n; i++){
            while(n%i == 0) {
                if(ans.empty() || ans.back() != i) ans.push_back(i);
                n /= i;
            }
        }
        if(n > 1) ans.push_back(n);
        return ans;
    }
};