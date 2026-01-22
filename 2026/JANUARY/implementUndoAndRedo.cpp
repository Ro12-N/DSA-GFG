class Solution {
  public:
  string ans="";
  string r="";
    void append(char x) {
        // append x into document
        ans+=x;
    }

    void undo() {
        // undo last change
        if(!ans.empty()){
            char ch=ans.back();
            ans.pop_back();
            r+=ch;
        }
    }

    void redo() {
        // redo changes
        if(!r.empty()){
           ans+=r.back();
           r.pop_back();
        }
    }

    string read() {
        // read the document
        return ans;
    }
};
// Time Complexity: O(1) for each operation
// Space Complexity: O(N) where N is the number of operations performed