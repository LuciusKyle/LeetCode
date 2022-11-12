
#include <assert.h>
#include <limits.h>
#include <set>
#include <vector>

using std::multiset;
using std::vector;

class MedianFinder {
 public:
  /** initialize your data structure here. */
  MedianFinder() {}

  void addNum(int num) {
    if (smaller_nums_.empty() || num < *smaller_nums_.crbegin()) {
      smaller_nums_.insert(num);
      if (1 < smaller_nums_.size() - greater_nums_.size()) {
        greater_nums_.insert(*smaller_nums_.crbegin());
        smaller_nums_.erase(--smaller_nums_.end());
      }
    } else {
      greater_nums_.insert(num);
      if (1 < greater_nums_.size() - smaller_nums_.size()) {
        smaller_nums_.insert(*greater_nums_.cbegin());
        greater_nums_.erase(greater_nums_.begin());
      }
    }
  }

  double findMedian() {
    // if (greater_nums_.empty() && smaller_nums_.empty()) abort(); // LeetCode don't test this.
    if (smaller_nums_.size() == greater_nums_.size())
      return (double(*greater_nums_.cbegin()) + *smaller_nums_.crbegin()) / 2;
    else
      return greater_nums_.size() < smaller_nums_.size() ? *smaller_nums_.crbegin() : *greater_nums_.cbegin();
  }

 private:
  multiset<int> greater_nums_;
  multiset<int> smaller_nums_;
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder obj = new MedianFinder();
 * obj.addNum(num);
 * double param_2 = obj.findMedian();
 */

int main(void) {
  multiset<int> debug_set;
  debug_set.insert(1);
  debug_set.insert(1);
  debug_set.insert(1);
  debug_set.insert(1);
  debug_set.insert(1);
  debug_set.erase(1);
  debug_set.insert(1);
  debug_set.insert(1);
  debug_set.insert(1);
  debug_set.insert(1);
  debug_set.erase(--debug_set.end());

  MedianFinder sln;
  vector test_sample{40, 12, 16, 14, 35, 19, 34, 35, 28, 35, 26, 6,  8,  2,
                     14, 25, 25, 4,  33, 18, 10, 14, 27, 3,  35, 13, 24, 27,
                     14, 5,  0,  38, 19, 25, 11, 14, 31, 30, 11, 31, 0};
  for (size_t i = 0; i < test_sample.size(); ++i) {
    sln.addNum(test_sample[i]);
    if (33 == i) double result = sln.findMedian();
    double result = sln.findMedian();
  }
  return 0;
}