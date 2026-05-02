class Solution {
  public:
    vector<int> kthLargest(vector<int>& arr, int k) {
        // code here
        int n=arr.size();
        priority_queue<int,vector<int>,greater<int>>pq;
        vector<int>ans;
        for(auto i:arr){
            pq.push(i);
            if(pq.size()>k) pq.pop();
            if(pq.size()==k) ans.push_back(pq.top());
            else ans.push_back(-1);
        }
        return ans;
        
    }
};
// Time Complexity: O(n log k) where n is the number of elements in the input array and k is the size of the priority queue.
// Space Complexity: O(k) for the priority queue that holds at most k elements.