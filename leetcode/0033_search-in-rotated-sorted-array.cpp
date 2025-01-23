#include <vector>

class Solution {
public:
	int search(std::vector<int>& nums, int target)
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
};

//int main()
//{
//	Solution obj;
//	std::vector<int> vInp {3, 4, 5, 6, 7, 8, 1, 2};
//
//	int nResult = obj.search(vInp, 1);
//	return 0;
//}
