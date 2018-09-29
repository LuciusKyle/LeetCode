
#include <vector>
#include <algorithm>

using std::vector;

class Solution {
 public:
  int minimumTotal(vector<vector<int>>& triangle) {
    vector<vector<int>> rtn = triangle;
    for(int i = static_cast<int>(triangle.size()) - 2; i >= 0; --i)
      for(int ii = 0; ii <= i; ++ii){
        rtn[i][ii] = triangle[i][ii] + std::min(rtn[i+1][ii], rtn[i+1][ii+1]);
      }
    return rtn[0][0];
  }
};

int main(int argc, char const *argv[])
{
  Solution sln;
  vector<int> row{2};
  vector<vector<int>> test_sample;
  test_sample.push_back(vector<int>{2});
  test_sample.push_back(vector<int>{3,4});
  test_sample.push_back(vector<int>{5,6,7});
  test_sample.push_back(vector<int>{4,1,8,3});
  int rtn = sln.minimumTotal(test_sample);
  return 0;
}

