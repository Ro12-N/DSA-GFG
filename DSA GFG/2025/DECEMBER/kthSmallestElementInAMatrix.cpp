class Solution {
  public:
    int kthSmallest(vector<vector<int>> &mat, int k) {
        // code here
        int n=mat.size();
        priority_queue<tuple<int,int,int>,vector<tuple<int,int,int>>,greater<>>pq;
        for(int i=0;i<n;i++){
            pq.push({mat[i][0],i,0});
        }
        int val=-1;
        while(k--){
            auto [v,i,j]=pq.top();
            pq.pop();
            val=v;
            if(j+1<n) pq.push({mat[i][j+1],i,j+1});
        }
        return val;
    }
};

//    Time Complexity: O(k log n)
//    Space Complexity: O(n)