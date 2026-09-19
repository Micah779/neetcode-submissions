using namespace std;
#include <vector>
#include <algorithm>

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        // window size is 3
        // simplying comparing all triplets would be O(n^3) = bad
        // start with sorting nums
        std::vector<vector<int>> result;
        std::sort(nums.begin(), nums.end());

        // [-4, -1, -1, 0, 1, 2]
        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] > 0) {
                break;
            }
            // skip duplicates
            if (i > 0 && nums[i] == nums[i-1]) {
                continue;
            }

            // two pointer for remaining window
            int left = i + 1;
            int right = nums.size() - 1;

            while (left < right) {
                int sum = nums[i] + nums[left] + nums[right];
                if (sum == 0) {
                    result.push_back({nums[i], nums[left], nums[right]});

                    // move pointers past duplicates
                    while (left < right && nums[left] == nums[left + 1]) {
                        ++left;
                    }
                    while (left < right && nums[right] == nums[right - 1]) {
                        --right;
                    }

                    ++left;
                    --right;
                }
                else if (sum < 0){
                    ++left;
                }
                else {
                    --right;
                }
            }
        }
        return result;
    }
};
