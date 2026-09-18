using namespace std;
#include <vector>
#include <string>
#include <unordered_map>
#include <algorithm>

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        // use sorting to simplify comparisons
        std::unordered_map<string, vector<string>> groups;

        for (auto str : strs) {
            string sorted_str = str;
            sort(sorted_str.begin(), sorted_str.end());

            groups[sorted_str].push_back(str);
        }

        // create final list from key : value, values
        std::vector<vector<string>> output;
        for (auto& pair : groups) {
            output.push_back(pair.second);
        }

        return output;
    }
};
