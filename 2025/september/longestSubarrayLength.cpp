class Solution {
  public:
    int longestSubarray(vector<int>& arr) {
        // code here
       int n=arr.size();
       vector<int>ngr(n,n);
       vector<int>ngl(n,-1);
       vector<int>st;
       for(int i=0;i<n;i++){
            while(!st.empty() && arr[st.back()]<arr[i]){
                int a=st.back();
                st.pop_back();
                ngr[a]=i;
            }
           st.push_back(i);
       }
       st.clear();
       for(int i=n-1;i>=0;i--){
            while(!st.empty() && arr[st.back()]<arr[i]){
                int a=st.back();
                st.pop_back();
                ngl[a]=i;
            }
           st.push_back(i);
       }
       int ans=0;
       for(int i=0;i<n;i++){
           int a=ngr[i]-ngl[i]-1;
           if(a>=arr[i]){
               ans=max(ans,a);
           }
       }
       return ans;
    }
};