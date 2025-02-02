#include <algorithm>
#include <vector>

static std::vector<std::vector<int>> merge(std::vector<std::vector<int>>& intervals)
{
	std::sort(intervals.begin(), intervals.end());

	int st = intervals[0][0], ed = intervals[0][1];
	std::vector<std::vector<int>> ans;

	for (int i = 1; i < intervals.size(); ++i)
	{
		if (ed < intervals[i][0])
		{
			ans.push_back({st, ed});
			st = intervals[i][0];
			ed = intervals[i][1];
		}
		else
		{
			ed = std::max(ed, intervals[i][1]);
		}
	}

	ans.push_back({st, ed});
	return ans;
}