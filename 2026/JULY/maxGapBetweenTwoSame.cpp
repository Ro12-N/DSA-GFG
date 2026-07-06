class Solution {
  public:
    int maxCharGap(string &s) {
        // code here
        int n=s.size();
        vector<int>ans(26,-1);
        int res=-1;
        for(int i=n-1;i>=0;i--){
            int idx=s[i]-'a';
            if(ans[idx]==-1) ans[idx]=i;
            else{
                res=max(res,ans[idx]-i-1);
            }
        }
        return res;
    }
};
// Time Complexity: O(n)
// Space Complexity: O(1)