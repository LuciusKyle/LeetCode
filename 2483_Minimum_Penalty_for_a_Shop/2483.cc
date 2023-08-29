
#include <assert.h>
#include <limits.h>

#include <string>

using std::string;

class Solution {
 public:
  int bestClosingTime(const string customers) {
    int total_customer = 0;
    for (const char ch : customers)
      if (ch == 'Y') ++total_customer;
    int min_penalty = total_customer, earliest_hour = 0;
    for (int i = 0, customer_count = 0; i < customers.size(); ++i) {
      if (customers[i] == 'Y') ++customer_count;
      if (((i + 1 - customer_count) + (total_customer - customer_count)) < min_penalty) {
        min_penalty = (i + 1 - customer_count) + (total_customer - customer_count);
        earliest_hour = i + 1;
      }
    }
    return earliest_hour;
  }
};

int main(int argc, char *argv[]) {
  Solution sln;
  assert(0 == sln.bestClosingTime("NYNNNYYN"));
  return 0;
}
