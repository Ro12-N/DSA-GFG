class Solution {
  public:
    vector<int> calculateSpan(vector<int>& arr) {
        int n=arr.size();
        vector<int>ans(n,1);
        stack<pair<int,int>>st;
        for(int i=0;i<n;i++){
            int cnt=1;
            while(!st.empty() && arr[st.top().first]<=arr[i]){
                auto [idx,c]=st.top();
                ans[idx]=c;
                cnt+=c;
                st.pop();
                
            }
            st.push({i,cnt});
            
            
            
        }
        while(!st.empty()){
            auto [idx,c]=st.top();
            st.pop();
            ans[idx]=c;
        }
        return ans;
    }
};
// Time Complexity: O(N) where N is the number of days
// Space Complexity: O(N) for stack usage