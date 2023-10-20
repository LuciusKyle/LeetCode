
#include <vector>

using std::vector;

// This is the interface that allows for creating nested lists.
// You should not implement it, or speculate about its implementation
class NestedInteger {
 public:
  // Return true if this NestedInteger holds a single integer, rather than a nested list.
  bool isInteger() const;

  // Return the single integer that this NestedInteger holds, if it holds a single integer
  // The result is undefined if this NestedInteger holds a nested list
  int getInteger() const;

  // Return the nested list that this NestedInteger holds, if it holds a nested list
  // The result is undefined if this NestedInteger holds a single integer
  const vector<NestedInteger> &getList() const;
};

class NestedIterator {
 public:
  NestedIterator(const vector<NestedInteger> &nestedList) : curr_index_(0) {
    for (const auto &ele : nestedList)
      if (ele.isInteger())
        values_.push_back(ele.getInteger());
      else {
        NestedIterator iter(ele.getList());
        while (iter.hasNext())
          values_.push_back(iter.next());
      }
  }

  int next() {
    return values_[curr_index_++];
  }

  bool hasNext() const {
    return curr_index_ != values_.size();
  }

 private:
  vector<int> values_;
  int curr_index_;
};

/**
 * Your NestedIterator object will be instantiated and called as such:
 * NestedIterator i(nestedList);
 * while (i.hasNext()) cout << i.next();
 */
