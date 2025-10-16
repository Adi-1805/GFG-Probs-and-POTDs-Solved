class Solution {
  public:
    int longestSubarray(vector<int>& arr, int k) {
        // code here
        int n = arr.size();
        unordered_map<long long, int> pfMap; // stores prefixSum:Index
        int cursum = 0, maxLen = 0;
        for(int i = 0; i < n; i++){
            cursum += arr[i];
            if(cursum == k) maxLen = max(maxLen, i+1);
            int remSum = cursum - k;
            if(pfMap.find(remSum) != pfMap.end()){
                maxLen = max(maxLen, i - pfMap[remSum]);
            }
            if(pfMap.find(cursum) == pfMap.end()){
                pfMap[cursum] = i;
            }
        }
        return maxLen;
    }
};