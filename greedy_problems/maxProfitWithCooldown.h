// Best Time to Buy and Sell Stock with Cooldown

/*
You are given an array prices where prices[i] is the price of a given stock on the ith day.

Find the maximum profit you can achieve. You may complete as many transactions as you like (i.e.,
buy one and sell one share of the stock multiple times) with the following restrictions:

    After you sell your stock, you cannot buy stock on the next day (i.e., cooldown one day).

Note: You may not engage in multiple transactions simultaneously (i.e., you must sell the stock
before you buy again).

Example 1:

Input: prices = [1,2,3,0,2]
Output: 3
Explanation: transactions = [buy, sell, cooldown, buy, sell]

Example 2:

Input: prices = [1]
Output: 0
*/

#include <vector>
#include <algorithm>

int maxProfitWithCooldown(std::vector<int>& prices)
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

