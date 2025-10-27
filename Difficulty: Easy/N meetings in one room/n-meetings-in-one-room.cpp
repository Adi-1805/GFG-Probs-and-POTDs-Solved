class Solution {
  public:
    // Function to find the maximum number of meetings that can
    // be performed in a meeting room.
    int maxMeetings(vector<int>& start, vector<int>& end) {
        // Your code here
        int n = start.size();
        
        vector<tuple<int, int, int>> v;
        for(int i = 0; i < n; i++){
            v.push_back({end[i], start[i], i+1}); 
        }
        
        sort(v.begin(), v.end());
        int count = 0;
        int lastEnd = -1;
        
        for(auto& it : v) {
            int currEnd = get<0>(it);
            int currStart = get<1>(it);
            int currInd = get<2>(it);
            // If meeting starts after last one ends
            if (currStart > lastEnd) {
                // Increase counter
                count++;
                // Update last end time
                lastEnd = currEnd; 
            }
        }
        return count;
    }
};