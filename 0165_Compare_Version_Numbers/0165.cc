
#include <string>
#include <stdlib.h>
#include <string.h>

using std::string;

// C++ version.
class Solution {
 public:
  int compareVersion(const string version1, const string version2) {
    const char *sub_version1 = version1.data(), *sub_version2 = version2.data();
    while (sub_version1 != nullptr || sub_version2 != nullptr) {
      int num1 = sub_version1 == nullptr ? 0 : atoi(sub_version1);
      int num2 = sub_version2 == nullptr ? 0 : atoi(sub_version2);
      if (sub_version1 != nullptr) sub_version1 = strstr(sub_version1, ".");
      if (sub_version1 != nullptr) ++sub_version1;
      if (sub_version2 != nullptr) sub_version2 = strstr(sub_version2, ".");
      if (sub_version2 != nullptr) ++sub_version2;
      if (num1 < num2) return -1;
      if (num2 < num1) return 1;
    }
    return 0;
  }
};

// C language version.
int compareVersion(const char *version1, const char *version2) {
  const char *v1 = version1, *v2 = version2;
  while (v1 != NULL || v2 != NULL) {
    int i1 = v1 == NULL ? 0 : atoi(v1), i2 = v2 == NULL ? 0 : atoi(v2);
    if (v1 != NULL) v1 = strstr(v1, ".");
    if (v1 != NULL) ++v1;
    if (v2 != NULL) v2 = strstr(v2, ".");
    if (v2 != NULL) ++v2;
    if (i1 < i2) return -1;
    if (i2 < i1) return 1;
  }
  return 0;
}

int main(void) {
  string str("1.2.3.4.5");
  long l = std::strtol(str.c_str(), nullptr, 10);
  l = std::atoi("");
  const char *v = strstr(str.c_str(), ".");
  v = strstr(v + 1, ".");

  Solution sln;
  int rtn = sln.compareVersion("1", "1.1");
  return 0;
}
