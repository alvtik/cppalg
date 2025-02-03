#include <algorithm>
#include <vector>
#include <string>

class Solution
{
public:
	std::vector<int> partitionLabels(std::string s)
	{
		int last[26] = { 0 };

		for(size_t nI = 0; nI < s.size(); ++nI)
		{
			last[s[nI] - 'a'] = nI;
		}

		size_t nMaxPos = 0;
		size_t nStartPos = 0;

		std::vector<int> vAnsw;

		for(size_t nI = 0; nI < s.size(); ++nI)
		{
			nMaxPos = std::max<size_t>(nMaxPos, last[s[nI] - 'a']);

			if (nMaxPos == nI)
			{
				vAnsw.push_back(nMaxPos - nStartPos + 1);
				nStartPos = nI + 1;
			}
		}

		return vAnsw;
	}
};

//int main()
//{
//	Solution obj;
//	std::string s = "ababcbacadefegdehijhklij";
//
//	auto result = obj.partitionLabels(s);
//	return 0;
//}
