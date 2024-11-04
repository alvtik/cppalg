class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        bool ss[128]{};
        int ans = 0;
        for (int left = 0, j = 0; j < s.size(); ++j) {
            while (ss[s[j]]) {
                ss[s[left++]] = false;
            }
            ss[s[j]] = true;
            ans = max(ans, j - left + 1);
        }
        return ans;
    }
};