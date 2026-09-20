using namespace std;
#include <vector>
#include <algorithm> // for std::min(a, b)

class MinStack {
private:
    std::vector<int> theStack;
    std::vector<int> minStack;
public:
    MinStack() {
    }
    
    void push(int val) {
        // append item to the vector
        theStack.push_back(val);

        if (minStack.empty()) {
            minStack.push_back(val);
        } else {
            minStack.push_back(std::min(val, minStack.back()));
        }
    }
    
    void pop() {
        // remove the end item in vector
        if (!theStack.empty()) {
            theStack.pop_back();
            minStack.pop_back();
        }
    }
    
    int top() {
        // return last element in vector
        return theStack.back();
    }
    
    int getMin() {
        // traverse vector and track min element then return
        return minStack.back();
    }
};
