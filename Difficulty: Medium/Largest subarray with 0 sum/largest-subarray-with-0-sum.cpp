class Solution {
  public:
    int maxLength(vector<int>& arr) {
        // code here
        int n = arr.size();
        map<int, int> mp; int sum = 0, maxlen = 0;
        for(int i = 0; i < n; i++){
            sum += arr[i];
            if(sum == 0) maxlen = max(maxlen, i+1);
            if(mp.find(sum) != mp.end()){
                maxlen = max(maxlen, i-mp[sum]);
            } 
            else mp[sum] = i;
        }
        return maxlen;
    }
};