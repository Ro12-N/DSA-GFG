class Solution {
public:
    bool isProduct(vector<int>& arr, long long target) {
        unordered_set<long long> st;
        for (auto i : arr) {
            if (i == 0) {
                if ( target==0)
                    return true;
            }
            if (target % i == 0) {
                long long need = target / i;

                if (st.count(need))
                    return true;
            }
            st.insert(i);
        }
        return false;
    }
};
// TC : o(N)
// SC : o(N)