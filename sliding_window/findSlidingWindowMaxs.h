//Sliding Window Maximum

/*

You are given an array of integers nums, there is a sliding window of size k which is moving from
the very left of the array to the very right. You can only see the k numbers in the window. Each
time the sliding window moves right by one position.

Return the max sliding window.

Example 1:

Input: nums = [1,3,-1,-3,5,3,6,7], k = 3
Output: [3,3,5,5,6,7]
Explanation: 
Window position                Max
---------------               -----
[1  3  -1] -3  5  3  6  7       3
 1 [3  -1  -3] 5  3  6  7       3
 1  3 [-1  -3  5] 3  6  7       5
 1  3  -1 [-3  5  3] 6  7       5
 1  3  -1  -3 [5  3  6] 7       6
 1  3  -1  -3  5 [3  6  7]      7

Example 2:

Input: nums = [1], k = 1
Output: [1]

*/

#include <deque>
#include <vector>

//The idea is that the front element in the queue contains the maximum element in the window
std::vector<int> findSlidingWindowMaxs(std::vector<int>& nums, int k)
{
	std::deque<int> q;
	std::vector<int> ans;
	ans.reserve(nums.size() - k + 1);

	for (int i = 0; i < nums.size(); ++i)
	{
		if (!q.empty() && i - k + 1 > q.front())
		{
			q.pop_front();
		}
		
		while (!q.empty() && nums[q.back()] <= nums[i])
		{
			q.pop_back();
		}
		
		q.push_back(i);
		
		if (i >= k - 1)
		{
			ans.emplace_back(nums[q.front()]);
		}
	}

	return ans;
}

