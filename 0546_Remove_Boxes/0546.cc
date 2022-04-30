
#include <assert.h>
#include <string.h>

#include <algorithm>
#include <iostream>
#include <map>
#include <unordered_map>
#include <vector>

using std::cout;
using std::endl;
using std::map;
using std::string;
using std::vector;


class Solution {
 public:
  Solution() : debug_map_hit_count_(0) {}
  int removeBoxes(const vector<int> &boxes) {
    char *next_boxes = new char[boxes.size()];
    for (size_t i = 0; i < boxes.size(); ++i) next_boxes[i] = static_cast<char>(boxes[i]);
    const int score = removeBoxes(string(next_boxes, boxes.size()));
    delete[] next_boxes;
    return score;
  }

 private:
  int removeBoxes(const string& boxes) {
    {
      char unique_dict[100] = {0};
      bool all_unique = true;
      for (int i = 0; i < boxes.size(); ++i)
        if (unique_dict[boxes[i]] == 0)
          unique_dict[boxes[i]] = 1;
        else {
          all_unique = false;
          break;
        }
      if (all_unique) return boxes.size();
    }
    const auto iter = answer_cache_.find(boxes);
    if (answer_cache_.end() != iter) {
      ++debug_map_hit_count_;
      return iter->second;
    }

    char pre_color = boxes[0];
    int contiguous_count = 1;
    int max_score = -1;
    for (int i = 1; i < boxes.size(); ++i) {
      if (pre_color == boxes[i]) {
        ++contiguous_count;
      } else {
        string next_boxes(boxes.size() - contiguous_count, 0);
        memcpy(next_boxes.data(), boxes.data(), i - contiguous_count);
        memcpy(next_boxes.data() + i - contiguous_count, boxes.data() + i, boxes.size() - i);
        const int score = contiguous_count * contiguous_count + removeBoxes(next_boxes);
        if (max_score < score) max_score = score;
        contiguous_count = 1;
        pre_color = boxes[i];
      }
    }
    const int answer = 0 < max_score ? max_score : contiguous_count * contiguous_count;
    answer_cache_.insert({boxes, answer});
    return answer;
  }

  std::unordered_map<string, int> answer_cache_;
  size_t debug_map_hit_count_;
};

int main(int argc, char* argv[]) {
  Solution sln;
  int ret = sln.removeBoxes(vector{1, 3, 2, 2, 2, 3, 4, 3, 1});
  assert(ret == 23);
  ret = sln.removeBoxes(vector{1, 1, 1});
  assert(ret == 9);
  ret = sln.removeBoxes(vector{1, 2, 2, 1, 1, 1, 2, 1, 1, 2, 1, 2, 1, 1, 2, 2, 1, 1, 2, 2, 1, 1, 1, 2, 2, 2, 2, 1, 2, 1, 1, 2, 2, 1, 2, 1, 2, 2, 2, 2, 2, 1, 2, 1, 2, 2, 1, 1, 1, 2, 2, 1, 2, 1, 2, 2, 1, 2, 1, 1, 1, 2, 2, 2, 2, 2, 1, 2, 2, 2, 2, 2, 1, 1, 1, 1, 1, 2, 2, 2, 2, 2, 1, 1, 1, 1, 2, 2, 1, 1, 1, 1, 1, 1, 1, 2, 1, 2, 2, 1});
  assert(ret == 2758);
  return 0;
}
