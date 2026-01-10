class Solution {
  public:
    int kthMissing(vector<int> &arr, int k) {
        // code here
        int n=arr.size();
        int i=0;
        int j=n-1;
        while(i<=j){
            int mid=i+(j-i)/2;
            int miss=arr[mid]-(mid+1);
            if(miss<k) i=mid+1;
            else j=mid-1;
        }
        return i+k;
        
    }
};
//    Time Complexity: O(log N)
//    Space Complexity: O(1)