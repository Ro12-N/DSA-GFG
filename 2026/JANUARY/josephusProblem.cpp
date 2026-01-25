class Solution {
  public:
  int find(int n,int k){
      if(n==1) return 0;
      int idx=find(n-1,k);
      idx=(idx+k)%n;
      return idx;
  }
    int josephus(int n, int k) {
        // code here
        // deque<int>q;
        // for(int i=1;i<=n;i++){
        //     q.push_back(i);
        // }
        // while(q.size()>1){
        //     int p=k-1;
        //     while(p--){
        //         q.push_back(q.front());
        //         q.pop_front();
        //     }
        //     q.pop_front();
        // }
        // return q.front();
        int ans=find(n,k);
        return ans+1;
    }
};
// Time Complexity: O(N)
// Space Complexity: O(N) for recursive stack