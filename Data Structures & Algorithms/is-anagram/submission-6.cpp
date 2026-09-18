#include <string>
#include <iostream>
#include <unordered_map>

class Solution {
public:
    bool isAnagram(string s, string t) {
        // looking to see if string s and string t have same chars and freq
        // can make two frequency maps of the chars and check if they are equal
        std::unordered_map<char, int> sMap;
        std::unordered_map<char, int> tMap;

        // freq map for sMap
        for (auto ch : s) {
            sMap[ch] += 1; // automatically initilize if dne
        }

        //freq map for tMap
        for (auto ch : t) {
            tMap[ch] += 1; // automatically initilize if dne
        }
        return sMap == tMap;
    }
};
