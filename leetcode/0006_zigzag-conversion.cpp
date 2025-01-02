#include <string>

class Solution {
public:
	std::string convert(std::string s, int numRows)
	{
		std::string strAns;
		strAns.reserve(s.size());
		const int nStep = numRows + numRows - 2;

		if (numRows <= 1 || nStep == 0 || s.size() < numRows)
		{
			return s;
		}

		for(int nR = 0; nR < numRows; ++nR)
		{
			int nSecStep = nStep - nR * 2;
			int nCharPos = nR;

			strAns += s[nCharPos];

			while(true)
			{
				if(nSecStep != nStep && nSecStep != 0)
				{
					if(nCharPos + nSecStep >= s.size())
						break;

					strAns += s[nCharPos + nSecStep];
				}

				nCharPos += nStep;

				if(nCharPos >= s.size())
					break;

				strAns += s[nCharPos];
			}
		}

		return strAns;
	}
};

int main()
{
	Solution obj;
	std::string str = "ABCD";

	std::string strAns = obj.convert(str, 3);

	return 0;
}
