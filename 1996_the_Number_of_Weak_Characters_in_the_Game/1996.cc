
#include <assert.h>
#include <limits.h>

#include <algorithm>
#include <chrono>
#include <execution>
#include <iostream>
#include <vector>

using std::vector;

class Solution {
 public:
  int numberOfWeakCharacters(vector<vector<int>> &properties) {
    if (properties.size() < 65536)
      std::sort(properties.begin(), properties.end(), [](const vector<int> &_l_vec, const vector<int> &_r_vec) -> bool {if (_l_vec[0]<_r_vec[0]) return true; else if (_r_vec[0] < _l_vec[0] ) return false; else return _l_vec[1] < _r_vec[1]; });
    else
      std::sort(std::execution::par_unseq, properties.begin(), properties.end(), [](const vector<int> &_l_vec, const vector<int> &_r_vec) -> bool {if (_l_vec[0]<_r_vec[0]) return true; else if (_r_vec[0] < _l_vec[0] ) return false; else return _l_vec[1] < _r_vec[1]; });
    int weak_character_count = 0;
    for (int i = properties.size() - 1, curr_max = INT_MIN, pre_attack = INT_MAX, next_max_defence = INT_MIN; 0 <= i; --i) {
      if (pre_attack != properties[i][0]) {
        curr_max = next_max_defence;
        if (next_max_defence < properties[i][1])
          next_max_defence = properties[i][1];
        pre_attack = properties[i][0];
      }
      if (properties[i][1] < curr_max) ++weak_character_count;
    }
    return weak_character_count;
  }
};

int main(void) {
  vector<vector<int>> test_vec{{10, 1}, {5, 1}, {7, 10}, {4, 1}, {5, 9}, {6, 9}, {7, 2}, {1, 10}};
  Solution sln;
  sln.numberOfWeakCharacters(test_vec);
  test_vec.clear();

  FILE *fp = fopen("testcase1", "rb");
  char *text_buf = new char[4 * 1024 * 1024]{'\0'};
  fread(text_buf, 1, 2 * 1024 * 1024, fp);
  int cur_pos = 0, num_count = 0, first_num = -1, second_num = -1;
  do {
    while (('9' < text_buf[cur_pos] || text_buf[cur_pos] < '0') && text_buf[cur_pos] != '\0') ++cur_pos;

    if (num_count % 2 == 0)
      first_num = atoi(text_buf + cur_pos);
    else {
      second_num = atoi(text_buf + cur_pos);
      test_vec.push_back({first_num, second_num});
    }
    ++num_count;
    while ('0' <= text_buf[cur_pos] && text_buf[cur_pos] <= '9') ++cur_pos;
  } while (text_buf[cur_pos] != '\0');
  fclose(fp);
  delete[] text_buf;
  assert(test_vec.size() == 100000);
  auto start_time = std::chrono::system_clock().now();
  int result = sln.numberOfWeakCharacters(test_vec);
  std::cout << "result: " << result << "\ttime: " << std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock().now() - start_time).count() << " milliseconds" << std::endl;
  return 0;
}
