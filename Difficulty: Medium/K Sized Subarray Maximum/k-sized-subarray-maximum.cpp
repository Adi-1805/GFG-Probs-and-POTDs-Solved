class Solution {
  public:
    vector<int> maxOfSubarrays(vector<int>& arr, int k) {
        // code here
        int n = arr.size();
        int i = 0, j = 0;
        int maxMax = 0, curMax = 0;
        vector<int> result;
        while(j < n){
            curMax = max(curMax, arr[j]);
            if(j-i+1 == k){
                maxMax = max(maxMax, curMax);
                result.push_back(maxMax);
                if(arr[i] == maxMax){
                    curMax = 0; maxMax = 0;
                    for(int p = i+1; p <= j; p++) curMax = max(curMax, arr[p]);
                }
                i++;
            }
            j++;
        }
        return result;
    }
};