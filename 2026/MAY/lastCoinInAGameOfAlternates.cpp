class Solution {
  public:
    int coin(vector<int>& arr) {
        // code here
        int n=arr.size();
       int i=0;
       int j=n-1;
       while(i<j){
           if(arr[i]<=arr[j]) j--;
           else i++;
       }
       return arr[i];
    }
};
// TC : o(n)
// SC : o(1)    