using namespace std;
#include <vector>

class Solution {
public:
    int search(vector<int>& nums, int target) {
        // for O(nlogn) searching we need to halve the search space
        // this is the classic binary search algorithm
        int left = 0;
        int right = nums.size() - 1;

        while (left <= right) {
            int middle = (left + right) / 2;
            if (nums[middle] == target) {
                return middle;
            } else if (nums[middle] < target) {
                left = middle + 1;
            } else {
                right = middle - 1;
            }
        }
        return -1;
    }
};
