#include <vector>
#include <string>
#include <unordered_map>
#include <algorithm>

class Solution
{
public:
	std::vector<std::vector<std::string>> groupAnagrams(std::vector<std::string>& strs)
	{
		std::unordered_map<std::string, std::vector<std::string>> d;
		for (auto& s : strs)
		{
			std::string k = s;
			std::sort(k.begin(), k.end());
			d[k].emplace_back(s);
		}

		std::vector<std::vector<std::string>> ans;
		ans.reserve(d.size());

		for (auto& [_, v] : d)
			ans.emplace_back(std::move(v));

		return ans;
	}
};

//int main()
//{
//	Solution obj;
//	//std::vector<int> vInp {2, 1, 2, 4, 5, 4, 5};
//	std::vector<std::string> v {"ddfg", "fgdd", "akd", "vbn", "bnv"};
//
//	auto result = obj.groupAnagrams(v);
//	return 0;
//}
