class Solution {
  public:
    void sort012(vector<int>& arr) {
        // code here
        int i=0;
        int k=0;
        int j=arr.size()-1;
        while(k<=j){
            if(arr[k]==0){
                swap(arr[i],arr[k]);
                i++;
                k++;
            }
            else if(arr[k]==1) k++;
            else {
                swap(arr[k],arr[j]);
                j--;
            }
        }
        
        
    }
};
// Time Complexity: O(N)
// Space Complexity: O(1)