class Solution {
  public:
  int n;
  vector<string>ans;
  bool chk(string s){
      if(s[0]=='0') return false;
      int v=stoi(s);
      return v<=255;
  }
  void solve(int idx,int p,string &s,string curr){
      if(idx==n){
          if(p==4){
              curr.pop_back();
              ans.push_back(curr);
          }
          return;
      }
      if(idx+1<=n){
          solve(idx+1,p+1,s,curr+s.substr(idx,1)+'.');
      }
      if(idx+2<=n&&chk(s.substr(idx,2))){
          solve(idx+2,p+1,s,curr+s.substr(idx,2)+'.');
      }
      if(idx+3<=n&&chk(s.substr(idx,3))){
          solve(idx+3,p+1,s,curr+s.substr(idx,3)+'.');
      }
  }
    vector<string> generateIp(string &s) {
        // code here
        n=s.size();
        ans.clear();
        if(n>12) return ans;
        string curr="";
        solve(0,0,s,curr);
        return ans;
        
        
    }
};
// Time Complexity: O(1) since the number of valid IP addresses is limited.
// Space Complexity: O(1) since the number of valid IP addresses is limited.