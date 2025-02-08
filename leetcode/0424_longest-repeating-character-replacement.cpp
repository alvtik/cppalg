#include <algorithm>
#include <string>

class Solution
{
public:
	int characterReplacement(std::string s, int k)
	{
		int cnt[26]{};

		int l = 0, mx = 0;
		const int n = s.length();

		for (int r = 0; r < n; ++r)
		{
			mx = std::max(mx, ++cnt[s[r] - 'A']);

			if (r - l + 1 - mx > k)
			{
				--cnt[s[l++] - 'A'];
			}
		}

		return n - l;
	}
};

//int main()
//{
//	Solution obj;
//	std::string s = "AABABBA";
//	int k = 3;
//
//	auto result = obj.characterReplacement(s, k);
//	return 0;
//}
