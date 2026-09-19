#include <vector>
#include <algorithm>

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        // if i sort the numbers then do a sliding window
        // extend right side while num is only 1 greater than prev
        // shorten left window side when not, maintain a max count

        // [2, 20, 4, 10, 3, 4, 5]
        // [2, 3, 4, 4, 5, 10, 20]
        //  l  r : max = 2

        // [2, 3, 4, 4, 5, 10, 20]
        //  l     r : max = 3

        // [2, 3, 4, 4, 5, 10, 20]
        //  l        r : max = 3
        if (nums.empty()) {
            return 0;
        }

        std::sort(nums.begin(), nums.end());

        int longest_streak = 1;
        int current_streak = 1;

        for (int i = 1; i < nums.size(); ++i) {
            // duplicate
            if (nums[i - 1] == nums[i]) {
                continue;
            }
            // extend streak
            else if (nums[i] == nums[i-1] + 1) {
                current_streak += 1;
            }

            // broken sequence
            else {
                longest_streak = std::max(longest_streak, current_streak);
                current_streak = 1;
            }
        }

        return std::max(longest_streak, current_streak);
    }
};
