#include <iostream>
#include <set>
#include <vector>

class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        // using a set you can just iterate nums and compare against the set
        std::set<int> mySet;

        if (nums.size() == 0 || nums.size() == 1)
            return false;

        for (auto i = 0; i < nums.size(); ++i) {
            if (mySet.find(nums[i]) != mySet.end()) {
                return true;
            } else {
                mySet.insert(nums[i]);
            }
        }
        return false;
    }
};