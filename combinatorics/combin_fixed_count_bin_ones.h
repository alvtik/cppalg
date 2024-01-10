#include <iostream>
#include <string>
#include <vector>
#include <stack>

class OnesCombStackVer {
public:
	std::vector<std::string> sequences(int len, int numOnes) {
		std::vector<std::string> res;

		struct Sequence
		{
			std::string seq;
			int nOnes = 0;
		};

		std::stack<Sequence> stack;
		stack.push(Sequence{ std::string(), 0 });

		Sequence s;
		s.seq.reserve(len);

		while (!stack.empty())
		{
			s = stack.top();
			stack.pop();
			
			if (s.nOnes == numOnes)
			{
				s.seq.insert(s.seq.end(), len - s.seq.size(), '0');
				res.push_back(s.seq);
			}
			else if (len - s.seq.size() >= numOnes - s.nOnes)
			{
				stack.push(Sequence{ s.seq + "1", s.nOnes + 1 });
				stack.push(Sequence{ s.seq + "0", s.nOnes });
			}
		}

		return res;
	}
};

class OnesCombSortVers {
public:
	std::vector<std::string> sequences(int len, int numOnes)
	{
		std::vector<std::string> res;

		if (len < 1 || len < numOnes || numOnes < 1)
			return res;

		std::string str;
		std::string strEnd;

		str.reserve(len);
		strEnd.reserve(len);

		strEnd.insert(strEnd.end(), len - numOnes, '0');
		strEnd.insert(strEnd.end(), numOnes, '1');

		std::size_t nLastOnePos = numOnes - 1;

		do
		{
			if (str.size() == 0)
			{
				str.insert(str.end(), numOnes, '1');
			}
			else
			{
				auto nFindPos = str.find("10");
				str[nFindPos] = '0';
				str[nFindPos + 1] = '1';

				std::sort(str.begin(), str.begin() + nFindPos, std::greater<char>());
			}

			str.insert(str.end(), len - str.size(), '0');
			res.push_back(str);

		} while (str != strEnd);

		return res;
	}
};

int main(int argc, char *argv[])
{
	OnesCombStackVer comb;
	auto res = comb.sequences(7, 4);

	for (const auto& s : res)
	{
		std::cout << s << std::endl;
	}

	return 0;
}
