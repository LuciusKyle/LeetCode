
#include <forward_list>
#include <list>
#include <string>
#include <vector>

using std::string;
using std::vector;

class Solution {
 public:
  bool equationsPossible(const vector<string>& equations) {
    vector<string> equal_groups;
    for (const string& equation : equations)
      if (equation[1] == '=' && equation[0] != equation[3]) {
        int left_group = -1, right_group = -1;
        for (int i = 0; i < equal_groups.size(); ++i) {
          if (equal_groups[i].find(equation[0]) != equal_groups[i].npos) left_group = i;
          if (equal_groups[i].find(equation[3]) != equal_groups[i].npos) right_group = i;
        }
        if (left_group == right_group && left_group == -1)
          equal_groups.push_back(string(1, equation[0]) + string(1, equation[3]));
        else if (left_group != right_group) {
          if (left_group == -1)
            equal_groups[right_group].push_back(equation[0]);
          else if (right_group == -1)
            equal_groups[left_group].push_back(equation[3]);
          else {
            equal_groups[left_group].append(equal_groups[right_group]);
            equal_groups.erase(equal_groups.begin() + right_group);
          }
        }
      }

    for (const string& equation : equations)
      if (equation[1] == '!') {
        if (equation[0] == equation[3]) return false;
        int left_group = -1, right_group = -1;
        for (int i = 0; i < equal_groups.size(); ++i) {
          if (equal_groups[i].find(equation[0]) != equal_groups[i].npos) left_group = i;
          if (equal_groups[i].find(equation[3]) != equal_groups[i].npos) right_group = i;
        }
        if (left_group == right_group && left_group != -1) return false;
      }

    return true;
  }
};

int main(void) {
  Solution sln;
  sln.equationsPossible({"c==c", "b==d", "x!=z"});
  return 0;
}
