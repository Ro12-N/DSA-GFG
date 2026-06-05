class Solution {
  public:
    int maxSubstring(string &s) {
        // code here
        int curr=0;
        int ans=-1;
        for(auto i:s){
            curr+=(i=='0')?1:-1;
            ans=max(ans,curr);
            if(curr<0) curr=0;
        }
        return ans;
    }
};
// Time Complexity: O(N) where N is the length of the input string. We traverse the string once to calculate the maximum substring length.
// Space Complexity: O(1) as we are using only a constant amount of extra space