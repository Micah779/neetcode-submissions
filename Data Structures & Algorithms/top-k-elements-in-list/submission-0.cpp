using namespace std;
#include <vector>
#include <unordered_map>
#include <set>
#include <algorithm>

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        // frequency of ints then grab top k from that frequency list
        std::unordered_map<int, int> freqMap;

        for (auto num : nums) {
            freqMap[num] += 1;
        }

        // copy pairs into a vector for sorting
        std::vector<pair<int, int>> freqVector(freqMap.begin(), freqMap.end());

        // sort descending based on the feeq
        sort(freqVector.begin(), freqVector.end(), [](const pair<int, int>& a, const pair<int, int>& b) {
            return a.second > b.second;
        });

        // grab the top k keys 'ints'
        vector<int> result;
        for (int i = 0; i < k; ++i) {
            result.push_back(freqVector[i].first);
        }

        return result;
        // i know a better approach would be using a max heap 
        // but i cant think of how to implement that atm
    }
};
