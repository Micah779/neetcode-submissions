using namespace std;
#include <vector>
#include <iostream>

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        // compliment = target - nums[i]
        // if we see compliment return compliment index, i
        // loop through each num in nums compare to compliment
        for (auto i = 0; i < nums.size(); ++i) {
            int compliment = target - nums[i];
            for (auto j = 0; j < nums.size(); ++j) {
                if (j != i && nums[j] == compliment) {
                    return {i, j};
                }
            }
        }
        return {0, 0};
    }
};
