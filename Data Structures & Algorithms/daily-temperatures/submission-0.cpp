using namespace std;
#include <vector>
#include <stack>

class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        // [30,38,30,36,35,40,28]
        int n = temperatures.size();
        std::stack<int> tempIStack;
        std::vector<int> result(n, 0);

        for (int i = 0; i < n; ++i) {
            while (!tempIStack.empty() && temperatures[i] > temperatures[tempIStack.top()]) {
                int previous_day_index = tempIStack.top();
                tempIStack.pop();

                result[previous_day_index] = i - previous_day_index;
            }
            tempIStack.push(i);
        }

        return result;
    }
};
