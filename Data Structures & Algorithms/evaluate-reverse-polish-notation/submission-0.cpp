using namespace std;
#include <vector>
#include <stack>
#include <string>

class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        // 2
        // 1
        // + pop() 1 + pop() 2 push() 3
        //
        // 3
        // 3
        // * pop() 3 * pop() 3 push() 9
        //
        // 4
        // 9
        // - pop() 4 - pop() 9 push() -5
        // need to switch order of operation on 2 pop() items
        std::stack<int> tokenStack;
        string operations = "+-*/";

        for (int i = 0; i < tokens.size(); ++i) {
            if (operations.find(tokens[i]) == std::string::npos) {
                // push int to stack
                tokenStack.push(std::stoi(tokens[i]));
            } else {
                // operation
                int val1 = tokenStack.top();
                tokenStack.pop();
                int val2 = tokenStack.top();
                tokenStack.pop();

                if (tokens[i] == "+" && tokens[i].size() == 1) {
                    int operation = val2 + val1;
                    tokenStack.push(operation);
                } else if (tokens[i] == "-" && tokens[i].size() == 1) {
                    int operation = val2 - val1;
                    tokenStack.push(operation);
                } else if (tokens[i] == "*" && tokens[i].size() == 1) {
                    int operation = val2 * val1;
                    tokenStack.push(operation);
                } else {
                    int operation = val2 / val1;
                    tokenStack.push(operation);
                }
            }
        }
        // should be final operation value that got pushed
        return tokenStack.top();

    }
};
