#include <algorithm>
#include <vector>

class Solution
{
public:
	int maxArea(std::vector<int>& height)
	{
		size_t nL = 0;
		size_t nR = height.size() - 1;
		int nAns = 0;

		while (nL < nR)
		{
			const int nC = std::min<int>(height[nL], height[nR]) * (nR - nL);

			if (nAns < nC)
				nAns = nC;

			if (height[nL] <= height[nR])
				++nL;
			else
				--nR;
		}

		return nAns;
	}
};

//int main()
//{
//	Solution obj;
//	std::vector<int> vInp
//	{
//		1,8,6,2,5,4,8,3,7
//	};
//
//	auto result = obj.maxArea(vInp);
//	return 0;
//}
