class Solution {
  public:
    int minJumps(vector<int>& arr) {
        // code here
        if(arr[0]==0) return -1;
         int l=0;
        int r=0;
        int cnt=0;
        int n=arr.size();
        if(n<=1) return 0;
        while(r<n-1){
            int far=0;
            for(int i=l;i<=r;i++){
                far=max(far,i+arr[i]);
            }
            if(far<=r) return -1;
            l=r+1;
            r=far;
            cnt++;
        }
        return cnt;
    }
};
