class Solution {
  public:
    int countPaths(int V, vector<vector<int>>& edges) {
        // code here
        int n=V;
        const int mod=1e9+7;
        unordered_map<int,vector<pair<int,int>>>mp;
        for(auto i:edges){
             int u=i[0];
            int v=i[1];
            int t=i[2];
            mp[u].push_back({v,t});
            mp[v].push_back({u,t});
        }
        priority_queue<pair<long long,int>,vector<pair<long long,int>>,greater<>>pq;
        vector<long long>res(n,LLONG_MAX);
        vector<long long>cnt(n,0);
        res[0]=0;
        cnt[0]=1;
        pq.push({0,0});

        while(!pq.empty()){
            auto [dist,node]=pq.top();
            pq.pop();
            for(auto &i:mp[node]){
                int nxtnode=i.first;
                int time=i.second;
                long long curr=dist+time;
                if(curr<res[nxtnode]){
                    res[nxtnode]=curr;
                    cnt[nxtnode]=cnt[node];
                    pq.push({curr,nxtnode});
                }else if(curr==res[nxtnode]){
                    cnt[nxtnode]=(cnt[nxtnode]+cnt[node])%mod;
                }
            }
        }
        return cnt[n-1];
    }
};
//Time Complexity: O(V + E * log E)
// Auxiliary Space: O(V + E)