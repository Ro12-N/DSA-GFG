class Solution {
  public:
    void find(vector<int>&arr, vector<int>&ngr){
        int n=arr.size();
        stack<int>st;
        for(int i=0; i<n; i++){
            while(!st.empty() && arr[i]>=arr[st.top()]){
                ngr[st.top()]+=i-st.top();
                st.pop();
            }
            st.push(i);
        }
        while(!st.empty()){
            ngr[st.top()]+=n-st.top();
            st.pop();
        }
    }
    int maxPeople(vector<int> &arr) {
        int n=arr.size();
        vector<int>ngr(n,0);
        find(arr,ngr);
        reverse(arr.begin(),arr.end());
        reverse(ngr.begin(),ngr.end());
        find(arr,ngr);
        int ans=0;
        for(auto it:ngr){
            ans=max(ans,it-1);
        }
        return ans;
    }
};

// Time Complexity: O(N) where N is the size of the array
// Space Complexity: O(N) for stack and auxiliary arrays usage
// The approach uses the concept of Next Greater Element (NGE) to determine how many people can be seen in a line from each position.