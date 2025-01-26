#include <vector>
#include <algorithm>


class Solution
{
public:
	std::vector<std::vector<int>> fourSum(std::vector<int>& nums, int target)
	{
		int n = nums.size();
		std::vector<std::vector<int>> ans;
		if (n < 4)
		{
			return ans;
		}
		std::sort(nums.begin(), nums.end());

		for (int i = 0; i < n - 3; ++i)
		{
			if (i && nums[i] == nums[i - 1])
			{
				continue;
			}

			for (int j = i + 1; j < n - 2; ++j)
			{
				if (j > i + 1 && nums[j] == nums[j - 1])
				{
					continue;
				}

				const long long d = nums[i] + nums[j];

				for(int k = j + 1; k < n - 1; ++k)
				{
					if (k > j + 1 && nums[k] == nums[k - 1])
					{
						continue;
					}

					const long long dd = target - (d + nums[k]);
					for(int l = k + 1; l < n; ++l)
					{
						if (l > k + 1 && nums[l] == nums[l - 1])
						{
							continue;
						}

						if(dd == nums[l])
							ans.push_back({nums[i], nums[j], nums[k],nums[l]});
					}
				}
			}
		}
		return ans;
	}
};

//int main()
//{
//	Solution obj;
//	std::vector<int> vInp {2, 1, 1, 2, 4, 5, 4, 5};
//
//	auto result = obj.fourSum(vInp, 10);
//	return 0;
//}
