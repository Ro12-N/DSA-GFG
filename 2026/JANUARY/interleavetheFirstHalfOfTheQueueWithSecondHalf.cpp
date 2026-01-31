class Solution {
  public:
    void rearrangeQueue(queue<int> &q) {
        // code here
        int n=q.size();
        queue<int>temp;
        for(int i=0;i<n/2;i++){
            temp.push(q.front());
            q.pop();
        }
        while(!temp.empty()){
            q.push(temp.front());
            temp.pop();
            q.push(q.front());
            q.pop();
        }
       
        
        
    }
};
// time complexity: O(N) where N is the number of elements in the queue
// space complexity: O(N) for the temporary queue used to store the first half of the elements