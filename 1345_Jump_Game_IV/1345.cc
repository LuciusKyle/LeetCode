
#include <map>
#include <unordered_map>
#include <vector>

using std::vector;

class Solution {
 public:
  int minJumps(const vector<int>& arr) {
    std::map<int, vector<int>> same_num_map;
    for (int i = 0; i < arr.size(); ++i) same_num_map[arr[i]].push_back(i);
    vector<int> steps_vec(arr.size(), -1), curr_pos(1, 0), next_pos;
    steps_vec[0] = 0;
    int step_count = 1;
    while (steps_vec.back() == -1) {
      for (const int pos : curr_pos) {
        // find same number
        for (const int same_num_pos : same_num_map[arr[pos]])
          if (pos != same_num_pos && steps_vec[same_num_pos] == -1) {
            steps_vec[same_num_pos] = step_count;
            next_pos.push_back(same_num_pos);
          }
        same_num_map[arr[pos]].clear();

        // find left or right pos
        if (pos != 0 && steps_vec[pos - 1] == -1) {
          steps_vec[pos - 1] = step_count;
          next_pos.push_back(pos - 1);
        }
        if (pos != arr.size() && steps_vec[pos + 1] == -1) {
          steps_vec[pos + 1] = step_count;
          next_pos.push_back(pos + 1);
        }
      }
      std::swap(curr_pos, next_pos);
      next_pos.clear();
      ++step_count;
    }
    return steps_vec.back();
  }
};
