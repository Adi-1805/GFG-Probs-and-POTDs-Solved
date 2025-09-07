class Solution {
  public:
    int missingNum(vector<int>& arr) {
        // code here
        int n = arr.size() + 1;
        long long int cursum = 0;
        long long int totSum = 1LL*n*(n+1)/2;
        for(int val: arr) cursum += val;
        return totSum - cursum;
    }
};