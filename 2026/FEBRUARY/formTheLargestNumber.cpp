class Solution {
  public:
    string findLargest(vector<int> &arr) {
        // code here
        vector<string>curr;
        for(auto i:arr){
            curr.push_back(to_string(i));
        }
        sort(curr.begin(),curr.end(),[](string &a,string &b){
               string p=a+b;
               string q=b+a;
               return p>q;
        });
        if(curr[0]=="0") return "0";
        string ans="";
        for(auto i:curr){
            ans+=i;
        }
        return ans;
    }
};
// Time Complexity: O(n log n) due to the sorting of the array of strings
// Space Complexity: O(n) due to the additional vector of strings created from the input array