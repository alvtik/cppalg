#include <algorithm>
#include <vector>

class Solution
{
public:
	int maxProfit(std::vector<int>& prices)
	{
		int f = 0, nCurProf = 0, nAcumIfBuy = -prices[0];

		for (int i = 1; i < prices.size(); ++i)
		{
			int g0 = std::max(nCurProf, nAcumIfBuy + prices[i]);
			nAcumIfBuy = std::max(nAcumIfBuy, f - prices[i]);

			f = nCurProf;
			nCurProf = g0;
		}

		return nCurProf;
	}
};

//int main()
//{
//	Solution obj;
//	std::vector<int> vInp = {1, 3, 7, 5, 10, 3};
//
//	auto result = obj.maxProfit(vInp);
//	return 0;
//}
