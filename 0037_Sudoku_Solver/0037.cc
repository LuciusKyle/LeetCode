
#include <unordered_set>
#include <vector>

using std::unordered_set;
using std::vector;

class Solution {
public:
	Solution() : columns(9), rows(9), squares(9) {
		for (auto &my_set : columns) my_set.reserve(9);
		for (auto &my_set : rows) my_set.reserve(9);
		for (auto &my_set : squares) my_set.reserve(9);
	}

	void solveSudoku(vector<vector<char>>& board) {
		for (size_t row = 0; row < board.size(); ++row)
			for (size_t column = 0; column < board[row].size(); ++column)
				if (board[row][column] != '.')
					FillOneCell(row, column, board[row][column]);

		FillSudoku(board, 0, 0);
	}

private:
	bool FillSudoku(vector<vector<char>>& board, const size_t current_row, const size_t current_column) {
		for (size_t row = current_row; row < board.size(); ++row)
			for (size_t column = row == current_row ? current_column : 0; column < board[row].size(); ++column)
				if (board[row][column] == '.') {
					for (char value = '1'; value <= '9'; ++value)
						if (FillOneCell(row, column, value)) {
							board[row][column] = value;
							if (FillSudoku(board, row, column))
								return true;
							else {
								EraseOneCell(row, column, value);
								board[row][column] = '.';
							}
						}
					return false;
				}
		return true;
	}

	bool FillOneCell(const size_t row, const size_t column, const char value) {
    // assert('1' <= value && value <= '9');
		auto rtn = rows[row].insert(value);
		if (!rtn.second)
			return false;
		rtn = columns[column].insert(value);
		if (!rtn.second) {
			rows[row].erase(value);
			return false;
		}
		rtn = squares[(row / 3) * 3 + column / 3].insert(value);
		if (!rtn.second) {
			rows[row].erase(value);
			columns[column].erase(value);
			return false;
		}
		return true;
	}

	void EraseOneCell(const size_t row, const size_t column, const char value) {
		// assert(rows[row].count(value) > 0);
		// assert(columns[column].count(value) > 0);
		// assert(squares[(row / 3) * 3 + column / 3].count(value) > 0);
    rows[row].erase(value);
		columns[column].erase(value);
		squares[(row / 3) * 3 + column / 3].erase(value);
	}

	vector<unordered_set<char>> rows;
	vector<unordered_set<char>> columns;
	vector<unordered_set<char>> squares;
};