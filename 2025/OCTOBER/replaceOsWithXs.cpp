class Solution {
  public:

int n,m;
void solve(vector<vector<char>>&grid,int i,int j){
    vector<vector<int>>dir={{-1,0},{1,0},{0,1},{0,-1}};
    queue<pair<int,int>>qu;
    qu.push({i,j});
    grid[i][j]='*';
    while(!qu.empty()){
        auto [p,q]=qu.front();
        qu.pop();
        for(auto d:dir){
            int pi=p+d[0];
            int qi=q+d[1];
            if(pi>=0 && pi<n &&qi>=0 &&qi<m && grid[pi][qi]=='O'){
                qu.push({pi,qi});
                grid[pi][qi]='*';
            }
        }
    }
}

    void fill(vector<vector<char>>& grid) {
        // Code here
         n=grid.size();
         m=grid[0].size();
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(i==0||j==0||i==n-1||j==m-1){
                    if(grid[i][j]=='O'){
                        solve(grid,i,j);
                    }
                }
            }
            
        }
            for(int i=0;i<n;i++){
                for(int j=0;j<m;j++){
                    grid[i][j]=(grid[i][j]=='*'?'O':'X');
                }
            }
        }
       
};