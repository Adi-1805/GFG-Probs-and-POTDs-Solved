// User code template

class Solution {
  public:
    vector<int> getFloorAndCeil(int target, vector<int> &nums) {
        sort(nums.begin(), nums.end());
        // code here
        int n = nums.size();
        int high = n-1, low = 0;
        int floor = -1, ceil = -1;
        while(low <= high){
            int mid = low + (high-low);
            if(nums[mid] == target) return {nums[mid], nums[mid]};
            else if(target > nums[mid]){
                floor = mid;
                low = mid+1;
            }
            else{
                ceil = mid;
                high = mid -1;
            }
        }
        vector<int> result;
        (floor == -1) ? result.push_back(-1) : result.push_back(nums[floor]);
        (ceil == -1) ? result.push_back(-1) : result.push_back(nums[ceil]);
        return result;
    }
};