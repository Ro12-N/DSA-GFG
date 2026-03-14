
class Solution {
  public:
    int sumSubMins(vector<int> &arr) {
        // code here
        int n=arr.size();
        stack<int>st;
        vector<int>nsl(n,-1);
       vector<int>nsr(n,n);

        for(int i=0;i<n;i++){
            while(!st.empty() && arr[st.top()]>arr[i]){
                int idx=st.top();
                st.pop();
                nsr[idx]=i;
            }
            st.push(i);
        }
        while(!st.empty()) st.pop();
         for(int i=n-1;i>=0;i--){
            while(!st.empty() && arr[st.top()]>=arr[i]){
                int idx=st.top();
                st.pop();
                nsl[idx]=i;
            }
            st.push(i);
        }
        
        int sum=0;
        for(int i=0;i<n;i++){
            int a=i-nsl[i];
            int b=nsr[i]-i;
            sum+=(a*b*arr[i]);
        }
        return sum;
    }
};
// Time Complexity: O(N) where N is the size of the input array.
// Space Complexity: O(N) where N is the size of the input array, used for the stack and the nsl and nsr vectors.