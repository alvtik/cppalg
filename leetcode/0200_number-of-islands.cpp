#include <vector>

void dfs(std::vector<std::vector<char>>& grid, int nR, int nC)
{
	grid[nR][nC] = '0';
	if(nR - 1 >= 0 && grid[nR - 1][nC] == '1')
		dfs(grid, nR - 1, nC);

	if(nC - 1 >= 0 && grid[nR][nC - 1] == '1')
		dfs(grid, nR, nC - 1);

	if(nR + 1 < grid.size() && grid[nR + 1][nC] == '1')
		dfs(grid, nR + 1, nC);

	if(nC + 1 < grid[nR].size() && grid[nR][nC + 1] == '1')
		dfs(grid, nR, nC + 1);
}

class Solution
{
public:
	int numIslands(std::vector<std::vector<char>>& grid)
	{
		int nNum = 0;

		for (size_t nI = 0; nI < grid.size(); ++nI)
		{
			for(size_t nJ = 0; nJ < grid[nI].size(); ++nJ)
			{
				if(grid[nI][nJ] == '1')
				{
					dfs(grid, nI, nJ);
					++nNum;
				}
			}
		}

		return nNum;
	}
};

//int main()
//{
//	Solution obj;
//	std::vector<std::vector<char> > vInp
//		= { {'1','1','1','1','0'},
//			{'1','1','0','1','0'},
//			{'1','1','0','0','1'},
//			{'0','0','0','0','1'}
//		};
//
//	auto result = obj.numIslands(vInp);
//	return 0;
//}
