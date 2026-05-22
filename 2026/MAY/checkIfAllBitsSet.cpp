class Solution {
  public:
    bool isBitSet(int n) {
        // code here
       if(n==0) return false;
       return ((n+1) &(n)) ==0;
    }
};
// TC : o(1)
// SC : o(1)