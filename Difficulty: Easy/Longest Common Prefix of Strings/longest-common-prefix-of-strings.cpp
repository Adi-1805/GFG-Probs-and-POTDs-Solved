// User function template for C++
class Solution {
  public:
    string longestCommonPrefix(vector<string> arr) {
        // your code here
        int n = arr.size();
        sort(arr.begin(), arr.end());
        string ans = "";
        for(int i = 0; i < min(arr[0].size(), arr[n-1].size()); i++){
            if(arr[0][i] != arr[n-1][i]) return ans;
            ans += arr[n-1][i];
        }
        return ans;
    }
};