class Solution {
  public:
    int findPosition(int n) {
        // code here
        if((n&(n-1))|| n==0) return -1;
        for(int i=0;i<32;i++){
            if(n & (1<<i)) return i+1;
        }
        return -1;
    }
};
// TC : O(32)
// SC:O(1)