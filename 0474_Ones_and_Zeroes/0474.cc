
#include <map>
#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <chrono>

using std::map;
using std::string;
using std::vector;
using std::unordered_map;

// Time Limit Exceeded!
class Solution1 {
 public:
  int findMaxForm(const vector<string>& strs, int m, int n) {
    vector<map<size_t, int>> result(strs.size());
    return findMaxForm(strs, m, n, 0, result);
  }

 private:
  int findMaxForm(const vector<string>& strs, const int zero, const int one, const int index, vector<map<size_t, int>> &result) {
    const int current_str_zero = std::count(strs[index].begin(), strs[index].end(), '0');
    bool can_form_current = (current_str_zero <= zero && strs[index].size() - current_str_zero <= one);
    if (index + 1 == strs.size()) {
      if (can_form_current) return 1;
      else return 0;
    }
    if (result[index].count((size_t(zero) << 32) | one)!=0) return result[index].at((size_t(zero) << 32) | one);
    const int form_current = can_form_current ? 1 + findMaxForm(strs, zero - current_str_zero, one - (strs[index].size() - current_str_zero), index + 1, result) : 0;
    const int not_form_current = findMaxForm(strs, zero, one, index + 1, result);
    result[index].insert({(size_t(zero) << 32) | one, form_current < not_form_current ? not_form_current : form_current});
    return result[index].at((size_t(zero) << 32) | one);
  }
};

// 5% beat.
class Solution {
 public:
  int findMaxForm(const vector<string>& strs, int m, int n) {
    vector<unordered_map<size_t, int>> result(strs.size());
    return findMaxForm(strs, m, n, 0, result);
  }

 private:
  int findMaxForm(const vector<string>& strs, const int zero, const int one, const int index, vector<unordered_map<size_t, int>>& result) {
    // if (one == 0 && zero == 0) return 0;
    const auto &string_ref = strs[index];
    int cur_zero = 0, cur_one = 0;
    for (const char ch : string_ref) if (ch == '0') ++cur_zero; else ++cur_one;
    bool can_form_current = (cur_zero <= zero && string_ref.size() - cur_zero <= one);
    if (index + 1 == strs.size()) return can_form_current ? 1 : 0;
    auto& map_ref = result[index];
    const size_t key_val = (size_t(zero) << 32 | one);
    if (map_ref.find(key_val) != map_ref.end()) return map_ref.at(key_val);
    const int form_current = can_form_current ? 1 + findMaxForm(strs, zero - cur_zero, one - cur_one, index + 1, result) : 0;
    const int not_form_current = findMaxForm(strs, zero, one, index + 1, result);
    map_ref.insert({key_val, form_current < not_form_current ? not_form_current : form_current});
    return form_current < not_form_current ? not_form_current : form_current;
  }
};

