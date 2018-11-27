
#include<vector>

using std::vector;

class Solution {
 public:
  int numSquares(const int n) {
    vector<int> squars;
    for(int i = 0;i * i<n;++i){
      squars.push_back(i * i);
    }

  }
  private:
  int minRequires(int n){
    
  }
};

int main(void) {
  Solution sln;

  return 0;
}
