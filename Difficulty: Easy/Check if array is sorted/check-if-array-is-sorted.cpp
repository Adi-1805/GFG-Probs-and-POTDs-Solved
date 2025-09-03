class Solution {
  public:
    bool isSorted(vector<int>& arr) {
        // code here
        bool flag = 1;
        for(int i = 0; i < arr.size()-1; i++){
            if(arr[i] > arr[i+1]) {
                flag = 0; break;
            }
        }
        return flag;
    }
};