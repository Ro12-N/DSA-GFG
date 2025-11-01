class Solution {
  public:
  vector<int> solve(vector<int>&indeg,int n,unordered_map<int,vector<int>>&mp){
      vector<int>ans;
      int cnt=0;
      queue<int>q;
      for(int i=0;i<n;i++){
          if(indeg[i]==0){
              cnt++;
              ans.push_back(i);
              q.push(i);
          }
      }
      while(!q.empty()){
          int a=q.front();
          q.pop();
          for(auto v:mp[a]){
              indeg[v]--;
              if(indeg[v]==0){
                  cnt++;
                  q.push(v);
                  ans.push_back(v);
              }
          }
      }
      
      
     return (cnt==n)?ans:vector<int>{};
  }
    vector<int> findOrder(int n, vector<vector<int>> &prerequisites) {
        // code here
        unordered_map<int,vector<int>>mp;
        vector<int>indeg(n,0);
        for(auto i:prerequisites){
            int a=i[0];
            int b=i[1];
            mp[b].push_back(a);
            indeg[a]++;
        }
        return solve(indeg,n,mp);
    }
};