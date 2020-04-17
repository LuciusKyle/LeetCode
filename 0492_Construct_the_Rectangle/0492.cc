
#include <math.h>
#include <tbb/tbb.h>

#include <iostream>
#include <vector>

using std::vector;

class Solution {
 public:
  vector<int> constructRectangle(const int area) {
    double w = sqrt(area);
    int l = w;
    while (l < area && 0.0000001 < w - int(w)) {
      ++l;
      w = double(area) / l;
    }
    return {l, int(w)};
  }
};

int main(void) {
  Solution sln;
  vector<int> ret = sln.constructRectangle(73);

  std::cout << "TBB version: " << TBB_VERSION_MAJOR << '_' << TBB_VERSION_MINOR << std::endl;
  tbb::parallel_for(int(1), 10000000, 1, [&sln](int i) {
    vector<int> r = sln.constructRectangle(i);
    if (r[0] * r[1] != i)
      std::cout << r[0] << '\t' << r[1] << '\t' << i << std::endl;
  });

  // for (int i = 1; i < 10000000; ++i) {
  //   ret = sln.constructRectangle(i);
  //   if (ret[0] * ret[1] != i) std::cout << ret[0] << '\t' << ret[1] << '\t'
  //   << i << std::endl;
  // }

  std::cout << "all done!" << std::endl;
  return 0;
}
