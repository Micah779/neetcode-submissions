class Solution {
public:
    int maxProfit(vector<int>& prices) {
        // brute force compare each day and store O(n^2) time complexity
        int res = 0;
        for (int i = 0; i < prices.size(); ++i) {
            int buy = prices[i];
            for (int j = i + 1; j < prices.size(); ++j) {
                int sell = prices[j];
                res = std::max(res, sell - buy);
            }
        }
        return res;

    }
};
