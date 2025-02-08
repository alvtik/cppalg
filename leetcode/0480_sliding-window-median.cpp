#include <deque>
#include <vector>
#include <set>

class Solution
{
public:
	std::vector<double> medianSlidingWindow(std::vector<int>& nums, int k)
	{
		if(k == 1)
			return std::vector<double> { nums.begin(), nums.end() };

		std::vector<double> vAnsw;
		vAnsw.reserve(nums.size() - k + 1);

		std::deque<int> deque;

		for(int nI = 0; nI < k; ++nI)
		{
			deque.push_back(nums[nI]);
			_setHigh.insert(nums[nI]);
		}

		while(_setLow.size() < _setHigh.size())
		{
			auto itr = _setHigh.begin();
			_setLow.insert(_setHigh.extract(itr));
		}

		const size_t nLowSize = _setLow.size();
		const bool oddFlag = (k & 1) == 1;

		for(int nI = k; nI < nums.size(); ++nI)
		{
			outMedian(vAnsw, oddFlag);

			const auto del = deque.front();
			auto itrFind = _setLow.find(del);

			if(itrFind != _setLow.end())
			{
				_setLow.erase(itrFind);
			}
			else
			{
				itrFind = _setHigh.find(del);
				_setHigh.erase(itrFind);
			}

			deque.pop_front();
			deque.push_back(nums[nI]);

			if(_setHigh.size() == 0)
			{
				_setLow.insert(nums[nI]);
			}
			else if(_setHigh.size() == 0)
			{
				_setLow.insert(nums[nI]);
			}
			else if(nums[nI] <= *_setHigh.begin())
			{
				_setLow.insert(nums[nI]);
			}
			else
			{
				_setHigh.insert(nums[nI]);
			}

			while(_setLow.size() < nLowSize)
			{
				auto itr = _setHigh.begin();
				_setLow.insert(_setHigh.extract(itr));
			}

			while(_setLow.size() > nLowSize)
			{
				auto itr = _setLow.end();
				--itr;

				_setHigh.insert(_setLow.extract(itr));
			}
		}

		outMedian(vAnsw, oddFlag);
		return vAnsw;
	}

private:
	void outMedian(std::vector<double>& vMed, bool oddFlag)
	{
		if(oddFlag)
		{
			auto itrMed = --_setLow.end();
			vMed.push_back(*itrMed);
		}
		else
		{
			auto itrLow = --_setLow.end();
			auto itrHigh = _setHigh.begin();

			vMed.push_back(
				(static_cast<double>(*itrLow) + *itrHigh) / 2.);
		}
	}

private:
	std::multiset<int> _setLow;
	std::multiset<int> _setHigh;
};

//int main()
//{
//	Solution obj;
//	std::vector<int> vNums = { 1, 2, 3, 4, 2, 3, 1, 4, 2 };
//	int k = 3;
//
//	auto result = obj.medianSlidingWindow(vNums, k);
//	return 0;
//}
