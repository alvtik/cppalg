#include <vector>

class Solution {
public:
	int search(std::vector<int>& nums, int target)
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

		return nums[left] == target ? left : -1;
	}
};

//int main()
//{
//	Solution obj;
//	std::vector<int> vInp {3, 4, 5, 6, 7, 8, 1, 2};
//
//	int nResult = obj.search(vInp, 1);
//	return 0;
//}
