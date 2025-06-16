// User function Template for C++

class Solution {
  public:
    bool isBSTTraversal(vector<int>& arr) {
        // your code here
        set<int> st(arr.begin(), arr.end());
        return is_sorted(arr.begin(), arr.end()) and st.size() == arr.size();
    }
};