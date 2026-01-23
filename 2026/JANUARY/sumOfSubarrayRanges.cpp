class Solution {
  public:
  int n;
pair<vector<int>,vector<int>> solve(bool flag,vector<int>&nums){
        stack<int> st;
        vector<int> nsl(n), nsr(n);

        for(int i = 0; i < n; i++) {
    while(!st.empty() && (flag? nums[st.top()] > nums[i]:nums[st.top()] < nums[i])) st.pop();
            nsl[i] = st.empty() ? -1 : st.top();
            st.push(i);
        }

        while(!st.empty()) st.pop();

        for(int i = n - 1; i >= 0; i--) {
            while(!st.empty() &&(flag? nums[st.top()] >= nums[i]: nums[st.top()] <= nums[i])) st.pop();
            nsr[i] = st.empty() ? n : st.top();
            st.push(i);
        }

        while(!st.empty()) st.pop();
        return {nsl,nsr};
}
    int subarrayRanges(vector<int>& arr) {
        // code here
        n=arr.size();
        auto [nsl,nsr]=solve(1,arr);
        auto [nll,nlr]=solve(0,arr);
        long long ans=0;
        for(int i=0;i<n;i++){
            long long cntmin=(i-nsl[i])*(nsr[i]-i);
            long long cntmax=(i-nll[i])*(nlr[i]-i);
            ans+=(cntmax-cntmin)*(arr[i]);
        }
        return ans;
    }
};
// Time Complexity: O(N) where N is the size of the array
// Space Complexity: O(N) for stack and auxiliary arrays usage