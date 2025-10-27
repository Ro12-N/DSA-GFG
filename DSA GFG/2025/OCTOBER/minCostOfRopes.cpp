class Solution {
  public:
    int minCost(vector<int>& arr) {
        // code here
        priority_queue<int,vector<int>,greater<int>>pq(arr.begin(),arr.end());
        int ans=0;
        while(pq.size()>=2){
            int a=pq.top();
            pq.pop();
            int b=pq.top();
            pq.pop();
            int cost=a+b;
            pq.push(cost);
            ans+=cost;
      }
      return ans;
        
    }
};

//O(nlogn)