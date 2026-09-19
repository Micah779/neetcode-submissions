using namespace std;
#include <iostream>
#include <vector>

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        // since multiplication doesn't matter the order
        // im thinking if you take the total product
        // then for each num index just place the total product / num
        // you would have the output array
        // ^ that method failed due to 0s
        // second idea would be doing a loop to calculate index product
        // skipping index
        // one loop per index which is O(n^2) tc
        // this worked but is too slow for submission
        // optimized approach is using prefix and postfix split by index
        // so total product is all_before_i x all_after_i
        // store prefix_products directly in output array
        // multiply postfix_products on the fly

        int n = nums.size();
        std::vector<int> output(n, 1);
        
        // pass 1 calculate prefix products
        int prefix = 1;
        for (int i = 0; i < n; ++i) {
            output[i] = prefix;
            prefix *= nums[i];
        }

        // pass 2 calculate postfix
        // walk backward and multiply prefix product by running postfix
        int postfix = 1;
        for (int i = n - 1; i >= 0; --i) {
            output[i] *= postfix;
            postfix *= nums[i];
        }

        return output;
    }
};
