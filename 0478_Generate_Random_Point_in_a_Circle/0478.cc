
#include <math.h>

#include <random>
#include <vector>
#include <iostream>

using std::vector;

class Solution {
 public:
  Solution(double radius, double x_center, double y_center)
      : _x_center(x_center),
        _y_center(y_center),
        _re(_rd()),
        _radius_dist(0, radius),
        _radian_dist(0, 2 * M_PI) {}

  vector<double> randPoint() {
    const double radian = _radian_dist(_re);
    const double radius = _radius_dist(_re);

    const double rtn_x_val = radius * cos(radian);
    const double rtn_y_val = radius * sin(radian);

    return {rtn_x_val + _x_center, rtn_y_val + _y_center};
  }

 private:
  const double _x_center;
  const double _y_center;
  std::random_device _rd;
  std::default_random_engine _re;
  std::uniform_real_distribution<double> _radius_dist;
  std::uniform_real_distribution<double> _radian_dist;
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(radius, x_center, y_center);
 * vector<double> param_1 = obj->randPoint();
 */

int main(void) {
  double test = sin(M_PI);
  Solution sln(0.01, 0, 0);
  vector<double> rtn;
  for (size_t i = 0; i < 100000; ++i) {
    rtn = sln.randPoint();
    if (0.01 <= rtn[0] * rtn[0] + rtn[1] * rtn[1])
      std::cout << i << std::endl;
  }  


  return 0;
}