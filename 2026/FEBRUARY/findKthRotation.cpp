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