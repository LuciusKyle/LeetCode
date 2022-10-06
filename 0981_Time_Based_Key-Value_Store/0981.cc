
#include <map>
#include <string>
#include <unordered_map>
#include <vector>

using std::map;
using std::string;
using std::vector;

class TimeMap {
 public:
  TimeMap() {}

  void set(const string key, const string value, const int timestamp) { k_v_map_[key].push_back({timestamp, value}); }

  string get(const string key, const int timestamp) const {
    if (k_v_map_.count(key) == 0) return "";
    const auto &vec = k_v_map_.find(key)->second;
    if (timestamp < vec.front().first) return "";
    if (vec.back().first <= timestamp) return vec.back().second;
    int left_index = 0, right_index = vec.size() - 1;
    while (left_index + 1 < right_index) {
      const int mid = (left_index + right_index) / 2;
      if (vec[mid].first < timestamp)
        left_index = mid;
      else if (timestamp < vec[mid].first)
        right_index = mid;
      else
        return vec[mid].second;
    }
    return vec[left_index].second;
  }

 private:
  map<string, vector<std::pair<int, string>>> k_v_map_;
  // std::unordered_map<string, vector<std::pair<int, string>>> k_v_map_;  // unordered_map uses more time on LeetCode.
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */