class Solution {
    int findGCD(int a, int b) {
        if (a == 0)
            return b;
        return findGCD(b % a, a);
    }
  public:
    int gcd(int a, int b) {
        // code here
        return findGCD(a,b);
    }
};
