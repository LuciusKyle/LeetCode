
#include <array>
#include <set>
#include <string>
#include <unordered_set>
#include <vector>
// #include <tbb/tbb.h>

using std::array;
using std::set;
using std::string;
using std::unordered_set;
using std::vector;

constexpr int positive_movement[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 0};
constexpr int negative_movement[] = {9, 0, 1, 2, 3, 4, 5, 6, 7, 8};

constexpr char positive_ch[] = {'1', '2', '3', '4', '5', '6', '7', '8', '9', '0'};
constexpr char negative_ch[] = {'9', '0', '1', '2', '3', '4', '5', '6', '7', '8'};

// 73% beat.
class Solution {
 public:
  int openLock(const vector<string>& deadends, const string target) {
    unordered_set<int> deadends_set;
    for (const string& deadend : deadends)
      deadends_set.insert(atoi(deadend.c_str()));
    const int target_val = atoi(target.c_str());
    if (target_val == 0) return 0;
    if (deadends_set.count(0) != 0) return -1;
    vector<int> pre_panels({0});
    int move_count = 0;
    int digits[4] = {0};
    int nums[8] = {0};
    do {
      ++move_count;
      vector<int> cur_panel;
      for (const int val : pre_panels) {
        const int digits[] = {val % 10, (val % 100) / 10, (val % 1000) / 100, val / 1000};
        const int nums[] = {
            val - digits[0] + positive_movement[digits[0]],
            val - digits[0] + negative_movement[digits[0]],
            val - digits[1] * 10 + positive_movement[digits[1]] * 10,
            val - digits[1] * 10 + negative_movement[digits[1]] * 10,
            val - digits[2] * 100 + positive_movement[digits[2]] * 100,
            val - digits[2] * 100 + negative_movement[digits[2]] * 100,
            val - digits[3] * 1000 + positive_movement[digits[3]] * 1000,
            val - digits[3] * 1000 + negative_movement[digits[3]] * 1000};
        for (const int num : nums) {
          if (num == target_val) return move_count;
          if (deadends_set.count(num) == 0) {
            deadends_set.insert(num);
            cur_panel.push_back(num);
          }
        }
      }
      pre_panels.swap(cur_panel);
    } while (!pre_panels.empty());
    return -1;
  }
};

int main(void) {
  Solution sln;
  int ret = sln.openLock({"8888"}, "0009");
  ret = sln.openLock({"0201", "0101", "0102", "1212", "2002"}, "0202");
  ret = sln.openLock({"8887", "8889", "8878", "8898", "8788", "8988", "7888", "9888"}, "8888");

  return 0;
}
