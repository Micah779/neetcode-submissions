class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        // naive approach would be to check every matrix[col][row]
        // this would be O(n) time complexity w n being mxn
        // to get O(log(n)) we would need to half this
        // we could count the number of rows
        // starting at the middle rows first val
        // check if its greater then target
        // if it is we know it has to be in in first half rows
        // otherwise second half rows
        // keep running this binary search algorithm on the matrix
        // which would result in logn time complexity

        int num_rows = matrix.size();
        int row_length = matrix[0].size();

        int left = 0;
        int right = num_rows - 1;

        while (left <= right) {
            int middle = left + (right - right) / 2; // avoid overflow
            int row_start = matrix[middle][0];
            int row_end = matrix[middle][row_length - 1];

            if (target >= row_start && target <= row_end) {
                for (int i = 0; i < row_length; ++i) {
                    if (matrix[middle][i] == target) {
                        return true;
                    }
                }
                return false;
            } else if (target > row_end) {
                left = middle + 1;
            } else {
                right = middle - 1;
            }
        }
        return false;
    }
};
