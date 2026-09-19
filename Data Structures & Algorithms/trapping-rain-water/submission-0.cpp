using namespace std;
#include<vector>
#include<algorithm>

class Solution {
public:
    int trap(vector<int>& height) {
        // amount of water trapped at each index should be summed
        // at index i, water = min(height[r], height[l]) - height[i]
        // if we get a negative number we count that as zero
        // can sweep across all indexes running this calculation summing total
        int total = 0;
        int left = 0;
        int right = height.size() - 1;

        int left_max = height[left];
        int right_max = height[right];

        while (left < right) {
            if (left_max < right_max) {
                ++left;
                left_max = std::max(left_max, height[left]);
                total += left_max - height[left];
            }
            else {
                --right;
                right_max = std::max(right_max, height[right]);
                total += right_max - height[right];
            }
        }

        return total;
        
    }
};
