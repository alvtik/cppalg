#include <vector>
#include <string>
#include <algorithm>

class Solution {
public:
	bool isAnagram(std::string s, std::string t) {
		if (s.size() != t.size()) {
			return false;
		}
		std::vector<int> cnt(26);
		for (int i = 0; i < s.size(); ++i) {
			++cnt[s[i] - 'a'];
			--cnt[t[i] - 'a'];
		}
		return std::all_of(cnt.begin(), cnt.end(), [](int x) { return x == 0; });
	}
};

//int main()
//{
//	Solution obj;
//	//std::vector<int> vInp {2, 1, 2, 4, 5, 4, 5};
//	//std::vector<std::string> v {"ddfg", "fgdd", "akd", "vbn", "bnv"};
//
//	auto result = obj.isAnagram("ddfgdd", "fddgdd");
//	return 0;
//}