#include <iostream>
#include <string>
#include <vector>
#include <stack>

class OnesCombinations {
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

int main(int argc, char *argv[])
{
	OnesCombinations comb;
	auto res = comb.sequences(7, 4);

	for (const auto& s : res)
	{
		std::cout << s << std::endl;
	}

	return 0;
}
