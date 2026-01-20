class Solution {
  public:
    string removeKdig(string &s, int k) {
        // code here
        deque<char>dq;
        for(auto i:s){
            while(!dq.empty()&& dq.back()>i &&k>0){
                dq.pop_back();
                k--;
            }
            dq.push_back(i);
        }
        while(k>0 &&!dq.empty()){
            k--;
            dq.pop_back();
        }
        string ans="";
        while(!dq.empty()){
            ans+=dq.front();
            dq.pop_front();
        }
        int idx=0;
        while(idx<ans.size() &&ans[idx]=='0') idx++;
        ans=ans.substr(idx);
        if(ans.empty()) return "0";
        return ans;
       
    }
};
// Time Complexity: O(N) where N is the length of the string
// Space Complexity: O(N)