class Solution {
  public:
    vector<int> leaders(vector<int>& arr) {
        // code here
        int n = arr.size();
        vector<int> result;
        int maxSofar = INT_MIN;
        for(int i = n-1; i >= 0; i--){
            if(arr[i] >= maxSofar){
                maxSofar = arr[i]; result.push_back(maxSofar);
            }
        }
        reverse(result.begin(), result.end());
        return result;
    }
};