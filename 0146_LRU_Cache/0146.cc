
#include <list>
#include <unordered_map>

using std::list;
using std::unordered_map;

class LRUCache {
 public:
  LRUCache(int capacity) : capacity_(capacity) { cache_.reserve(capacity + (4096 < capacity ? 256 : 32)); }

  int get(int key) {
    if (0 < cache_.count(key)) {
      const int value = cache_[key]->second;
      values_.erase(cache_[key]);
      values_.push_front({key, value});
      cache_[key] = values_.cbegin();
      return value;
    }
    return -1;
  }

  void put(int key, int value) {
    if (0 < cache_.count(key)) {
      values_.erase(cache_[key]);
      values_.push_front({key, value});
      cache_[key] = values_.cbegin();
    } else {
      values_.push_front({key, value});
      cache_.insert({key, values_.cbegin()});
      if (capacity_ < cache_.size()) {
        cache_.erase(values_.back().first);
        values_.pop_back();
      }
    }
  }

 private:
  const int capacity_;
  unordered_map<int, list<std::pair<int, int>>::const_iterator> cache_;
  list<std::pair<int, int>> values_;
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */

int main(void) {
  LRUCache sln(2);
  sln.put(1, 1);
  sln.put(2, 2);
  sln.put(3, 3);
  int ret = sln.get(2);
  return 0;
}