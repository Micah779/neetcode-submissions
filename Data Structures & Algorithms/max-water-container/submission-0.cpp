using namespace std;
#include <vector>
#include <algorithm> // for std::min

class Solution {
public:
    int maxArea(vector<int>& heights) {
        // two pointers from left and right coming in
        // max_water = (right_i - left_i) * min(heights[left], heights[right])
        // in the example to start it would be (7 - 0) * 1 = 7
        // then we could check the heights[l + 1] and heights[r - 1]
        // the larger one is the direction we shrink our window
        // recalculate max_water as max(curr_max, max_water)
        // repeat while left < right
        // return the max_water we could find

        // [1,7,2,5,4,7,3,6]
        // c_m_w = 7
        // 
        int max_water = 0;
        int left = 0;
        int right = heights.size() - 1;

        while (left < right) {
            int current_max_water = (right - left) * std::min(heights[left], heights[right]);
            max_water = std::max(max_water, current_max_water);

            if (heights[left] < heights[right]) {
                ++left;
            } else {
                --right;
            }
        }

        return max_water;

    }
};
