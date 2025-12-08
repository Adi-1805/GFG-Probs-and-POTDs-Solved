class Solution {
  public:
    int peakElement(vector<int> &arr) {
        // code here
        int n = arr.size();
        int high = n-1, low = 0;
        if(arr.size() == 1 or arr[low] > arr[low+1]) return low;
        if(arr[high] > arr[high-1]) return high;
        while(low <= high){
            int mid = low + (high-low)/2;
            if(arr[mid-1] < arr[mid] and arr[mid] > arr[mid+1]) return mid;
            else if(arr[mid-1] > arr[mid]) high = mid;
            else low = mid;
        }
        return -1;
    }
};