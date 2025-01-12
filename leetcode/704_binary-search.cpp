#include <vector>

class Solution {
public:
	int search(std::vector<int>& nums, int target) {
		int l = 0, r = nums.size() - 1;
		while (l < r) {
			int mid = (l + r) >> 1;
			if (nums[mid] >= target) {
				r = mid;
			} else {
				l = mid + 1;
			}
		}
		return nums[l] == target ? l : -1;
	}
};

//int main()
//{
//	Solution obj;
//	std::vector vInp { -1, 5, 6, 7, 9};
//
//	obj.search(vInp, 7);
//
//	return 0;
//}