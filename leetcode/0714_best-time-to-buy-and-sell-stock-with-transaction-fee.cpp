#include <algorithm>
#include <vector>

class Solution
{
public:
	int maxProfit(std::vector<int>& prices, int fee)
	{
		int nCurProfit = 0, nAccum = -prices[0];

		for (int i = 1; i < prices.size(); ++i)
		{
			int g0 = std::max(nCurProfit, nAccum + prices[i] - fee);
			nAccum = std::max(nAccum, nCurProfit - prices[i]);
			nCurProfit = g0;
		}

		return nCurProfit;
	}
};

//int main()
//{
//	Solution obj;
//	std::vector<int> vInp = {1, 3, 7, 5, 10, 3};
//	int k = 3;
//
//	auto result = obj.maxProfit(vInp, k);
//	return 0;
//}