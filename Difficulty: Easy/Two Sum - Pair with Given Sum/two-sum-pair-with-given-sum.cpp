class Solution {
  public:
    bool twoSum(vector<int>& arr, int target) {
        // code here
        int n = arr.size();
        sort(arr.begin(), arr.end());
        int l = 0, r = n-1;
        while(l < r){
            int sum = arr[l] + arr[r];
            if(sum > target) r--;
            else if(sum < target) l++;
            else return 1;
        }
        return 0;
    }
};