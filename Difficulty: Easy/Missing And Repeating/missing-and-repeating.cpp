#define ll long long int 
class Solution {
  public:
    vector<int> findTwoElement(vector<int>& arr) {
        // code here
        int n = arr.size();
        ll Sn = ((ll)n*(n+1))/2;
        ll S2n = ((ll)n*(n+1)*(2*n+1))/6;
        
        ll S = 0, S2 = 0;
        for(int &val: arr){
            S += (ll)val; S2 += (ll)val * (ll)val;
        }
        
        // X is the repeating number and Y is the missing number
        ll xMinusY = S - Sn;
        ll xPlusY = (S2 - S2n)/xMinusY;
        
        ll X = (xPlusY + xMinusY)/2, Y = (xPlusY - xMinusY)/2;
        
        return {int(X), int(Y)};
    }
};