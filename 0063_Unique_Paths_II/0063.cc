
#include<vector>
#include<chrono>
#include<limits.h>
#include<iostream>

using std::vector;

class Solution {
 public:
  int uniquePathsWithObstacles(vector<vector<int>> &obstacleGrid) {
    int m = obstacleGrid.size(), n = obstacleGrid[0].size();
    vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
    dp[0][1] = 1;
    for (int i = 1; i <= m; ++i)
      for (int j = 1; j <= n; ++j)
        if (!obstacleGrid[i - 1][j - 1]) dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
    return dp[m][n];
  }
};

int main(void)
{
	Solution sln;
  vector<vector<int>> grid{vector<int>{0,0,0,},vector<int>{0,1,0,},vector<int>{0,0,0,}};

	auto start = std::chrono::system_clock::now();
  int rtn = sln.uniquePathsWithObstacles(grid);
	std::cout << "time: "
		<< std::chrono::duration_cast<std::chrono::milliseconds>(
			std::chrono::system_clock::now() - start)
		.count()
		<< " milliseconds" << std::endl;

  grid.assign({vector<int>{0,0},vector<int>{1,1},vector<int>{0,0}});
  rtn = sln.uniquePathsWithObstacles(grid);
	return 0;
}



