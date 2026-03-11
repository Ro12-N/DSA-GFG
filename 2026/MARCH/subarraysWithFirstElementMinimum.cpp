class Solution {
  public:
    int countSubarrays(vector<int> &arr) {
        // code here
        int n=arr.size();
        vector<int>rs(n,n);
        stack<int>st;
        for(int i=0;i<n;i++){
            
            while(!st.empty() && arr[st.top()]>arr[i]){
                int idx=st.top();
                st.pop();
                rs[idx]=i;
            }
            
            
            st.push(i);
            
        }
        int ans=0;
        for(int i=0;i<n;i++){
            ans+=rs[i]-i;
        }
        return ans;
        
    }
};
// Time Complexity: O(N) where N is the size of the input array.
// Space Complexity: O(N) where N is the size of the input array, used for the stack and the rs vector.