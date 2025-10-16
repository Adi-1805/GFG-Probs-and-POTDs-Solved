class Solution {
  public:
    long subarrayXor(vector<int> &arr, int k) {
        // code here
        int n = arr.size();
        unordered_map<int, int> preMap;
        int curxor = 0, count = 0;
        preMap[curxor] = 1;
        for(int i = 0; i < n; i++){
            curxor ^= arr[i];
            int remXor = k^curxor;
            count += preMap[remXor];
            preMap[curxor]++;
        }
        return count;
    }
};