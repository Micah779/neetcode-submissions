#include <algorithm>

class Solution {
public:
    int findMin(vector<int> &nums) {
        int left = 0;
        int right = nums.size() - 1;
        int min_val = nums[left];

        while (left <= right) {
            int middle = left + (right - left) / 2;

            if (nums[middle] < nums[left]) { // could be min, check left
                min_val = std::min(nums[middle], min_val);
                right = middle - 1;
            } else {
                min_val = std::min(min_val, nums[left]);
                left = middle + 1; // still monotomic increasing
            }
        }
        return min_val; // case where its sorted monotomic this is nums[0]
    }
};
