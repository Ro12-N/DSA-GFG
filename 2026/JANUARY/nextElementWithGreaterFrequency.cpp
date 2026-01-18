class Solution {
  public:
    vector<int> nextFreqGreater(vector<int>& arr) {
        // code here
        unordered_map<int,int>mp;
        for(auto i:arr){
            mp[i]++;
        }
        int n=arr.size();
        stack<pair<int,int>>st;
        vector<int>ans(n,-1);
        for(int i=0;i<n;i++){
            while(!st.empty() && st.top().first<mp[arr[i]]){
                auto [f,idx]=st.top();
                st.pop();
                ans[idx]=arr[i];
            }
            st.push({mp[arr[i]],i});
        }
        return ans;
    }
};
// Time Complexity: O(N) where N is the size of the array
// Space Complexity: O(N)