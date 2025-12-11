class Solution {
  public:
    int findKRotation(vector<int> &arr) {
        // Code 
        int n = arr.size();
        int low = 0, high = n-1;
        int minimum = INT_MAX;
        int k = 0;
        while(low <= high){
            int mid = low + (high-low)/2;
            if(arr[mid] >= arr[low]){
                // left sorted
                if(minimum > arr[low]){
                    k = low; minimum = arr[low];
                }
                low = mid + 1; 
            }else{
                //right sorted
                if(minimum > arr[mid]){
                    k = mid; minimum = arr[mid];
                }
                high = mid - 1;
            }
        }
        return k;
    }
};
