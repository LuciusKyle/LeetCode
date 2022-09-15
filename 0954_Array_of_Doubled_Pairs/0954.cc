
#include <limits.h>

#include <unordered_map>
#include <vector>

using std::vector;

class Solution {
 public:
  bool canReorderDoubled(const vector<int>& arr) {
    int max_positive_val = INT_MIN, min_positive_val = INT_MAX, zero_counter = 0, closest_negative_val = -100000, furtherest_negatie_val = 0;
    std::unordered_map<int, int> num_counter;
    num_counter.reserve(1023 < arr.size() ? arr.size() + 256 : arr.size() + 32);
    for (const int num : arr)
      if (num < 0) {
        if (num < furtherest_negatie_val) furtherest_negatie_val = num;
        if (closest_negative_val < num) closest_negative_val = num;
        ++num_counter[num];
      } else if (0 < num) {
        if (num < min_positive_val) min_positive_val = num;
        if (max_positive_val < num) max_positive_val = num;
        ++num_counter[num];
      } else
        ++zero_counter;

    if (zero_counter % 2 != 0) return false;
    for (int i = min_positive_val; i <= max_positive_val; ++i)
      while (num_counter.count(i) != 0) {
        if (num_counter.count(i * 2) == 0) return false;
        --num_counter[i];
        if (num_counter[i] == 0) num_counter.erase(i);
        --num_counter[i * 2];
        if (num_counter[i * 2] == 0) num_counter.erase(i * 2);
      }

    for (int i = closest_negative_val; furtherest_negatie_val <= i; --i)
      while (num_counter.count(i) != 0) {
        if (num_counter.count(i * 2) == 0) return false;
        --num_counter[i];
        if (num_counter[i] == 0) num_counter.erase(i);
        --num_counter[i * 2];
        if (num_counter[i * 2] == 0) num_counter.erase(i * 2);
      }

    return true;
  }
};

int main(void) {
  Solution sln;
  sln.canReorderDoubled({-3, -5});
  return 0;
}