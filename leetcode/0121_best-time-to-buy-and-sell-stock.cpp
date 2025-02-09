#include <algorithm>
#include <vector>

class Solution
{
public:
	int maxProfit(std::vector<int>& prices)
	{
		if(prices.size() < 2)
			return 0;
		
		int nMin = prices[0];
		int nRes = 0;

		for(size_t nI = 1; nI < prices.size(); ++nI)
		{
			nRes = std::max<int>(nRes, prices[nI] - nMin);
			nMin = std::min<int>(nMin, prices[nI]);
		}
		
		return nRes;
	}
};