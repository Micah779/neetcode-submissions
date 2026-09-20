using namespace std;
#include <stack>
#include <string>
#include <unordered_map>

class Solution {
public:
    bool isValid(string s) {
        // create a stack
        // loop through characters in s
        // if its an opening bracket add it to the stack
        // if its a closing bracket grab the top of stack and make sure its correct opening
        // pop that from the stack and continue
        // if its not the correct opening bracket then return false
        // if we get through the whole string s return true
        std::stack<char> bracketStack;

        std::string openingBrackets = "({[";
        std::unordered_map<char, char> bracketMap = {{')','('},{'}','{'},{']','['}};

        for (int i = 0; i < s.size(); ++i) {
            // opening bracket
            if (openingBrackets.find(s[i]) != std::string::npos) {
                bracketStack.push(s[i]);
            } else {
                if (bracketStack.empty()) {
                    return false;
                }
                char checkChar = bracketStack.top();
                // valid
                if (checkChar == bracketMap[s[i]]) {
                    bracketStack.pop();
                    continue;
                } else {
                    return false;
                }
            }
        }

        return bracketStack.empty();
    }
};
