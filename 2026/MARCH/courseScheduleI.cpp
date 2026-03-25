class Solution {
  public:
    bool canFinish(int n, vector<vector<int>>& prerequisites) {
        // Code here
        queue<int>q;
        unordered_map<int,vector<int>>mp;
        vector<int>indeg(n,0);
        for(auto &i:prerequisites){
            mp[i[1]].push_back(i[0]);
            indeg[i[0]]++;
        }
        int cnt=0;
        for(int i=0;i<n;i++){
            if(indeg[i]==0){
                cnt++;
                q.push(i);
            }
        }
        while(!q.empty()){
            int a=q.front();
            q.pop();
            for(auto j:mp[a]){
                indeg[j]--;
                if(indeg[j]==0){
                    cnt++;
                    q.push(j);
                }
            }
        }
        return cnt==n;
        
        
    }
};
// Time Complexity: O(V + E) where V is the number of courses and E is the number of prerequisites.
// Space Complexity: O(V + E) for the adjacency list and indegree array.