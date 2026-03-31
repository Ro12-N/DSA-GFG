class Solution {
  public:
    int minCost(vector<vector<int>>& houses) {
        // code here
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<>>pq;
        int n=houses.size();
        unordered_map<int,vector<pair<int,int>>>mp;
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                int x1=houses[i][0];
                int y1=houses[i][1];
                int x2=houses[j][0];
                int y2=houses[j][1];
                int dist=abs(x1-x2)+abs(y1-y2);
                mp[i].push_back({j,dist});
                mp[j].push_back({i,dist});
            }
        }
        pq.push({0,0});
        int sum=0;
        vector<int>vis(n,0);
        while(!pq.empty()){
            auto [d,node]=pq.top();
            pq.pop();
            if(vis[node]) continue;
            vis[node]=true;
            sum+=d;
            for(auto v:mp[node]){
                int nxt=v.first;
                int val=v.second;
                if(!vis[nxt])
                pq.push({val,nxt});
            }
        }
        return sum;
    }
};
// Time Complexity: O(n^2 log n)
// Auxiliary Space: O(n^2)