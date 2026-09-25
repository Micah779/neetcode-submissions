class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        // fixed window size of s1
        // move window across s2
        // if window has each character of s1 return true

        int left = 0;
        int window_size = s1.size();
        std::sort(s1.begin(), s1.end());

        for (int i = 0; i < s2.size(); ++i) {
            std::string sub = s2.substr(i, window_size);
            std::sort(sub.begin(), sub.end());

            if (sub == s1) {
                return true;
            }
        }
        return false;
    }
};
