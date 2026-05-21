class Solution {
  public:
    int minSteps(vector<int>& arr, int start, int end) {
        // code here
        queue<int>q;
        vector<int>dist(1000,-1);
        q.push(start);
        dist[start]=0;
        while(!q.empty()){
            int f=q.front();
            q.pop();
            if(f==end) return dist[f];
            for(auto i:arr){
                int curr=(f*i)%1000;
                if(dist[curr]==-1){
                    dist[curr]=dist[f]+1;
                    q.push(curr);
                }
            }
        }
        return -1;
    }
};
// TC : o(N)
// SC : o(N)