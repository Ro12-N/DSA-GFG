class Solution {
public:
    vector<vector<int>> kSmallestPair(vector<int>& arr1, vector<int>& arr2, int k) {
        vector<vector<int>> ans;
        int n = arr1.size(), m = arr2.size();
        if(n == 0 || m == 0 || k == 0) return ans;

        priority_queue<tuple<int,int,int>, vector<tuple<int,int,int>>, greater<>> pq;

        for(int i = 0; i < n && i < k; i++) {
            pq.push({arr1[i] + arr2[0], i, 0});
        }

        while(k-- > 0 && !pq.empty()) {
            auto [sum, i, j] = pq.top(); pq.pop();
            ans.push_back({arr1[i], arr2[j]});

            if(j + 1 < m) {
                pq.push({arr1[i] + arr2[j + 1], i, j + 1});
            }
        }

        return ans;
    }
};
