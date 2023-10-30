// Sliding Window Median

/*
The median is the middle value in an ordered integer list. If the size of the list is even, there
is no middle value. So the median is the mean of the two middle values.

    For examples, if arr = [2,3,4], the median is 3.
    For examples, if arr = [1,2,3,4], the median is (2 + 3) / 2 = 2.5.

You are given an integer array nums and an integer k. There is a sliding window of size k which is
moving from the very left of the array to the very right. You can only see the k numbers in the
window. Each time the sliding window moves right by one position.

Return the median array for each window in the original array. Answers within 10-5 of the actual
value will be accepted.

Example 1:

Input: nums = [1,3,-1,-3,5,3,6,7], k = 3
Output: [1.00000,-1.00000,-1.00000,3.00000,5.00000,6.00000]
Explanation: 
Window position                Median
---------------                -----
[1  3  -1] -3  5  3  6  7        1
 1 [3  -1  -3] 5  3  6  7       -1
 1  3 [-1  -3  5] 3  6  7       -1
 1  3  -1 [-3  5  3] 6  7        3
 1  3  -1  -3 [5  3  6] 7        5
 1  3  -1  -3  5 [3  6  7]       6

Example 2:

Input: nums = [1,2,3,4,2,3,1,4,2], k = 3
Output: [2.00000,3.00000,3.00000,3.00000,2.00000,3.00000,2.00000]
*/

#include <queue>
#include <vector>
#include <unordered_map>

class MedianFinder {
public:
	MedianFinder(int k) {
		this->k = k;
	}

	void addNum(int num) {
		if (small.empty() || num <= small.top()) {
			small.push(num);
			++smallSize;
		} else {
			large.push(num);
			++largeSize;
		}
		reblance();
	}

	void removeNum(int num) {
		++delayed[num];
		if (num <= small.top()) {
			--smallSize;
			if (num == small.top()) {
				prune(small);
			}
		} else {
			--largeSize;
			if (num == large.top()) {
				prune(large);
			}
		}
		reblance();
	}

	double findMedian() {
		return k & 1 ? small.top() : ((double) small.top() + large.top()) / 2.0;
	}

private:
	std::priority_queue<int> small;
	std::priority_queue<int, std::vector<int>, std::greater<int>> large;
	std::unordered_map<int, int> delayed;
	int smallSize = 0;
	int largeSize = 0;
	int k;

	template <typename T>
	void prune(T& pq) {
		while (!pq.empty() && delayed[pq.top()]) {
			if (--delayed[pq.top()] == 0) {
				delayed.erase(pq.top());
			}
			pq.pop();
		}
	}

	void reblance() {
		if (smallSize > largeSize + 1) {
			large.push(small.top());
			small.pop();
			--smallSize;
			++largeSize;
			prune(small);
		} else if (smallSize < largeSize) {
			small.push(large.top());
			large.pop();
			++smallSize;
			--largeSize;
			prune(large);
		}
	}
};

std::vector<double> calcMedians(std::vector<int>& nums, int k)
{
	MedianFinder finder(k);

	for (int i = 0; i < k; ++i) {
		finder.addNum(nums[i]);
	}

	std::vector<double> ans = {finder.findMedian()};

	for (int i = k; i < nums.size(); ++i) {
		finder.addNum(nums[i]);
		finder.removeNum(nums[i - k]);
		ans.push_back(finder.findMedian());
	}

	return ans;
}

/*
class Solution {
public:
double median(const std::map<int, int>& mapValCount, int k)
{
	if((k & 1) !=0)
	{
		int nMinSum = k / 2 + 1;
		
		int nCurSum = 0;
		
		for(auto it = mapValCount.begin(), itEnd = mapValCount.end(); it != itEnd; ++it)
		{
			nCurSum += it->second;

			if(nCurSum >= nMinSum)
				return it->first;
		}
	}
	
	int nSumL = k / 2;
	int nSumR = nSumL + 1;
	int nCurSum = 0;
	
	bool searchL = true;
	
	double fL = 0;
	double fR = 0;

	for(auto it = mapValCount.begin(), itEnd = mapValCount.end(); it != itEnd; ++it)
	{
		nCurSum += it->second;

		if(searchL && nCurSum >= nSumL)
		{
			fL = it->first;
			searchL = false;
		}

		if(nCurSum >= nSumR)
		{
			fR = it->first;
			break;
		}
	}
	
	return (fL + fR) / 2;
}

std::vector<double> medianSlidingWindow(std::vector<int>& nums, int k) {
	
	std::vector<double> vecResult;
	vecResult.reserve(nums.size() - k + 1);
	
	if(k > nums.size())
		return vecResult;
	
	std::map<int, int> mapValCount;
	std::deque<std::map<int, int>::node_type> deq;
	
	for(std::size_t nI = 0; nI < k; ++nI)
	{
		++mapValCount[nums[nI]];
	}
	
	vecResult.push_back(median(mapValCount, k));

	for(std::size_t nI = k; nI < nums.size(); ++nI)
	{
		auto itr = mapValCount.find(nums[nI - k]);
		
		if(itr->second < 2)
		{
			deq.push_back(mapValCount.extract(itr));
		}
		else
			--(itr->second);
		
		auto itrNew = mapValCount.find(nums[nI]);
		
		if(itrNew != mapValCount.end())
			++(itrNew->second);
		else if(deq.size() > 0)
		{
			auto& refNode = deq.back();
			refNode.key() = nums[nI];
			refNode.mapped() = 1;
			
			mapValCount.insert(std::move(refNode));
			deq.pop_back();
		}
		else
			++mapValCount[nums[nI]];

		vecResult.push_back(median(mapValCount, k));
	}

	return vecResult;
}

};
*/
