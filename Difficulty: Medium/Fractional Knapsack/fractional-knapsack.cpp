class Solution {
public:
    double fractionalKnapsack(vector<int>& val, vector<int>& wt, int capacity) {
        int n = val.size();
        vector<pair<double, int>> items;
        for(int i = 0; i < n; i++){
            items.push_back({(double)val[i] / wt[i], i});
        }
        sort(items.rbegin(), items.rend());

        double max_val = 0.0;
        double cap = capacity;
        for(auto &it : items){
            int i = it.second;
            if(cap >= wt[i]){
                max_val += val[i]; cap -= wt[i];
            }else{
                max_val += it.first * cap; break;
            }
        }
        return max_val;
    }
};
