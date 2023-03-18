
#include <string>
#include <vector>

using std::string;
using std::vector;

class BrowserHistory {
 public:
  BrowserHistory(string homepage) : histories_(1, homepage), curr_index_(0) {
    histories_.reserve(100);
  }

  void visit(string url) {
    if (++curr_index_ == histories_.size()) histories_.push_back(url);
    histories_[curr_index_] = url;
    histories_.resize(curr_index_ + 1);
  }

  string back(int steps) {
    if (curr_index_ < steps) steps = curr_index_;
    curr_index_ -= steps;
    return histories_[curr_index_];
  }

  string forward(int steps) {
    if (histories_.size() <= curr_index_ + steps)
      curr_index_ = histories_.size() - 1;
    else
      curr_index_ += steps;
    return histories_[curr_index_];
  }

 private:
  vector<string> histories_;
  int curr_index_;
};

/**
 * Your BrowserHistory object will be instantiated and called as such:
 * BrowserHistory* obj = new BrowserHistory(homepage);
 * obj->visit(url);
 * string param_2 = obj->back(steps);
 * string param_3 = obj->forward(steps);
 */