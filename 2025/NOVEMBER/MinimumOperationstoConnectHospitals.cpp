class Solution {
public:
    void dfs(int node, vector<vector<int>>& adj, vector<int>& vis){
        vis[node] = 1;
        for(int nxt : adj[node]){
            if(!vis[nxt]) dfs(nxt, adj, vis);
        }
    }

    int minConnect(int V, vector<vector<int>>& edges) {
        
        int E = edges.size();
        if (E < V - 1) return -1;

        vector<vector<int>> adj(V);
        for (auto &e : edges) {
            int u = e[0], v = e[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        vector<int> vis(V, 0);
        int components = 0;

        for (int i = 0; i < V; i++) {
            if (!vis[i]) {
                components++;
                dfs(i, adj, vis);
            }
        }

        return components - 1;
    }
};
