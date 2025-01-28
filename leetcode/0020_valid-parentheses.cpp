#include <string>
#include <stack>

class Solution
{
public:
	bool isValid(std::string s)
	{
		std::stack<char> st;

		for (auto ch :  s)
		{
			if (ch == '(' || ch == '{' || ch == '[')
			{
				st.push(ch);
				continue;
			}

			if (st.size() == 0)
				return false;

			char ch_s = st.top();

			if(ch_s != '(' && ch == ')')
				return false;
			else if(ch_s != '{' && ch == '}')
				return false;
			else if(ch_s != '[' && ch == ']')
				return false;

			st.pop();
		}

		return st.empty();
	}
};

//int main()
//{
//	Solution obj;
//	std::string str = "[({{}})]";
//
//	auto result = obj.isValid(str);
//	return 0;
//}
