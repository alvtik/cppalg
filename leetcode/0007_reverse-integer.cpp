#include <limits>

class Solution {
public:
	int reverse(int x)
	{
		int nRes = 0;

		while(x != 0)
		{
			const int nPrevX = x;
			x = x / 10;
			const int nRest = nPrevX - x * 10;

			if (nRes > (std::numeric_limits<int32_t>::max() / 10)
					|| nRes < (std::numeric_limits<int32_t>::min() / 10))
				return 0;

			nRes = nRes * 10 + nRest;
		}

		return nRes;
	}
};

//int main()
//{
//	Solution obj;
//
//	obj.reverse(123);
//	return 0;
//}