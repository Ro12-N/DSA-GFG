class Solution {
  public:
    int maxAmount(vector<int>& arr, int k) {
        // code here
        priority_queue<int>pq(arr.begin(),arr.end());
        int mod=1e9+7;
        int ans=0;
        while(k-- && !pq.empty()){
            int curr=pq.top();
            pq.pop();
            ans=(ans+curr)%mod;
            curr--;
            if(curr) pq.push(curr);
        }
        return ans;
    }
};
// Time Complexity: O(klogn) where n is the size of the array
// Space Complexity: O(n) for the priority queue