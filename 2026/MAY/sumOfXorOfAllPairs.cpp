class Solution {
  public:
    long long sumXOR(vector<int> &arr) {
        // code here
        long long ans=0;
        int n=arr.size();
        for(int bit=0;bit<32;bit++){
            long long a=0;
            long long b=0;
            for(int i=0;i<n;i++){
                if(arr[i]&(1<<bit)) a++;
            }
            b=n-a;
            ans+=(a*b*(1LL<<bit));
            
            
        }
        return ans;
    }
};
//Time Complexity: O(N*32) where N is the size of the input array.
//Space Complexity: O(1) as we are using only constant extra space.