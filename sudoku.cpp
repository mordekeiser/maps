class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        unordered_set<char> rowSet[9], colSet[9], boxSet[9];

        for (int row = 0; row < 9; row++) {
            for (int col = 0; col < 9; col++) {
                char num = board[row][col];
                if (num == '.') continue; // Ignore empty cells
                
                int boxIndex = (row / 3) * 3 + (col / 3); // Calculate 3x3 box index

                // Check for duplicates
                if (rowSet[row].count(num) || colSet[col].count(num) || boxSet[boxIndex].count(num)) {
                    return false;
                }
                rowSet[row].insert(num);
                colSet[col].insert(num);
                boxSet[boxIndex].insert(num);
            }
        }

        return true;
    }
};
