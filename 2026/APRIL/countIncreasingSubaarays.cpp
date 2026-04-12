class Solution {
  public:
    int countIncreasing(vector<int>& arr) {
        // code here.
        int ans=0;
        int cnt=0;
        for(int i=1;i<arr.size();i++){
            if(arr[i-1]<arr[i]) cnt++;
            else cnt=0;
            if(cnt>0) ans+=cnt;
        }
        return ans;
    }
};

// Time Complexity: O(n) where n is the size of the input array
// Space Complexity: O(1) as we are using only a constant amount of extra space
