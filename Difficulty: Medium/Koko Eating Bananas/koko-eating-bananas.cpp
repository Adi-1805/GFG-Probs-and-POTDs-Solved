class Solution {
    int getHours(vector<int>& arr, int mid){
        int time = 0;
        for(int x: arr){
            time += (x%mid == 0) ? x/mid: x/mid+1;
        }
        return time;
    }
  public:
    int kokoEat(vector<int>& arr, int k) {
        // Code here
        int low = 1, high = *max_element(arr.begin(),arr.end());
        int ans = 0;
        while(low <= high){
            int mid = low + (high - low)/2;
            if(getHours(arr, mid) <= k){
                ans = mid;
                high = mid-1;
            }else{
                low = mid+1;
            }
        }
        return ans;
    }
};