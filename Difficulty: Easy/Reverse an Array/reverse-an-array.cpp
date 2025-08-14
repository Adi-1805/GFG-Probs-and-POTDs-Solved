class Solution {
  public:
    void reverseArray(vector<int> &arr) {
        // code here
        int n = arr.size(), i = 0;
        while(i < (n/2)){
            swap(arr[i], arr[n-1-i]);
            i++;
        }
    }
};