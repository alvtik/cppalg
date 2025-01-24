#include <vector>

class Solution {
public:
	int findMin(std::vector<int>& nums)
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

//int main()
//{
//	Solution obj;
//	std::vector<int> vInp {9, 1, 2, 3, 4, 5};
//
//	int nResult = obj.findMin(vInp);
//	return 0;
//}
