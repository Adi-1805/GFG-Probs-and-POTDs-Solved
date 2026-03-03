class Solution {
  public:
    void sort012(vector<int>& arr) {
        /* Based on the DUTCH FLAG ALGORITHM
        
            We're tryign to maintain three section in the array using three pointers: low, high and mid.
            We will maintain 0...low as a sorted section, low...(mid-1) also sorted, mid...high as UNsorted
            and high+1...(n-1) will be sorted automatically.
            
            At every point we're trying to achieve:
            [0, low-1] will contain 0s;
            [low, mid-1] will contain 1s;
            [mid, high] will be unsorted;
            [high+1, n-1] will contain 2s
        */
        
        int n = arr.size(), low = 0, high = n-1, mid = 0;
        while(mid <= high){
            if(arr[mid] == 0){
                swap(arr[low], arr[mid]); low++; mid++;
            }else if(arr[mid] == 1){
                mid++;
            }else{
                swap(arr[mid], arr[high]); high--;
            }
        }
    }
};