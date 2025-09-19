class Solution {
  public:
    vector<int> nextGreater(vector<int> &arr) {
        // code here
        int n=arr.size();
        vector<int>ans(n,-1);
        vector<int>curr;
        for(int i=0;i<2*n;i++){
             while(!curr.empty() && arr[curr.back()]<arr[i%n]){
                   int a=curr.back();
                   curr.pop_back();
                   ans[a]=arr[i%n];
             }
             if(i<n)
             curr.push_back(i%n);
        }
        return ans;
    }
};