using namespace std;
#include <vector>
#include <algorithm>

class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        // binary search
        int left = 1;
        int right = *std::max_element(piles.begin(), piles.end());
        int answer = right;

        while (left <= right) {
            int middle = left + (right - left) / 2;
            long long totalHours = 0;
            
            // total hours needed at speed middle
            for (int p : piles) {
                totalHours += (p + middle - 1) / middle;
            }

            if (totalHours <= h) {
                answer = middle; // this speed works as possible answer
                right = middle - 1; // look for smaller speed
            } else {
                left = middle + 1; // too slow increase speed
            }
        }

        return answer;
    }
};
