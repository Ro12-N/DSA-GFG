class Solution {
  public:
    vector<int> freqInRange(vector<int>& arr, vector<vector<int>>& queries) {
        // code here
        unordered_map<int,vector<int>>mp;
        int n=arr.size();
        for(int i=0;i<n;i++){
            mp[arr[i]].push_back(i);
        }
        vector<int>ans;
        for(auto i:queries){
            int s=i[0];
            int e=i[1];
            int x=i[2];
            
            auto &v=mp[x];
            int val=upper_bound(v.begin(),v.end(),e)-lower_bound(v.begin(),v.end(),s);
            ans.push_back(val);
        }
        return ans;
    }
};
// Time Complexity: O(NlogN + QlogN) where N is the size of the input array and Q is the number of queries. The first part O(NlogN) is for building the frequency map, and the second part O(QlogN) is for processing each query using binary search.
// Space Complexity: O(N) for storing the frequency map, where N is the size of the input array.