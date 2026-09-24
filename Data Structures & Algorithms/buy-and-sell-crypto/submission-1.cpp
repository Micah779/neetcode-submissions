class Solution {
public:
    int maxProfit(vector<int>& prices) {
        // brute force compare each day and store O(n^2) time complexity
        // better is a two pointers solution
        // left is the buy day
        // right is the sell day
        int left = 0;
        int right = 1;
        int maxProfit = 0;
        
        while (right < prices.size()) {
            if (prices[right] > prices[left]) {
                int profit = prices[right] - prices[left];
                maxProfit = std::max(maxProfit, profit);
            } else {
                left = right;
            }
            ++right;
        }

        return maxProfit;
    }
};
