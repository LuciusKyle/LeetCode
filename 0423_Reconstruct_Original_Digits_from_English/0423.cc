
#include <string>

using std::string;

class Solution {
 public:
  string originalDigits(string s) {
    int dict[256]{0};
    int count[10]{0};
    for (const char ch : s) ++dict[ch];

    count[0] = dict['z'];
    dict['z'] = 0;
    dict['e'] -= count[0];
    dict['r'] -= count[0];
    dict['o'] -= count[0];

    count[6] = dict['x'];
    dict['s'] -= count[6];
    dict['i'] -= count[6];
    dict['x'] = 0;

    count[2] = dict['w'];
    dict['t'] -= count[2];
    dict['w'] = 0;
    dict['o'] -= count[2];

    count[7] = dict['s'];
    dict['s'] = 0;
    dict['e'] -= 2 * count[7];
    dict['v'] -= count[7];
    dict['n'] -= count[7];

    count[5] = dict['v'];
    dict['f'] -= count[5];
    dict['i'] -= count[5];
    dict['v'] = 0;
    dict['e'] -= count[5];

    count[4] = dict['f'];
    dict['f'] = 0;
    dict['o'] -= count[4];
    dict['u'] -= count[4];
    dict['r'] -= count[4];

    count[3] = dict['r'];
    dict['t'] -= count[3];
    dict['h'] -= count[3];
    dict['r'] = 0;
    dict['e'] -= 2 * count[3];

    count[1] = dict['o'];
    dict['o'] = 0;
    dict['n'] -= count[1];
    dict['e'] -= count[1];

    count[8] = dict['g'];

    count[9] = dict['n'] / 2;

    string rtn;
    for (int i = 0; i < std::end(count) - std::begin(count); ++i)
      for (int j = 0; j < count[i]; ++j) rtn.push_back('0' + i);
    return rtn;
  }
};