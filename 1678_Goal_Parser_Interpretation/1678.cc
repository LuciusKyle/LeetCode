
#include <iostream>
#include <string>

using std::cout;
using std::endl;
using std::string;

class Solution {
 public:
  string interpret(const string command) {
    char rtn[101] = {'\0'};
    for (int str_index = 0, rtn_index = 0; str_index < command.size(); ++str_index)
      if (command[str_index] == 'G')
        rtn[rtn_index++] = 'G';
      else {
        if (command[str_index + 1] == ')') {
          ++str_index;
          rtn[rtn_index++] = 'o';
        } else {
          str_index += 3;
          rtn[rtn_index++] = 'a';
          rtn[rtn_index++] = 'l';
        }
      }

    return rtn;
  }
};

int main(int argc, char* argv[]) {
  Solution sln;
  const string test_str = argc == 2 ? argv[1] : "G()(al)";
  auto rtn = sln.interpret(test_str);
  cout << rtn << endl;
  return 0;
}
