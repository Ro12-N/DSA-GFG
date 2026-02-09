class Solution {
  public:
    int findKRotation(vector<int> &arr) {
        int i=0;
        int j=arr.size()-1;
        while(i<j && arr[i]>arr[j]){
            i++;
        }
        return i;
    }
};
// Time Complexity: O(logN) where N is the size of the input array
// Space Complexity: O(1)


// Another approach using binary search
class Solution {
  public:
    int findKRotation(vector<int> &arr) {
        // Code Here
        int n=arr.size();
        int s=0;
        int e=n-1;
        while(s<=e){
            if(arr[s]<=arr[e]) return s;
            int mid=s+(e-s)/2;
            int nxt=(mid+1)%n;
            int prev=(mid-1+n)%n;
            if(arr[mid]<=arr[nxt] && arr[mid]<=arr[prev]) return mid;
            
            
            if(arr[mid]<=arr[e]) e=mid-1;
            else s=mid+1;
        }
        return 0;
    }
};
// Time Complexity: O(logN) where N is the size of the input array
// Space Complexity: O(1)