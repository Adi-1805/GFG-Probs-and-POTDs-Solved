class Solution {
  public:
    // Function to find equilibrium point in the array.
    int findEquilibrium(vector<int> &arr) {
        // code here
        int n = arr.size();
        int total = accumulate(arr.begin(), arr.end(), 0);
        int left_sum = 0, right_sum = 0;
        for(int i = 0; i < n; i++){
            right_sum = total - left_sum- arr[i];
            if(left_sum == right_sum) return i;
            left_sum += arr[i];
        }
        return -1;
    }
};