class Solution {
    int power(int a, int b){
        if(b==0) return 1;
        
        if(b&1) return power(a,b/2)*power(a,b/2)*a;
        return power(a,b/2)*power(a,b/2);
    }
  public:
    int RecursivePower(int n, int p) {
        // Code here
        return power(n,p);
    }
};
