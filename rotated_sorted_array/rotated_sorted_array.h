#pragma once
#include <vector>

class RotatedSortedArray
{
public:
	static int search(std::vector<int>& nums, int target)
	{
		int n = nums.size();
		int left = 0, right = n - 1;

		while (left < right)
		{
			int mid = (left + right) >> 1;
			if (nums[0] <= nums[mid])
			{
				if (nums[0] <= target && target <= nums[mid])
					right = mid;
				else
					left = mid + 1;
			}
			else
			{
				if (nums[mid] < target && target <= nums[n - 1])
					left = mid + 1;
				else
					right = mid;
			}
		}

		return nums[left] == target ? left : -1;
	}
	
//----------------------------------------------

	static int findMin(std::vector<int>& nums)
	{
		int n = nums.size();
		if (nums[0] <= nums[n - 1])
			return nums[0];

		int left = 0, right = n - 1;

		while (left < right)
		{
			int mid = (left + right) >> 1;

			if (nums[0] <= nums[mid])
				left = mid + 1;
			else
				right = mid;
		}
		return nums[left];
	}
};
