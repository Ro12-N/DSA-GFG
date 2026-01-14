class Solution {
  public:
    bool canServe(vector<int> &arr) {
        // code here
        int f=0;
        int t=0;
        for(int i=0;i<arr.size();i++){
            if(arr[i]==5) f++;
            else if(arr[i]==10){
                t++;
                if(f==0) return false;
                f--;
            }else{
                if(t>=1 &&f>=1){
                    t--;
                    f--;
                }else if(f>2){
                    f-=3;
                }else return false;
            }
            
        }
        
        
        
        return true;
    }
};

// Time Complexity: O(N) where N is the length of arr
// Space Complexity: O(1)