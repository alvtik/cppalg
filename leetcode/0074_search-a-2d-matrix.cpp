#include <vector>

class Solution {
public:
	bool searchMatrix(std::vector<std::vector<int>>& matrix, int target) {
		int m = matrix.size(), n = matrix[0].size();
		int left = 0, right = m * n - 1;
		while (left < right) {
			int mid = (left + right) >> 1;
			int x = mid / n, y = mid % n;
			if (matrix[x][y] >= target) {
				right = mid;
			} else {
				left = mid + 1;
			}
		}
		return matrix[left / n][left % n] == target;
	}
};

//int main()
//{
//	Solution obj;
//	std::vector<std::vector<int>> vInp {{ -1, 5, 6, 7, 9} , { 10, 15, 16, 17, 19}};
//
//	obj.searchMatrix(vInp, 7);
//
//	return 0;
//}
