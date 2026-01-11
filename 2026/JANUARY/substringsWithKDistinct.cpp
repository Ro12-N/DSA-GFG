class Solution {
  public:
  int solve(string &s,int k){
      if(k<0) return 0;
      int i=0;
      int j=0;
      int n=s.size();
      int ans=0;
      int cnt=0;
      vector<int>v(26,0);
      while(j<n){
          if(v[s[j]-'a']==0) cnt++;
          v[s[j]-'a']++;
          while(cnt>k){
              if(--v[s[i]-'a']==0) cnt--;
              i++;
          }
          ans+=j-i+1;
          j++;
      }
      return ans;
  }
    int countSubstr(string& s, int k) {
        // code here
        return solve(s,k)-solve(s,k-1);
    }
};
// TC: O(N)
// SC: O(1)