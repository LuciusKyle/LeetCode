
#include <queue>

class MyStack {
 public:
  /** Initialize your data structure here. */
  MyStack() {}

  /** Push element x onto stack. */
  void push(int x) { data_.push(x); }

  /** Removes the element on top of the stack and returns that element. */
  int pop() {
    for (size_t i = 0; i < data_.size() - 1; ++i) {
      data_.push(data_.front());
      data_.pop();
    }
    int rtn = data_.front();
    data_.pop();
    return rtn;
  }

  /** Get the top element. */
  int top() { return data_.back(); }

  /** Returns whether the stack is empty. */
  bool empty() { return data_.empty(); }

 private:
  std::queue<int> data_;
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */