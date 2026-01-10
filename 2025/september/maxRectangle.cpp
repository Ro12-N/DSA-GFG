class Solution {
  public:
  int solve(vector<int>&curr){
      int n=curr.size();
      vector<int>nsr(n,n);
      vector<int>nsl(n,-1);
      vector<int>st;
      for(int i=0;i<n;i++){
          while(!st.empty() && curr[st.back()]>curr[i]){
              int a=st.back();
              st.pop_back();
              nsr[a]=i;
          }
          st.push_back(i);
      }
      st.clear();
      for(int i=n-1;i>=0;i--){
          while(!st.empty() && curr[st.back()]>curr[i]){
              int a=st.back();
              st.pop_back();
              nsl[a]=i;
          }
          st.push_back(i);
      }
      int ans=0;
      for(int i=0;i<n;i++){
          int dist=nsr[i]-nsl[i]-1;
          ans=max(ans,dist*curr[i]);
      }
      return ans;
      
      
      
  }
    int maxArea(vector<vector<int>> &mat) {
        // code here
        int n=mat.size();
        int m=mat[0].size();
        for(int j=0;j<m;j++){
            int cnt=0;
            for(int i=0;i<n;i++){
                if(mat[i][j]){
                    cnt++;
                }else cnt=0;
                mat[i][j]=cnt;
            }
        }
        int ans=0;
        for(auto i:mat){
            ans=max(ans,solve(i));
        }
        return ans;
    }
};