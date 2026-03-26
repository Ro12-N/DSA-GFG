class Solution {
  public:
    vector<int> minHeightRoot(int V, vector<vector<int>>& edges) {
        int n=V;
        if(n == 1) return {0};

        vector<vector<int>> adj(n);
        vector<int> degree(n, 0);

        for(auto &e : edges){
            int u = e[0], v = e[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
            degree[u]++;
            degree[v]++;
        }

        queue<int> q;

        for(int i = 0; i < n; i++){
            if(degree[i] == 1){
                q.push(i);
            }
        }

        vector<int> ans;

        while(!q.empty()){
            int size = q.size();
            ans.clear(); 

            while(size--){
                int node = q.front();
                q.pop();
                ans.push_back(node);

                for(auto nei : adj[node]){
                    degree[nei]--;
                    if(degree[nei] == 1){
                        q.push(nei);
                    }
                }
            }
        }

        return ans;
    }
};
