class Solution {
public:
    vector<int> commonElements(vector<int> &a, vector<int> &b, vector<int> &c) {
        int i = 0, j = 0, k = 0;
        vector<int> res;

        while(i < a.size() && j < b.size() && k < c.size()) {

            if(a[i] == b[j] && b[j] == c[k]) {
                if(res.empty() || res.back() != a[i]) 
                    res.push_back(a[i]);
                i++; j++; k++;
            }
            else {
                if(a[i] <= b[j] && a[i] <= c[k]) i++;
                else if(b[j] <= a[i] && b[j] <= c[k]) j++;
                else k++;
            }
        }
        return res;
    }
};
// Time Complexity: O(n1 + n2 + n3) where n1, n2, and n3 are the sizes of the three input arrays.
// Space Complexity: O(min(n1, n2, n3)) in the worst case when all elements in the smallest array are common to the other two arrays and are stored in the result vector.