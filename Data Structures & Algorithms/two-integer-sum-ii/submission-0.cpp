using namespace std;
#include<vector>

class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        // sliding window (in this case shrinking)
        // shrink left in if current sum is to large
        // shring right in if current sum is too small
        // have pointers on both ends
        int left = 0;
        int right = numbers.size() - 1;

        while (left < right) {
            int current_sum = numbers[left] + numbers[right];
            if (current_sum == target) {
                return {left + 1, right + 1};
            }
            else if (current_sum < target) {
                left += 1;
            }
            else {
                right -= 1;
            }
        }

        // return index1 + 1, index2 + 1 since answer is 1-indexed

        // ill ad a return -1 even though it should never be reached
        return {-1, -1};
    }
};
