#include <vector>
#include <algorithm>
#include <climits>
#include <iostream>

double findMedianSortedArrays(const std::vector<int>& nums1, const std::vector<int>& nums2) {

    if(nums1.size() == 0 && nums2.size() == 0)
        return 0;

    // Make sure that nums1 is a smaller array
    if (nums1.size() > nums2.size()) {
        return findMedianSortedArrays(nums2, nums1);
    }

    int m = nums1.size();
    int n = nums2.size();

    int left = 0, right = m;
    while (left <= right) {
        int i = (left + right) / 2;      // The division position in nums1
        int j = (m + n + 1) / 2 - i;     // The division position in nums2

        // Edge elements to the left and right of the separation
        int maxLeft1 = (i == 0) ? INT_MIN : nums1[i - 1];
        int minRight1 = (i == m) ? INT_MAX : nums1[i];

        int maxLeft2 = (j == 0) ? INT_MIN : nums2[j - 1];
        int minRight2 = (j == n) ? INT_MAX : nums2[j];

        // Checking if the division is correct
        if (maxLeft1 <= minRight2 && maxLeft2 <= minRight1) {
            // If the total number of elements is even
            if ((m + n) % 2 == 0) {
                return (std::max(maxLeft1, maxLeft2) + std::min(minRight1, minRight2)) / 2.0;
            } else { // If the number is odd
                return std::max(maxLeft1, maxLeft2);
            }
        } else if (maxLeft1 > minRight2) {
            // We have taken too much from nums1, we are moving the right border to the left
            right = i - 1;
        } else {
            // We have taken too little from nums1, we are moving the left border to the right
            left = i + 1;
        }
    }

    // If the code has reached this point, then an error has occurred with the input data
    return 0.0; // We return the default value, although it should never reach here
}

/*
int main() {
    std::vector<int> nums1 = {1, 3};
    std::vector<int> nums2 = {2};

    double median = findMedianSortedArrays(nums1, nums2);
    std::cout << "Median: " << median << std::endl; // Output: 2.0

    std::vector<int> nums3 = {1, 2};
    std::vector<int> nums4 = {3, 4};

    median = findMedianSortedArrays(nums3, nums4);
    std::cout << "Median: " << median << std::endl; // Output: 2.5

    return 0;
}
*/
