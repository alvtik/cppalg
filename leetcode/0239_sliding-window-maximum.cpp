#include <deque>
#include <vector>
#include <set>

class Solution
{
public:
	std::vector<int> maxSlidingWindow(std::vector<int>& nums, int k)
	{
		if(k == 1)
			return std::vector<int> { nums.begin(), nums.end() };

		std::vector<int> vAnsw;
		vAnsw.reserve(nums.size() - k + 1);

		std::deque<int> deque;

		for(int nI = 0; nI < k; ++nI)
		{
			deque.push_back(nums[nI]);
			_setSort.insert(nums[nI]);
		}

		for(int nI = k; nI < nums.size(); ++nI)
		{
			outMax(vAnsw);

			auto itrDel = _setSort.find(deque.front());
			_setSort.erase(itrDel);

			deque.pop_front();
			deque.push_back(nums[nI]);
			_setSort.insert(nums[nI]);
		}

		outMax(vAnsw);
		return vAnsw;
	}

private:
	void outMax(std::vector<int>& vMed)
	{
		vMed.push_back(*_setSort.begin());
	}

private:
	std::multiset<int, std::greater<>> _setSort;
};

//int main()
//{
//	Solution obj;
//	std::vector<int> vNums = { 1, 2, 3, 4, 2, 3, 1, 4, 2 };
//	int k = 3;
//
//	auto result = obj.maxSlidingWindow(vNums, k);
//	return 0;
//}
