class Solution {
  public:

    vector<int> countBSTs(vector<int>& arr) {
        // Code here
       int n=arr.size();
       vector<int>st=arr;
       sort(st.begin(),st.end());
       unordered_map<int,int>mp;
       for(int i=0;i<n;i++){
           mp[st[i]]=i;
       }
       vector<int>ans;
       vector<int>c(n+1);
       c[0]=1;
       for(int i=0;i<n;i++){
         c[i+1]=c[i]*2*(2*i+1)/(i+2);
       }
       
       
       for(int i=0;i<n;i++){
           int l=mp[arr[i]];
           int r=n-l-1;
           ans.push_back(c[l]*c[r]);
       }
       
       
       return ans;
    }
};
//TC: O(nlogn) for sorting and O(n) for counting BSTs, overall O(nlogn)
//SC: O(n) for storing the count of BSTs and the mapping of elements to their indices.