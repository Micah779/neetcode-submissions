#include <iostream>
#include <string>
#include <vector>
#include <sstream>

class Solution {
public:
    // should be easy enough to use a non ASCII 256 char like €
    std::string special_char = "€";

    string encode(vector<string>& strs) {
        // add the special char between each word to "encode"
        std::string output;
        for (string str : strs) {
            output += str;
            output += special_char;
        }

        return output;

    }

    vector<string> decode(string s) {
        // to decode split string at delimiter which is special char
        // can use string stream
        std::vector<std::string> decoded_string;
        std::size_t pos = 0;
        std::size_t prev = 0;

        while((pos = s.find(special_char, prev)) != std::string::npos) {
            decoded_string.push_back(s.substr(prev, pos - prev));
            prev = pos + special_char.length();
        }

        return decoded_string;
    }
};
