class Solution {
public:

    bool isPal(string &s, int l, int r){
        while(l < r){
            if(s[l] != s[r]) return false;
            l++;
            r--;
        }
        return true;
    }

    bool palindromePair(vector<string>& arr) {

        unordered_map<string,int> mp;

        int n = arr.size();

        for(int i = 0; i < n; i++){
            mp[arr[i]] = i;
        }

        for(int i = 0; i < n; i++){

            string word = arr[i];
            int m = word.size();

            for(int j = 0; j <= m; j++){

                string prefix = word.substr(0, j);
                string suffix = word.substr(j);
                if(isPal(word, 0, j - 1)){

                    string rev = suffix;
                    reverse(rev.begin(), rev.end());

                    if(mp.count(rev) && mp[rev] != i)
                        return true;
                }

                if(j != m && isPal(word, j, m - 1)){

                    string rev = prefix;
                    reverse(rev.begin(), rev.end());

                    if(mp.count(rev) && mp[rev] != i)
                        return true;
                }
            }
        }

        return false;
    }
};
// TC: O(n * m^2) where n is the number of words and m is the average length of the words (due to substring and palindrome checks)
// SC: O(n * m) for the hash map storing the words and their indices    