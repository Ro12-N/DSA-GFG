class Solution {
  public:
    bool isPower(int x, int y) {
        // code here
       if(y==1) return 1;
       if(x==1) return y==1;
       while(y%x==0){
           y/=x;
       }
       return y==1;
    }
};
// Time Complexity: O(log(y)) where y is the input number
// Space Complexity: O(1) as we are using only a constant amount of extra space