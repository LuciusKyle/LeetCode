
#include <stdlib.h>
#include <time.h>

#include <unordered_map>
#include <vector>

class RandomizedSet {
 public:
  RandomizedSet() { srand(time(nullptr)); }

  bool insert(int val) {
    if (val_index_map_.count(val) == 1) return false;
    if (vals_.size() == val_index_map_.size()) {
      val_index_map_.insert({val, vals_.size()});
      vals_.push_back(val);
    } else {
      vals_[val_index_map_.size()] = val;
      val_index_map_.insert({val, val_index_map_.size()});
    }
    return true;
  }

  bool remove(int val) {
    if (val_index_map_.count(val) == 0) return false;
    const int pos = val_index_map_.at(val);
    const int last_pos = val_index_map_.size() - 1;
    if (pos != last_pos) {
      vals_[pos] = vals_[last_pos];
      val_index_map_[vals_[last_pos]] = pos;
    }
    val_index_map_.erase(val);
    return true;
  }

  int getRandom() { return vals_[rand() % val_index_map_.size()]; }

 private:
  std::unordered_map<int, int> val_index_map_;
  std::vector<int> vals_;
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */