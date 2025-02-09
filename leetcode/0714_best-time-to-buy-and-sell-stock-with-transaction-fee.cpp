#include <algorithm>
#include <vector>

class Solution
{
public:
    int maxProfit(std::vector<int>& prices, int fee)
    {
        int nProfit = 0, nAcumIfBuy = -prices[0];

        for (int i = 1; i < prices.size(); ++i)
        {
            int g0 = std::max(nProfit, nAcumIfBuy + prices[i] - fee);
            nAcumIfBuy = std::max(nAcumIfBuy, nProfit - prices[i]);
            nProfit = g0;
        }

        return nProfit;
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