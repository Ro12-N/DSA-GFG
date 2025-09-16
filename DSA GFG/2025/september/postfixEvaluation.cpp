class Solution {
public:
    int evaluatePostfix(vector<string>& arr) {
        stack<int> st;
        for (auto &i : arr) {
            if (i.size() > 1 || isdigit(i[0])) {
                st.push(stoi(i));
            } else {
                int right = st.top(); st.pop();
                int left = st.top(); st.pop();

                if (i == "+") {
                    st.push(left + right);
                } else if (i == "-") {
                    st.push(left - right);
                } else if (i == "*") {
                    st.push(left * right);
                } else if (i == "/") {
                    int a = left / right;
                    if((left<0 ^ right<0) && (left%right)!=0) a--;
                    st.push(a);
                   } else if (i == "^") {
                    st.push(pow(left, right));  
                }
            }
        }
        return st.top();
    }
};
