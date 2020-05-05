#include "../cppLib.h"

class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        if (word.empty()) return false;
        char start = word[0];
        int rows = board.size();
        if (!rows) return false;
        int cols = board[0].size();

        int row = -1, col = -1;
        bool res = false;
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (board[i][j] == start) {
                    row = i;
                    col = j;
                    board[i][j] = '0';
                    res = helper(board, word, 1, row, col, rows, cols);
                    if (res) return true;
                    board[i][j] = start;
                }
            }
        }
        return res;
    }

    bool helper(vector<vector<char>>& board, string& word, int start, int row, int col, int rows, int cols) {
        if (start >= word.size()) return true;
        char goal = word[start];
        bool status = false;
        if (row > 0 && board[row - 1][col] == goal) {
            board[row - 1][col] = '0';
            status = helper(board, word, start + 1, row - 1, col, rows, cols);
            if (status) return true;
            board[row - 1][col] = goal;
        }
        if (row < rows - 1 && board[row + 1][col] == goal) {
            board[row + 1][col] = '0';
            status = helper(board, word, start + 1, row + 1, col, rows, cols);
            if (status) return true;
            board[row + 1][col] = goal;
        }
        if (col > 0 && board[row][col - 1] == goal) {
            board[row][col - 1] = '0';
            status = helper(board, word, start + 1, row, col - 1, rows, cols);
            if (status) return true;
            board[row][col - 1] = goal;
        }
        if (col <  cols - 1 && board[row][col + 1] == goal) {
            board[row][col + 1] = '0';
            status = helper(board, word, start + 1, row, col + 1, rows, cols);
            if (status) return true;
            board[row][col + 1] = goal;
        }
        return false;
    }
};