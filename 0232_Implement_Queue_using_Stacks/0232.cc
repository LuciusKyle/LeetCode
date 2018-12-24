
#include <stack>

class MyQueue {
 public:
  /** Initialize your data structure here. */
  MyQueue() : bottom_of_my_stack_(0) {}

  /** Push element x to the back of queue. */
  void push(int x) {
    if (my_stack_.empty()) bottom_of_my_stack_ = x;
    my_stack_.push(x);
  }

  /** Removes the element from in front of queue and returns that element. */
  int pop() {
    std::stack<int> temp_stack;
    while (!my_stack_.empty()) {
      temp_stack.push(my_stack_.top());
      my_stack_.pop();
    }
    const int rtn = temp_stack.top();
    temp_stack.pop();
    if (!temp_stack.empty()) bottom_of_my_stack_ = temp_stack.top();
    while (!temp_stack.empty()) {
      my_stack_.push(temp_stack.top());
      temp_stack.pop();
    }
    return rtn;
  }

  /** Get the front element. */
  int peek() { return bottom_of_my_stack_; }

  /** Returns whether the queue is empty. */
  bool empty() { return my_stack_.empty(); }

 private:
  int bottom_of_my_stack_;
  std::stack<int> my_stack_;
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue obj = new MyQueue();
 * obj.push(x);
 * int param_2 = obj.pop();
 * int param_3 = obj.peek();
 * bool param_4 = obj.empty();
 */

int main(int argc, char const *argv[]) {
  MyQueue test_queue;
  test_queue.push(1);
  test_queue.pop();
  bool rtn = test_queue.empty();
  return 0;
}

