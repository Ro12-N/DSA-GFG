class Solution {
  public:
  void solve(int n,int o,int c,int &cnt){
      if(o==n &&c==n){
          cnt++;
          return;
      }
      if(o<n) solve(n,o+1,c,cnt);
      if(c<o) solve(n,o,c+1,cnt);
  }
    int findWays(int n) {
        // code here
        if(n%2) return 0;
      int  cnt=0;
        solve(n/2,0,0,cnt);
        return cnt;
    }
};
// Time Complexity: O(2^N)
// Space Complexity: O(N) for recursive stack


class Solution {
  public:
    int findWays(int n) {
        // code here
        if(n%2) return 0;
        int k=n/2;
        int res=1;
        for(int i=0;i<k;i++){
            res=res*(4*i+2)/(i+2);
        }
        return res;
    }
};
// Time Complexity: O(N)
// Space Complexity: O(1)