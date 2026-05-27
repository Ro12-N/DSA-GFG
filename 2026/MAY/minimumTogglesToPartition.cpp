class Solution {
  public:
    int minToggle(vector<int>& arr) {
        // code here
       int t=0;
       int num=0;
       for(auto i:arr){
           if(i) num++;
           else t=min(t+1,num);
       }
       return t;
        
    }
};
// TC : o(n)
// SC : o(1)