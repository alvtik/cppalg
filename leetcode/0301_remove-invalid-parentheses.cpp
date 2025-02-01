#include <vector>
#include <string>
#include <stack>
#include <queue>
#include <unordered_set>

class Solution
{
public:
	std::vector<std::string> removeInvalidParentheses(std::string s)
	{
		if(isValid(s))
			return { s };

		std::queue<std::string> q;               // Queue for BFS
		std::unordered_set<std::string> visited; // To track visited rows

		q.push(s);            // The starting line
		std::string current;

		while (!q.empty()) {
			current = q.front();
			q.pop();

			visited.erase(current);

			if(current.size() < 2)
				continue;

			if(current.size() <= _nResStrLen)
				break;

			// Generating all strings with one character removed
			for (size_t i = 0; i < current.size(); ++i) {
				std::string next = current.substr(0, i) + current.substr(i + 1);

				// Checking if the row has already been visited.
				if (visited.find(next) == visited.end())
				{
					q.push(next);
					visited.insert(next);

					if(isValid(next))
					{
						saveStr(next);
					}
				}
			}
		}

		std::vector<std::string> vRes;
		vRes.insert(vRes.end(), _set.begin(), _set.end());

		if(vRes.empty())
			vRes.push_back("");

		return vRes;
	}

private:
	bool isValid(const std::string& s)
	{
		std::stack<char> st;

		for (auto ch :  s)
		{
			if(std::isalpha(ch))
				continue;

			if (ch == '(')
			{
				st.push(ch);
				continue;
			}

			if (st.size() == 0)
				return false;

			char ch_s = st.top();

			if(ch_s != '(' && ch == ')')
				return false;

			st.pop();
		}

		return st.empty();
	}

	void saveStr(const std::string& str)
	{
		if (str.size() > _nResStrLen)
		{
			_nResStrLen = str.size();

			_set.clear();
			_set.insert(str);
		}
		else if(str.size() == _nResStrLen)
		{
			_set.insert(str);
		}
	}

private:
	std::unordered_set<std::string> _set;
	int _nResStrLen = 0;
};

//int main()
//{
//	Solution obj;
//	std::string s ="((((((((((((((((((aaaaa))";
//	//std::string s ="x(";
//	//std::string s = "(j))(";
//	//std::string s = "(((k()((";
//	//std::string s = ")))((()(";
//
//	auto result = obj.removeInvalidParentheses(s);
//	return 0;
//}