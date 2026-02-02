class Solution {
  public:
    vector<int> maxOfSubarrays(vector<int>& arr, int k) {
        // code here
        deque<int>dq;
        vector<int>ans;
        int n=arr.size();
        for(int i=0;i<n;i++){
            while(!dq.empty() &&arr[dq.back()]<arr[i]) dq.pop_back();
            dq.push_back(i);
            while(!dq.empty()&&i-dq.front()>=k) dq.pop_front();
            

            if(i+1>=k){
                ans.push_back(arr[dq.front()]);
            }
        }
        return ans;
    }
};
// Time Complexity: O(N)
// Space Complexity: O(K)