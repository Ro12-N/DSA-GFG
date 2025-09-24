class Solution {
  public:
    void reverseQueue(queue<int> &q) {
        // code here
        int n=q.size();
        stack<int>st;
        for(int i=0;i<n-1;i++){
           st.push(q.front());
           q.pop();
        }
        while(!st.empty()){
            q.push(st.top());
            st.pop();
        }
    }
};