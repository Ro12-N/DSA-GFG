class Solution {
  public:
    int hIndex(vector<int>& citations) {
        // code here
        int n=citations.size();
        vector<int>cnt(n+1,0);
        for(auto i:citations){
            cnt[min(i,n)]++;
        }
        int a=0;
        for(int i=n;i>=0;i--){
             a+=cnt[i];
             if(a>=i) return i;
        }
        return 0; 
    }
};
// Time Complexity: O(n) due to the single pass through the citations array and the counting array
// Space Complexity: O(n) due to the counting array used to store the frequency of citations