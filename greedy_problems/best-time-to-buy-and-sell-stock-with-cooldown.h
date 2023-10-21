#include <vector>
#include <algorithm>

int maxProfit(std::vector<int>& prices)
{
	int restAfteBuy = -prices[0], acumProfit = 0, f3 = 0;
	
	for (int i = 1; i < prices.size(); ++i)
	{
		int prevRest = restAfteBuy;
		int prevAcumProfit = acumProfit, pf3 = f3;
		
		// Point of purchase. The remaining money after a new purchase,
		// the lower the price - the larger the balance
		restAfteBuy = std::max(prevRest, pf3 - prices[i]);
		
		// Point of sale
		acumProfit = std::max(prevAcumProfit, prevRest + prices[i]); // positive accumulated income
		
		// Since you cannot immediately buy after the sale, the accumulated income for calculations
		// must be taken from the previous
		f3 = std::max(pf3, prevAcumProfit); // maximum between
    }
	
	return acumProfit;
}

