
#include <forward_list>
#include <list>
#include <string>
#include <vector>

using std::string;
using std::vector;

class Solution {
 public:
  string simplifyPath(string path) {
    string folder_name;
    char pre_ch = '/';
    std::list<string> paths;
    for (int i = 0; i < path.size(); ++i) {
      if (pre_ch != '/' && path[i] == '/') {
        // folder finished.
        if (folder_name == ".") {
          // don't push folder.
          folder_name.clear();
        } else if (folder_name == "..") {
          folder_name.clear();
          if (!paths.empty()) {
            paths.pop_back();
          }
        } else {
          // regular folder.
          paths.push_back(folder_name);
          folder_name.clear();
        }
      } else if (pre_ch == '/' && path[i] == '/') {
        // duplicate '/', do nothing.
      } else if (pre_ch != '/' && path[i] != '/') {
        // folder not finished.
        folder_name.push_back(path[i]);
      } else if (pre_ch == '/' && path[i] != '/') {
        // folder start.
        folder_name.push_back(path[i]);
      }
      pre_ch = path[i];
    }
    if (!folder_name.empty())
      if (folder_name == "..") {
        if (!paths.empty()) paths.pop_back();
      } else if (folder_name != ".")
        paths.push_back(folder_name);

    // reconstruct path.
    path.clear();
    for (auto iter = paths.cbegin(); iter != paths.cend(); ++iter) {
      path.push_back('/');
      path.append(*iter);
    }
    if (path.empty()) return "/";
    return path;
  }
};