int main(void) {
  
  auto start = std::chrono::system_clock::now();


  Solution sln;
  int rtn = sln.findMaxForm({"10", "0001", "111001", "1", "0"}, 4, 3);
  start = std::chrono::system_clock::now();
  rtn = sln.findMaxForm(
      {"1101", "0101", "1101", "0101", "1101", "0101", "1101", "0101", "1101",
       "0101", "1101", "0101", "1101", "0101", "1101", "0101", "1101", "0101",
       "1101", "0101", "1101", "0101", "1101", "0101", "1101", "0101", "1101",
       "0101", "1101", "0101", "1101", "0101", "1101", "0101", "1101", "0101",
       "1101", "0101", "1101", "0101", "1101", "0101", "1101", "0101", "1101",
       "0101", "1101", "0101", "1101", "0101", "1101", "0101", "1101", "0101",
       "1101", "0101", "1101", "0101", "1101", "0101", "1101", "0101", "1101",
       "0101", "1101", "0101", "1101", "0101", "1101", "0101", "1101", "0101",
       "1101", "0101", "1101", "0101", "1101", "0101", "1101", "0101", "1101",
       "0101", "1101", "0101", "1101", "0101", "1101", "0101", "1101", "0101",
       "1101", "0101", "1101", "0101", "1101", "0101", "1101", "0101", "1101",
       "0101", "1101", "0101", "1101", "0101", "1101", "0101", "1101", "0101",
       "1101", "0101", "1101", "0101", "1101", "0101", "1101", "0101", "1101",
       "0101", "1101", "0101", "1101", "0101", "1101", "0101", "1101", "0101",
       "1101", "0101", "1101", "0101", "1101", "0101", "1101", "0101", "1101",
       "0101", "1101", "0101", "1101", "0101", "1101", "0101", "1101", "0101",
       "1101", "0101", "1101", "0101", "1101", "0101", "1101", "0101", "1101",
       "0101", "1101", "0101", "1101", "0101", "1101", "0101", "1101", "0101",
       "1101", "0101", "1101", "0101", "1101", "0101", "1101", "0101", "1101",
       "0101", "1101", "0101", "1101", "0101", "1101", "0101", "1101", "0101",
       "1101", "0101", "1101", "0101", "1101", "0101", "1101", "0101", "1101",
       "0101", "1101", "0101", "1101", "0101", "1101", "0101", "1101", "0101",
       "1101", "0101", "1101", "0101", "1101", "0101", "1101", "0101", "1101",
       "0101", "1101", "0101", "1101", "0101", "1101", "0101", "1101", "0101",
       "1101", "0101", "1101", "0101", "1101", "0101", "1101", "0101", "1101",
       "0101", "1101", "0101", "1101", "0101", "1101", "0101", "1101", "0101",
       "1101", "0101", "1101", "0101", "1101", "0101", "1101", "0101", "1101",
       "0101", "1101", "0101", "1101", "0101", "1101", "0101", "1101", "0101",
       "1101", "0101", "1101", "0101", "1101", "0101", "1101", "0101", "1101",
       "0101", "1101", "0101", "1101", "0101", "1101", "0101", "1101", "0101",
       "1101", "0101", "1101", "0101", "1101", "0101", "1101", "0101", "1101",
       "0101", "1101", "0101", "1101", "0101", "1101", "0101", "1101", "0101",
       "1101", "0101", "1101", "0101", "1101", "0101", "1101", "0101", "1101",
       "0101", "1101", "0101", "1101", "0101", "1101", "0101", "1101", "0101",
       "1101", "0101", "1101", "0101", "1101", "0101", "1101", "0101", "1101",
       "0101", "1101", "0101", "1101", "0101", "1101", "0101", "1101", "0101",
       "1101", "0101", "1101", "0101", "1101", "0101", "1101", "0101", "1101",
       "0101", "1101", "0101", "1101", "0101", "1101", "0101", "1101", "0101",
       "1101", "0101", "1101", "0101", "1101", "0101", "1101", "0101", "1101",
       "0101", "1101", "0101", "1101", "0101", "1101", "0101", "1101", "0101",
       "1101", "0101", "1101", "0101", "1101", "0101", "1101", "0101", "1101",
       "0101", "1101", "0101", "1101", "0101", "1101", "0101", "1101", "0101",
       "1101", "0101", "1101", "0101", "1101", "0101", "1101", "0101", "1101",
       "0101", "1101", "0101", "1101", "0101", "1101", "0101", "1101", "0101",
       "1101", "0101", "1101", "0101", "1101", "0101", "1101", "0101", "1101",
       "0101", "1101", "0101", "1101", "0101", "1101", "0101", "1101", "0101",
       "1101", "0101", "1101", "0101", "1101", "0101", "1101", "0101", "1101",
       "0101", "1101", "0101", "1101", "0101", "1101", "0101", "1101", "0101",
       "1101", "0101", "1101", "0101", "1101", "0101", "1101", "0101", "1101",
       "0101", "1101", "0101", "1101", "0101", "1101", "0101", "1101", "0101",
       "1101", "0101", "1101", "0101", "1101", "0101", "1101", "0101", "1101",
       "0101", "1101", "0101", "1101", "0101", "1101", "0101", "1101", "0101",
       "1101", "0101", "1101", "0101", "1101", "0101", "1101", "0101", "1101",
       "0101", "1101", "0101", "1101", "0101", "1101", "0101", "1101", "0101",
       "1101", "0101", "1101", "0101", "1101", "0101", "1101", "0101", "1101",
       "0101", "1101", "0101", "1101", "0101", "1101", "0101", "1101", "0101",
       "1101", "0101", "1101", "0101", "1101", "0101", "1101", "0101", "1101",
       "0101", "1101", "0101", "1101", "0101", "1101", "0101", "1101", "0101",
       "1101", "0101", "1101", "0101"},
      100, 100);

  std::cout << "time: "
            << std::chrono::duration_cast<std::chrono::milliseconds>(
                   std::chrono::system_clock::now() - start)
                   .count()
            << " milliseconds" << std::endl;
  return 0;
}

