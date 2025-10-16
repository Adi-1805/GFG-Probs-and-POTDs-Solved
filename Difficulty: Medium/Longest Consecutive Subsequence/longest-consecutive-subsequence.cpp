class Solution {
  public:
    bool BS(int s, int e, vector<int> &arr, int target){
        if(s > e) return false;
        
        int mid = (s+e)/2;
        if(arr[mid] == target) return true;
        else if(arr[mid] < target) return BS(mid+1, e, arr, target);
        else return BS(s, mid-1, arr, target);
        
        return false;
    }
    // Function to return length of longest subsequence of consecutive integers.
    int longestConsecutive(vector<int>& arr) {
        // Your code here
        int n = arr.size();
        sort(arr.begin(), arr.end());
        
        int maxlen = 1, curlen = 1;
        for(int i = 0; i < n; i++){
            int nextElement = arr[i]+1;
            while(BS(0, n-1, arr, nextElement)){
                curlen++;
                nextElement += 1;
            }
            maxlen = max(maxlen, curlen);
            curlen = 1;
        }
        return maxlen;
    }
};