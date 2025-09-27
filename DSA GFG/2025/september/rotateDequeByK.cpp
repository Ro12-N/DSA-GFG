class Solution {
  public:
    void rotateDeque(deque<int>& dq, int type, int k) {
        // code here
        int n=dq.size();
          int p=k%n;
        if(type==1){
            rotate(dq.begin(),dq.end()-p,dq.end());
        }else{
            rotate(dq.begin(),dq.begin()+p,dq.end());
        }
    }
};