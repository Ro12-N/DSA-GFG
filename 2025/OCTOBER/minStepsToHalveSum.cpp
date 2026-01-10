class Solution {
  public:
    int minOperations(vector<int>& arr) {
        // code here
        double ts=accumulate(arr.begin(),arr.end(),0.0);
        double half=ts/2.0;
        priority_queue<double>pq;
        for(auto i:arr){
            pq.push(1.0*i);
        }
        int cnt=0;
        while(!pq.empty()){
            cnt++;
            double a=pq.top();
            pq.pop();
            ts-=(a/2.0);
            pq.push(a/2.0);
            if(ts<=half) return cnt;
        }
        return -1;
    }
};

//O(nlogn)
//O(n)