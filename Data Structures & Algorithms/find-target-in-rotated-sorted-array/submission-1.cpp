class Solution {
public:
    int search(vector<int>& nums, int target) {
        // basic binary search in sorted vector of nums
        int left = 0;
        int right = nums.size() - 1;

        while (left <= right) {
            int middle = left + (right - left) / 2;
            if (nums[middle] == target) {
                return middle;
            } else if (nums[left] <= nums[middle]) { // left half sorted
                if (target >= nums[left] && target <= nums[middle]) {
                    right = middle - 1;
                } else {
                    left = middle + 1;
                }
            } else { // right half sorted
                if (target >= nums[middle] && target <= nums[right]) {
                    left = middle + 1;
                } else {
                    right = middle - 1;
                }
            }
        }
        return -1;
    }
};
