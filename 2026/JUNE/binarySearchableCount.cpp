class Solution {
  public:
    int binarySearchable(vector<int>& arr) {
        // code here
        int c=0;
        int n=arr.size();
        for(int i=0;i<n;i++){
            int x=arr[i];
            int l=0;
            int r=n-1;
            while(l<=r){
                int mid=(l+r)/2;
                if(x==arr[mid]){
                    c++;
                    break;
                }
                if(arr[mid]>x){
                    r=mid-1;
                }
                else if(arr[mid]<x)
                    l=mid+1;
                
            }
        }
        return c;
    }
};
// Time Complexity: O(N log N) where N is the number of elements in the array. We perform a binary search for each element, which takes O(log N) time.
// Space Complexity: O(1) as we are using only a constant amount of extra space.