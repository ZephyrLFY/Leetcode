#include <iostream>
#include <vector>
using namespace std;

class Trie {
public:
    vector<Trie*> next;
    string word = "";

    Trie() : next(26, 0) {}

    void insert(vector<string>& words) {
        for (string word : words) {
            Trie* node = this;
            for (char c : word) {
                if (!node->next[c - 'a']) {
                    node->next[c - 'a'] = new Trie();
                }
                node = node->next[c - 'a'];
            }
            node->word = word;
        }
    }
};

class Solution {
private:
    vector<string> res;
    int rows, cols;
public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        rows = board.size();
        cols = rows ? board[0].size() : 0;
        if (!rows || !cols) return res;
        
        Trie* head = new Trie();
        head->insert(words);
        
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                helper(board, head, i, j);
            }
        }
        return res;
    }

    void helper(vector<vector<char>>& board, Trie* head, int row, int col) {
        char c = board[row][col];
        if (c == '.' || !head->next[c - 'a']) return;
        head = head->next[c - 'a'];
        
        if (head->word != "") {
            res.push_back(head->word);
            head->word = "";
        }

        board[row][col] = '.';
        if (row > 0) helper(board, head, row - 1, col);
        if (row < rows - 1) helper(board, head, row + 1, col);
        if (col > 0) helper(board, head, row, col - 1);
        if (col < cols - 1) helper(board, head, row, col + 1);
        board[row][col] = c;
    }
};