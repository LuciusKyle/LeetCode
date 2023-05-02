
#include <cmath>
#include <numeric>
#include <vector>

using std::vector;

class Solution {
 public:
  vector<int> powerfulIntegers(int x, int y, const int bound) {
    vector<unsigned int> bits_table(bound / 32 + 2);
    vector<int> answer;
    const int smaller_base = std::min(x, y), larger_base = std::max(x, y);
    // int power_x_limit = std::max(1, int(std::log(bound) / std::log(smaller_base))), power_y_limit = std::max(1, int(log(bound) / log(larger_base)));
    int power_x_limit = std::max(1, bound / smaller_base), power_y_limit = std::max(1, bound / larger_base);
    for (int power_y = 0; power_y < power_y_limit; ++power_y) {
      if (bound < 1 + std::pow(larger_base, power_y)) break;
      for (int power_x = 0; power_x < power_x_limit; ++power_x) {
        const int curr_val = std::pow(smaller_base, power_x) + std::pow(larger_base, power_y);
        if (bound < curr_val) break;
        if ((bits_table[curr_val / 32] & (1 << (curr_val % 32))) == 0)
          answer.push_back(curr_val);
        bits_table[curr_val / 32] |= (1 << (curr_val % 32));
      }
    }
    return answer;
  }
};

// official solution.
class Solution_official {
public:
    vector<int> powerfulIntegers(int x, int y, int bound) {
        unordered_set<int> cnt;
        int value1 = 1;
        for (int i = 0; i < 21; i++) {
            int value2 = 1;
            for (int j = 0; j < 21; j++) {
                int value = value1 + value2;
                if (value <= bound) {
                    cnt.emplace(value);
                } else {
                    break;
                }
                value2 *= y;
            }
            if (value1 > bound) {
                break;
            }
            value1 *= x;
        }
        return vector<int>(cnt.begin(), cnt.end());
    }
};

int main(int argc, char *argv[]) {
  Solution sln;
  // sln.powerfulIntegers(2, 3, 2);
  sln.powerfulIntegers(1, 2, 100);
  return 0;
}
