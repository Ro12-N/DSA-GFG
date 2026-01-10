class Solution {
  public:
  vector<vector<int>>ans;
  void solve(int s,int k,int t,vector<int>temp){
      if(temp.size()==k){
         if(t==0) ans.push_back(temp);
         return;
       
      }
      for(int i=s;i<10;i++){
            if(i>t) break;
            temp.push_back(i);
            solve(i+1,k,t-i,temp);
            temp.pop_back();
      }
  }
    vector<vector<int>> combinationSum(int n, int k) {
        // code here
        vector<int>temp;
        solve(1,k,n,temp);
        return ans;
    }
};