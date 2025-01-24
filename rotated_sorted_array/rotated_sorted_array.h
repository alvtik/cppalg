#pragma once
#include <vector>

class RotatedSortedArray
{
public:
	static bool search(std::vector<int>& nums, int target)
	{
		int l = 0, r = nums.size() - 1;

		while (l < r)
		{
			int mid = (l + r) >> 1;

			if (nums[mid] > nums[r])
			{
				if (nums[l] <= target && target <= nums[mid])
				{
					r = mid;
				}
				else
				{
					l = mid + 1;
				}
			}
			else if (nums[mid] < nums[r])
			{
				if (nums[mid] < target && target <= nums[r])
				{
					l = mid + 1;
				}
				else
				{
					r = mid;
				}
			}
			else
			{
				--r;
			}
		}

		return nums[l] == target;
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
