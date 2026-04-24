class Solution {
  public:
    bool canSplit(vector<int>& arr) {
        // code here
        int sum=accumulate(arr.begin(),arr.end(),0);
        int curr=0;
        for(auto i:arr){
            curr+=i;
            if(2*curr==sum) return true;
        }
        return false;
    }
};

// Time Complexity: O(n) where n is the size of the input array
// Space Complexity: O(1) as we are using only a constant amount of extra space