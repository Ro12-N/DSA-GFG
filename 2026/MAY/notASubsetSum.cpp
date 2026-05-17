class Solution {
  public:
    int findSmallest(vector<int> &arr) {
        // code here.
        sort(arr.begin(),arr.end());
        int res=1;
         for(auto i:arr){
             if(i>res) break;
             res+=i;
         }
         return res;
    }
};
// TC : O(N LOGN)
// SC : O(1)