class Solution {
  public:
    int maxCircularSum(vector<int> &arr) {
        // code here
        int n=arr.size();
        int kmin=arr[0];
        int kmax=arr[0];
        int sum=arr[0];
        int sum2=arr[0];
        int ts=arr[0];
        for(int i=1;i<n;i++){
            ts+=arr[i];
            sum=min(sum+arr[i],arr[i]);
            sum2=max(sum2+arr[i],arr[i]);
            kmax=max(kmax,sum2);
            kmin=min(kmin,sum);
        }
        if(kmax<0) return kmax;
        return max(kmax,ts-kmin);


    }
};
// Time Complexity: O(N)
// Space Complexity: O(1)