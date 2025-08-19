class Solution {
  public:
    int smallestSubWithSum(int x, vector<int>& arr) {
        // Your code goes here
        int n = arr.size();
        int minLen = 1e9, cursum = 0;
        int left = 0, right  = 0;
        while(right < n){
            cursum += arr[right];
            // cout << cursum << endl;
            while(cursum > x){
                minLen = min(minLen, right-left+1);
                // cout << minLen << endl;
                cursum -= arr[left];
                left++;
            }
            right++;
        }
        return (minLen == 1e9) ? 0 : minLen;
    }
};