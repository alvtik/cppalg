#include <algorithm>
#include <vector>
#include <unordered_map>

class Solution
{
public:
	std::vector<int> topKFrequent(std::vector<int>& nums, int k)
	{
		std::unordered_map<int, int> mapCnt;

		for (auto n : nums)
			++mapCnt[n];

		std::vector<int> vRes;
		vRes.reserve(mapCnt.size());

		for (auto [n, _] : mapCnt)
			vRes.push_back(n);

		std::sort(vRes.begin(), vRes.end(), [&] (int l, int r)
		{
			return mapCnt[l] > mapCnt[r];
		});

		vRes.resize(k);
		return vRes;
	}
};

//int main()
//{
//	Solution obj;
//	std::vector<int> vInp
//	{
//		1, 2, 2, 3
//	};
//
//	auto result = obj.topKFrequent(vInp, 2);
//	return 0;
//}
