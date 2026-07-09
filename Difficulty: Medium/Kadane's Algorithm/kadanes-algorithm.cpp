class Solution {
    using ll = long long;
  public:
    int maxSubarraySum(vector<int> &a) {
        // Code here
        int n = a.size();
        ll maxsum = INT_MIN;
        ll cursum = 0; int s = 0, e = 0;
        for(int i = 0; i < n; i++){
            if(cursum == 0) s = i;
            cursum += a[i];
            if(cursum > maxsum){
                maxsum = cursum;
                e = i;
            }
            if(cursum < 0){
                cursum = 0;
            }
            // cout << sum << " ";
        }
        return maxsum;
    }
};