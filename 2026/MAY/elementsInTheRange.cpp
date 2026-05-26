class Solution {
  public:
    bool checkElements(int start, int end, vector<int> &arr) {
        // code here
        int cnt=0;
        for(auto i:arr){
            if(i>=start &&i<=end) cnt++;
        }
        return (end-start+1)==cnt;
    }
};

// TC : o(n)
// SC : o(1)