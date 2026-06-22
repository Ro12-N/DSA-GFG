class Solution {
	public:
	int getLastDigit(string& a, string& b) {
		if (b == "0")
			return 1;
		int base = a.back() - '0';
		int val=0;
		for(auto i:b){
		    val=(val*10+(i-'0'))%4;
		}
		if(val==0) val=4;
		int ans = 1;
		for (int i = 0; i<val; i++) {
			ans = (ans*base)%10;
		}
		return ans;
	}
};
// TC : O(|a| + |b|) where |a| and |b| are the lengths of the strings a and b respectively.
// SC : O(1) as we are using constant space.