class Solution {
  public:
  int n,m;
  bool solve(int i,int j,vector<vector<char>> &mat, string &word,int idx){
      if(idx==word.size()) return true;
      if(i<0||j<0||i>=n||j>=m||mat[i][j]!=word[idx]) return false;
      char ch=mat[i][j];
      mat[i][j]='$';
      if(
       solve(i,j+1,mat,word,idx+1)||
       solve(i+1,j,mat,word,idx+1)||
       solve(i,j-1,mat,word,idx+1)||
       solve(i-1,j,mat,word,idx+1)) return true;
       mat[i][j]=ch;
       return false;

  }
    bool isWordExist(vector<vector<char>> &mat, string &word) {
        // Code here
         n=mat.size();
         m=mat[0].size();
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(mat[i][j]==word[0]){
                     if(solve(i,j,mat,word,0)) return true;
                }
            }
        }
        return false;
    }
};
// Time Complexity: O(N * M * 4^L) where N is number of rows, M is number of columns and L is length of the word
// Space Complexity: O(L) for recursive stack where L is length of the word