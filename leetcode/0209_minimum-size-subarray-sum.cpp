#include <vector>
#include <algorithm>

class Solution {
public:
	int minSubArrayLen(int target, std::vector<int>& nums) {

		const int n = nums.size();
		std::vector<long long> vSort(n + 1);

		for (int i = 0; i < n; ++i)
		{
			vSort[i + 1] = vSort[i] + nums[i];
		}

		int ans = n + 1;
		for (int i = 0; i <= n; ++i)
		{
			int j = lower_bound(vSort.begin(), vSort.end(), vSort[i] + target) - vSort.begin();
			if (j <= n)
			{
				ans = std::min(ans, j - i);
			}
		}

		return ans <= n ? ans : 0;
	}
};

//int main()
//{
//	Solution obj;
//	std::vector vInp { 2, 3, 1, 2, 4, 3 };
//
//	obj.minSubArrayLen(7, vInp);
//
//	return 0;
//}
