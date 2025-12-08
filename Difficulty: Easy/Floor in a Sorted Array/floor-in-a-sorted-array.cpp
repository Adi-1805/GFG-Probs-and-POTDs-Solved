class Solution {
  public:
    int findFloor(vector<int>& nums, int target) {
        // code here
        int n = nums.size();
        int high = n-1, low = 0;
        int index = -1;
        while(low <= high){
            int mid = low + (high-low);
            if(target >= nums[mid]){
                index = mid;
                low = mid+1;
            }
            else high = mid -1;
        }
        return index;
    }
};
