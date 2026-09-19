using namespace std;
#include <string>
#include <algorithm>
#include <cctype>

class Solution {
public:
    bool isPalindrome(string s) {
        // if its a palindrome we should be able to use two pointers
        // converging from opposite ends, skipping spaces
        // comparing characters until indexes cross
        // "Was it a car or a cat I saw"
        // need to user all lowercase comparisons to make it work well
        // need to include cctype for tolower and algorithm for transform

        // "Was it a car or a cat I saw"
        int left = 0;
        int right = s.size() - 1;
        std::transform(s.begin(), s.end(), s.begin(), [](unsigned char c) {
            return std::tolower(c);
        });

        while (left <= right) {
            char l = s[left];
            char r = s[right];
            if (std::isalnum(l) && std::isalnum(r)) {
                if (s[left] != s[right]) {
                    return false;
                } else {
                    right -= 1;
                    left += 1;
                    continue;
                }
            }
            if (!std::isalnum(l)) {
                left += 1;
            }
            if (!std::isalnum(r)) {
                right -= 1;
            }
        }
        return true;
    }
};
