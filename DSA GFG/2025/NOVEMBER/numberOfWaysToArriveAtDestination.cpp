class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {

        const long long INF = 1e18;
        vector<long long> dist(n, INF);
        vector<long long> ways(n, 0);

        vector<vector<pair<int,int>>> adj(n);
        for (auto &e : roads) {
            adj[e[0]].push_back({e[1], e[2]});
            adj[e[1]].push_back({e[0], e[2]});
        }

        // Dijkstra
        priority_queue<pair<long long,int>, 
                       vector<pair<long long,int>>,
                       greater<pair<long long,int>>> pq;

        dist[0] = 0;
        ways[0] = 1;
        pq.push({0, 0});

        long long mod = 1e9+7;

        while (!pq.empty()) {
            auto [d, node] = pq.top();
            pq.pop();

            if (d > dist[node]) continue;

            for (auto &[nei, wt] : adj[node]) {
                long long nd = d + wt;

                // Found a shorter path
                if (nd < dist[nei]) {
                    dist[nei] = nd;
                    ways[nei] = ways[node];
                    pq.push({nd, nei});
                }
                // Found another shortest path
                else if (nd == dist[nei]) {
                    ways[nei] = (ways[nei] + ways[node]) % mod;
                }
            }
        }

        return ways[n-1] % mod;
    }
};
