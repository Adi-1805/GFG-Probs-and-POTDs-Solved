class Solution {
    int inversionCounts = 0;
    void merge(int left, int right, int mid, vector<int>& arr){
        vector<int> v;
        int i = left, j = mid+1;
        
        while(i <= mid and j <= right){
            if(arr[i] <= arr[j]){
                v.push_back(arr[i++]);
            }else{
                // Inversion found. Since both sub-arrays are sorted, arr[j] 
                // forms an inversion with arr[i] AND all remaining elements in the left subarray.
                v.push_back(arr[j++]);
                inversionCounts += (mid-i+1);
            }
        }
        while(i <= mid){
            v.push_back(arr[i++]);
        }
        while(j <= right){
            v.push_back(arr[j++]);
            inversionCounts += (mid-i+1);
        }
        
        for(int i = 0; i<v.size(); i++){
            arr[left + i] = v[i]; // v[0] goes to arr[left]
        }
    }
    void mergeSort(int left, int right, vector<int> &arr){
        if(left >= right) return;
        int mid = (left+right)/2;
        mergeSort(left, mid, arr);
        mergeSort(mid+1, right, arr);
        merge(left, right, mid, arr);
    }
  public:
    int inversionCount(vector<int> &arr) {
        // Code Here
        int n = arr.size();
        mergeSort(0, n-1, arr);
        return inversionCounts;
    }
};