using namespace std;
#include <vector>
#include <unordered_set>

class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        int rows = board.size();
        int columns = board[0].size();

        // valid rows
        // using a hashset to make sure no duplicates are in the rows
        for (int r = 0; r < rows; ++r) {
            std::unordered_map<char, int> rowFreq;
            for (int j = 0; j < rows; ++j) {
                char cell = board[r][j];
                if (cell == '.') {
                    continue;
                }
                if (rowFreq[cell] > 0) {
                    // 1-9 duplicate in row
                    return false;
                }
                rowFreq[cell] += 1;
            }
        }

        // valid columns
        // uisng a hashset to make sure no duplicates are in the columns
        for (int c = 0; c < columns; ++c) {
            std::unordered_map<char, int> colFreq;
            for (int j = 0; j < columns; ++j) {
                char cell = board[j][c];
                if (cell == '.') {
                    continue;
                }
                if (colFreq[cell] > 0) {
                    // 1-9 duplicate in col
                    return false;
                }
                colFreq[cell] += 1;
            }
        }

        // valid squares
        for (int boxRow = 0; boxRow < 9; boxRow += 3) {
            for (int boxCol = 0; boxCol < 9; boxCol += 3) {
                std::unordered_map<char, int> boxMap;

                for (int r = 0; r < 3; ++r) {
                    for (int c = 0; c < 3; ++c) {
                        char cell = board[boxRow + r][boxCol + c];
                        if (cell == '.') {
                            continue;
                        }
                        if (boxMap[cell] > 0) {
                            return false;
                        }
                        boxMap[cell] += 1;
                    }
                }
            }
        }
        // all rows, cols, squares valid
        return true;
    }
};
