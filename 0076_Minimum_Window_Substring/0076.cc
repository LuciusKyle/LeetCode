
#include <assert.h>

#include <array>
#include <iostream>
#include <string>

using std::array;
using std::cout;
using std::endl;
using std::string;

class Solution {
 public:
  string minWindow(const string s, const string t) {
    int s_count[58] = {'\0'}, t_count[58] = {'\0'};
    for (const char ch : t) ++t_count[ch - 'A'];

    size_t l_index = 0, r_index = 0;
    // enlarge window
    while (r_index < s.size() && !includeAllCharacter(s_count, t_count))
      ++s_count[s[r_index++] - 'A'];

    // is there one possible answer?
    if (!includeAllCharacter(s_count, t_count)) return "";

    size_t temp_l_index = l_index, temp_r_index = r_index;
    --s_count[s[--r_index] - 'A'];
    // move window
    while (r_index < s.size()) {
      ++s_count[s[r_index++] - 'A'];
      // try to shrink window
      if (includeAllCharacter(s_count, t_count))
        do {
          --s_count[s[l_index++] - 'A'];
        } while (includeAllCharacter(s_count, t_count));
      else
        --s_count[s[l_index++] - 'A'];

      if (r_index - l_index + 1 != temp_r_index - temp_l_index) {
        temp_r_index = r_index;
        temp_l_index = l_index - 1;
      }
    }
    if (r_index - l_index + 1 != temp_r_index - temp_l_index) {
      temp_r_index = r_index;
      temp_l_index = l_index - 1;
    }
    return s.substr(temp_l_index, temp_r_index - temp_l_index);
  }

 private:
  bool includeAllCharacter(const int *s_count, const int *t_count) {
    for (int i = 0; i < 58; ++i)
      if (0 < t_count[i] - s_count[i]) return false;
    return true;
  }
};

int main(void) {
  Solution sln;
  auto rtn = sln.minWindow("ADOBECODEBANCabc", "ABC");
  assert("BANC" == rtn);
  rtn = sln.minWindow("ADOBECODEBANC", "ABC");
  assert("BANC" == rtn);
  rtn = sln.minWindow("a", "a");
  assert("a" == rtn);
  rtn = sln.minWindow("wegdtzwabazduwwdysdetrrctotpcepalxdewzezbfewbabbseinxbqqplitpxtcwwhuyntbtzxwzyaufihclztckdwccpeyonumbpnuonsnnsjscrvpsqsftohvfnvtbphcgxyumqjzltspmphefzjypsvugqqjhzlnylhkdqmolggxvneaopadivzqnpzurmhpxqcaiqruwztroxtcnvhxqgndyozpcigzykbiaucyvwrjvknifufxducbkbsmlanllpunlyohwfsssiazeixhebipfcdqdrcqiwftutcrbxjthlulvttcvdtaiwqlnsdvqkrngvghupcbcwnaqiclnvnvtfihylcqwvderjllannflchdklqxidvbjdijrnbpkftbqgpttcagghkqucpcgmfrqqajdbynitrbzgwukyaqhmibpzfxmkoeaqnftnvegohfudbgbbyiqglhhqevcszdkokdbhjjvqqrvrxyvvgldtuljygmsircydhalrlgjeyfvxdstmfyhzjrxsfpcytabdcmwqvhuvmpssingpmnpvgmpletjzunewbamwiirwymqizwxlmojsbaehupiocnmenbcxjwujimthjtvvhenkettylcoppdveeycpuybekulvpgqzmgjrbdrmficwlxarxegrejvrejmvrfuenexojqdqyfmjeoacvjvzsrqycfuvmozzuypfpsvnzjxeazgvibubunzyuvugmvhguyojrlysvxwxxesfioiebidxdzfpumyon", "ozgzyywxvtublcl");
  assert("tcnvhxqgndyozpcigzykbiaucyvwrjvknifufxducbkbsmlanl" == rtn);
  return 0;
}
