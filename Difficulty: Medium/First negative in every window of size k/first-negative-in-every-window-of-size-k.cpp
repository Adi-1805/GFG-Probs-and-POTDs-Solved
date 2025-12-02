class Solution {
  public:
    vector<int> firstNegInt(vector<int>& arr, int k) {
        // write code here
        int n = arr.size();
        int i = 0, j = 0;
        vector<int> result;
        queue<int> q;
        while(j < n){
            if(arr[j] < 0) q.push(arr[j]);
            if(j - i + 1 == k){
                if(!q.empty()) result.push_back(q.front());
                else result.push_back(0);
                if(arr[i] == q.front()) q.pop();
                i++; 
            }
            j++;
        }
        return result;
    }
};