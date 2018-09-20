
#include<vector>
#include<string>
#include<iostream>

using std::vector;
using std::string;
using std::cout;
using std::endl;

class Solution {
public:
	vector<vector<string>> solveNQueens(const int n) {
		vector<string> board(n, string(n, '.'));
		vector<string> solution_set(n, string(n, '.'));
		vector<vector<string>> rtn;
		FillBoard(rtn, board, static_cast<size_t>(n), solution_set);
		return rtn;
	}
	int totalNQueens(const int n) {
		vector<string> board(n, string(n, '.'));
		vector<string> solution_set(n, string(n, '.'));
		vector<vector<string>> rtn;
		FillBoard(rtn, board, static_cast<size_t>(n), solution_set);
		return static_cast<int>(rtn.size());
	}

private:
	void FillBoard(vector<vector<string>> &rtn, vector<string> &board, const size_t n, vector<string> &solution_set) {
		const size_t edge_size = board.size();
		for (size_t i = 0; i < edge_size; ++i) {
			bool whole_line_is_invalid = true;
			for (size_t ii = 0; ii < edge_size; ++ii) {
				if (board[i][ii] == '.' && (n != edge_size || solution_set[i][ii] != 'Q')) {
					whole_line_is_invalid = false;
					PutChessman(i, ii, board);
					if (n == 1) {
						rtn.push_back(board);
						for (size_t j = 0; j < edge_size; ++j)
							for (size_t jj = 0; jj < edge_size; ++jj)
								if (rtn.back()[j][jj] == 'Q')
									solution_set[j][jj] = 'Q';
								else
									rtn.back()[j][jj] = '.';
					}
					else {
						FillBoard(rtn, board, n - 1, solution_set);
					}
					RemoveChessman(i, ii, board);
				}
			}
			if (whole_line_is_invalid)
				return;
		}
	}

	void PutChessman(const size_t row, const size_t column, vector<string> &board) const {
		const size_t edge_size = board.size();
		for (size_t i = 0; i < edge_size; ++i) {
			if (i < row && i < column) {
				++board[row - i][column - i];
			}
			if (row + i < edge_size && column + i < edge_size) {
				++board[row + i][column + i];
			}
			if (row + i < edge_size && i < column) {
				++board[row + i][column - i];
			}
			if (i < row && column + i < edge_size) {
				++board[row - i][column + i];
			}
			++board[row][i];
			++board[i][column];
		}
		board[row][column] = 'Q';
	}

	void RemoveChessman(const size_t row, const size_t column, vector<string> &board) {
		const size_t edge_size = board.size();
		for (size_t i = 0; i < edge_size; ++i) {
			if (i < row && i < column && '.' < board[row - i][column - i]) {
				--board[row - i][column - i];
			}
			if (row + i < edge_size && column + i < edge_size && '.' < board[row + i][column + i]) {
				--board[row + i][column + i];
			}
			if (row + i < edge_size && i < column && '.' < board[row + i][column - i]) {
				--board[row + i][column - i];
			}
			if (i < row && column + i < edge_size && '.' < board[row - i][column + i]) {
				--board[row - i][column + i];
			}
			if ('.' < board[row][i])
				--board[row][i];
			if ('.' < board[i][column])
				--board[i][column];
			board[row][column] = '.';
		}
	}
};

int main(void) {
	Solution sln;
	const auto rtn = sln.solveNQueens(4);
	for (const auto &board : rtn) {
		for (const auto &row : board) {
			for (const auto ch : row)
				cout << ch << '\t';
			cout << '\n';
		}
		cout << "\n\n";
	}
	return 0;
}
