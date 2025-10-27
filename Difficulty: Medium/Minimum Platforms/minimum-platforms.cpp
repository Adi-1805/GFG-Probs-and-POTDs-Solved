class Solution {
  public:
    int minPlatform(vector<int>& arr, vector<int>& dep) {
        // code here
        int n = arr.size();
        vector<int> hash(2400, 0);
        for(int i = 0; i < n; i++){
            hash[arr[i]] += 1;
            hash[dep[i]+1] -= 1;
        }
        int maxCnt = 0;
        for(int i = 1; i < 2400; i++){
            hash[i] += hash[i-1];
            maxCnt = max(maxCnt, hash[i]);
        }
        return maxCnt;
    }
};
