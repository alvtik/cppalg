#include <string>
#include <climits>
#include <limits>

class Solution {
public:
	int myAtoi(std::string s) {

		int nNumb = 0;
		bool numBeg = false;
		bool isNeg = false;
		int nMult = 1;

		for(char ch : s)
		{
			if(!numBeg)
			{
				if(ch == ' ')
					continue;
				else if(ch == '+')
				{
					numBeg = true;
					continue;
				}
				else if(ch == '-')
				{
					numBeg = true;
					isNeg = true;
					continue;
				}
				else if(std::isdigit(ch))
				{
					numBeg = true;
					nNumb = ch - '0';
					continue;
				}
				else
				{
					break;
				}
			}
			else if(!std::isdigit(ch))
				break;

			if(isNeg)
			{
				if(ch ==  '0')
					continue;

				int digit = ch - '0';
				nNumb = -digit;
				nMult = -1;
				isNeg = false;

				continue;
			}

			int digit = ch - '0';

			if(nMult == 1)
			{
				if (nNumb > (std::numeric_limits<int32_t>::max() / 10)
						|| (nNumb == std::numeric_limits<int32_t>::max() / 10 && digit > 7))
					return std::numeric_limits<int32_t>::max();

				nNumb = nNumb * 10 + digit;
			}
			else
			{
				if(nNumb < std::numeric_limits<int32_t>::min() / 10
						|| (nNumb == std::numeric_limits<int32_t>::min() / 10 && digit > 8))
					return std::numeric_limits<int32_t>::min();

				nNumb = nNumb * 10 - digit;
			}
		}

		return nNumb;
	}
};

//int main()
//{
//	Solution obj;

//	obj.myAtoi("   -042");
//	return 0;
//}
