class Solution {
  public:
    int maxWater(vector<int> &arr) {
        // code here
        int n=arr.size();
        vector<int>l(n);
        l[0]=arr[0];
        vector<int>r(n);
        r[n-1]=arr[n-1];
        for(int i=1;i<n;i++){
            l[i]=max(l[i-1],arr[i]);
            
        }
        for(int i=n-2;i>=0;i--){
            r[i]=max(r[i+1],arr[i]);
        }
        int ans=0;
        for(int i=0;i<n;i++){
            ans+=(min(r[i],l[i])-arr[i]);
        }
        return ans;
    }
};
//Time Complexity: O(N) where N is the size of the input array.
//Space Complexity: O(N) where N is the size of the input array.