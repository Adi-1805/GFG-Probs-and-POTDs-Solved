class Solution {
  public:
    int countDigits(int n) {
        // code here
        return log10(n)+1;
    }
};