
#include <time.h>

#include <chrono>
#include <iostream>
#include <random>
#include <string>

using std::cout;
using std::endl;
using std::string;

class Solution {
 public:
  int minPartitions(const string &n) {
    int result = 0;
    for (const int digit : n)
      if (result < digit - '0') result = digit - '0';

    return result;
  }
};

int main(void) {
  auto time_point = std::chrono::system_clock::now();

  std::default_random_engine re(time(nullptr));
  std::uniform_int_distribution<char> u_dist(0 + '0', 9 + '0');
  string test_str;
  test_str.reserve(1000016);
  for (int i = 0; i < 100000; ++i) test_str.push_back(u_dist(re));
  cout << "generate test data: " << std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now() - time_point).count() << " milliseconds\n";

  Solution sln;
  time_point = std::chrono::system_clock::now();
  int ret = sln.minPartitions(test_str);
  cout << "calculate answer: " << std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now() - time_point).count() << " milliseconds\n";

  return 0;
}