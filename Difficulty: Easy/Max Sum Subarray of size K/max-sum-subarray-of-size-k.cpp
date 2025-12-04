class Solution {
  public:
    int maxSubarraySum(vector<int>& arr, int k) {
        // code here
        int n = arr.size();
        int i = 0, j = 0;
        int maxSum = 0, curSum = 0;
        while(j < n){
            curSum += arr[j];
            if(j-i+1 == k){
                maxSum = max(maxSum, curSum);
                curSum -= arr[i];
                i++;
            }
            j++;
        }
        return maxSum;
    }
};