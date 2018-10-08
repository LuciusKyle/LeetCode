
#include<stack>
#include<set>

using std::stack;
using std::multiset;

class MinStack {
 public:
  /** initialize your data structure here. */
  MinStack() {}

  void push(const int x) {
    internal_stack.push(x);
    internal_set.insert(x);
  }

  void pop() {
    internal_set.erase(internal_set.find(internal_stack.top()));
    internal_stack.pop();
  }

  int top() {
    return internal_stack.top();
  }

  int getMin() {
    return *(internal_set.cbegin());
  }

 private:
  stack<int> internal_stack;
  multiset<int> internal_set;
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack obj = new MinStack();
 * obj.push(x);
 * obj.pop();
 * int param_3 = obj.top();
 * int param_4 = obj.getMin();
 */

int main(void) {
  MinStack obj;
  obj.push(0);
  obj.push(1);
  obj.push(0);
  obj.pop();
  int param_3 = obj.top();
  int param_4 = obj.getMin();
  return 0;
}
