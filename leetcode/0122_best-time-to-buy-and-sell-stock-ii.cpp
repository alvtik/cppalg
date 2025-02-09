#include <algorithm>
#include <vector>

class Solution
{
public:
	int maxProfit(std::vector<int>& prices)
	{
		int ans = 0;

		for (int i = 1; i < prices.size(); ++i)
			ans += std::max(0, prices[i] - prices[i - 1]);
		
		return ans;
	}
};