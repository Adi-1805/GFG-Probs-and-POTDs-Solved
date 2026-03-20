class Solution {
    void recur(int i, vector<int> &arr, vector<int> &result, int sum){
        if(i == arr.size()){
            result.push_back(sum); return;
        }
        recur(i+1, arr, result, sum);
        recur(i+1, arr, result, sum+arr[]);
    }
  public:
    vector<int> subsetSums(vector<int>& arr) {
        // code here
        vector<int> result; int sum = 0;
        recur(0, arr, result, sum);
        return result;
    }
};