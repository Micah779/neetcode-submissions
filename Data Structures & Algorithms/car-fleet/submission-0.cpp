using namespace std;
#include <vector>
#include <stack>
#include <algorithm> // for sorting

class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        // l@0 [1,_,_,4,_,_,_,_,_,_] car 1 has speed 3, car 2 has speed 2, target @10
        // l@1 [_,_,_,1,_,4,_,_,_,_]
        // l@2 [_,_,_,_,_,_,1,4,_,_]
        // l@3 [_,_,_,_,_,_,1,4,_,_]
        // l@4 [_,_,_,_,_,_,_,_,_,_] // reached target with 1 fleet
        std::vector<double> arrivalStack;
        std::vector<pair<int, int>> pair;
        
        for (int i = 0; i < position.size(); ++i) {
            pair.push_back({position[i], speed[i]});
        }

        std::sort(pair.rbegin(), pair.rend());
        for (auto& p : pair) {
            arrivalStack.push_back((double)(target - p.first) / p.second); // pushing time to arrival for car
            if (arrivalStack.size() >= 2 && arrivalStack.back() <= arrivalStack[arrivalStack.size() - 2]) {
                arrivalStack.pop_back(); // remove car aka arrival time from stack if it merges into fleet
            }
        }
        return arrivalStack.size(); // fleet size will be number of cars/arrival times left in the stack
    }
};
