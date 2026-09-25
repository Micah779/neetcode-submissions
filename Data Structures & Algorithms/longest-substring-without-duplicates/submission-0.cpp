class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        // sliding window
        // window gets bigger if substring continues
        // if we see a repeat bring left to right
        // use a set to check for duplicate

        int longest = 0;
        int left = 0;
        std::set<char> charSet;

        for (int right = 0; right < s.size(); ++right) {
            while (charSet.find(s[right]) != charSet.end()) {
                charSet.erase(s[left]);
                ++left;
            }
            charSet.insert(s[right]);
            longest = std::max(longest, right - left + 1);
        }

        return longest;
    }
};
