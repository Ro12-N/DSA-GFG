class Solution {
  public:
    int orangesRot(vector<vector<int>>& mat) {
        // code here
        int f=0;
        int n=mat.size();
        int m=mat[0].size();
        queue<pair<int,int>>q;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(mat[i][j]==2){
                    mat[i][j]=0;
                    q.push({i,j});
                }else if(mat[i][j]==1) f++;
            }
        }
        if(f==0) return 0;
        int len=1;
        vector<vector<int>>dir={{-1,0},{1,0},{0,1},{0,-1}};
        while(!q.empty()){
            int s=q.size();
            while(s--){
                auto [i,j]=q.front();
                q.pop();
                for(int d=0;d<4;d++){
                    int ni=i+dir[d][0];
                    int nj=j+dir[d][1];
                    if(ni>=0 &&nj>=0 &&ni<n &&nj<m && mat[ni][nj]==1){
                        mat[ni][nj]=0;
                        f--;
                        if(f==0) return len;
                        q.push({ni,nj});
                    }
                }
            }
            
            
            
            
            len++;
            
        }
        return -1;
    }
};
// Time Complexity: O(n*m) where n and m are the dimensions of the grid.
// Space Complexity: O(n*m) in the worst case when all oranges are rotten and added to the queue.