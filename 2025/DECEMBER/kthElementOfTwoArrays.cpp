class Solution {
  public:
    int kthElement(vector<int> &a, vector<int> &b, int k) {
        // code here
        int i=0;
        int j=0;
        int n=a.size();
        int m=b.size();
        int curr;
        while(i<n ||j<m){
            int av=(i<n)?a[i]:INT_MAX;
            int bv=(j<m)?b[j]:INT_MAX;
            curr=min(av,bv);
            if((--k) ==0) return curr;
            if(av<bv) i++;
            else j++;
        }
        return curr;
    }
};

// Time Complexity: O(k)
// Space Complexity: O(1)