
#include <stdlib.h>

class MyCircularQueue {
 public:
  MyCircularQueue(int k) : capacity(k), mem_ptr(reinterpret_cast<int*>(malloc(sizeof(int) * k))), front_cursor(0), back_cursor(0), size(0) {}

  ~MyCircularQueue() { free(mem_ptr); }

  bool enQueue(int value) {
    if (size == capacity) return false;
    if (back_cursor == capacity)
      back_cursor = 0;
    mem_ptr[back_cursor++] = value;
    ++size;
    return true;
  }

  bool deQueue() {
    if (size == 0) return false;
    if (front_cursor + 1 == capacity)
      front_cursor = 0;
    else
      ++front_cursor;
    --size;
    return true;
  }

  int Front() const { return size == 0 ? -1 : mem_ptr[front_cursor]; }

  int Rear() const { return size == 0 ? -1 : mem_ptr[back_cursor - 1]; }

  bool isEmpty() const { return size == 0; }

  bool isFull() const { return size == capacity; }

 private:
  const int capacity;
  int* mem_ptr;
  int front_cursor, back_cursor, size;
};

/**
 * Your MyCircularQueue object will be instantiated and called as such:
 * MyCircularQueue* obj = new MyCircularQueue(k);
 * bool param_1 = obj->enQueue(value);
 * bool param_2 = obj->deQueue();
 * int param_3 = obj->Front();
 * int param_4 = obj->Rear();
 * bool param_5 = obj->isEmpty();
 * bool param_6 = obj->isFull();
 */
