class Solution {
  public:
    vector<string> graycode(int n) {
        // code here
        vector<string>ans;
        for(int i=0;i<(1<<n);i++){
          int curr=i^(i>>1);
          string pr="";
         for(int j=n-1;j>=0;j--){
             if(curr&(1<<j)) pr+='1';
             else pr+='0';
         }
          ans.push_back(pr);
        }
        return ans;
    }
};
// Time Complexity: O(n*2^n)
// Space Complexity: O(n*2^n)