#include <vector>

class Solution
{
public:
	int singleNumber(std::vector<int>& nums)
	{
		int ans = 0;
		for (int v : nums) {
			ans ^= v;
		}
		return ans;
	}
};

//int main()
//{
//	Solution obj;
//	std::vector<int> vInp {2, 1, 2, 4, 5, 4, 5};
//
//	int nResult = obj.singleNumber(vInp);
//	return 0;
//}