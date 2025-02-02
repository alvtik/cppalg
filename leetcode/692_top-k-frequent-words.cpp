#include <algorithm>
#include <vector>
#include <string>
#include <unordered_map>

class Solution {
public:
	std::vector<std::string> topKFrequent(std::vector<std::string>& words, int k)
	{
		std::unordered_map<std::string, int> cnt;
		for (const auto& w : words)
		{
			++cnt[w];
		}

		std::vector<std::string> ans;

		for (const auto& [w, _] : cnt)
		{
			ans.push_back(w);
		}

		std::sort(ans.begin(), ans.end(), [&](const std::string& a, const std::string& b)
					 {
			return cnt[a] > cnt[b] || (cnt[a] == cnt[b] && a < b);
		});

		ans.resize(k);
		return ans;
	}
};

//int main()
//{
//	Solution obj;
//	std::vector<std::string> vInp
//	{
//		"dddddff", "dddsddff", "dddddff", "dds"
//	};
//
//	auto result = obj.topKFrequent(vInp, 2);
//	return 0;
//}
