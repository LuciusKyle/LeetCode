
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
    static_assert(sizeof(size_t) == 8);

    size_t ch_dict[4] = {0};
    array<bool, 256> ch_dict_arr{false};
    array<size_t, 256> ch_count{0};
    for (const auto ch : t) {
      ch_dict[ch / 64] |= (1 << (ch % 64));
      ch_dict_arr[ch] = true;
    }
    size_t max_len = s.size();
    size_t start_index = 0;
    size_t end_index = 0;
    size_t ch_result[4] = {0};
    for (size_t i = 0; i < s.size(); ++i) {
      if (max_len < i - start_index) {
        const size_t temp_start_index = i < max_len ? 0 : i - max_len;
        if (ch_dict_arr[s[temp_start_index]]) {
          assert(ch_count[s[temp_start_index]] != 0);
          if (ch_count[s[temp_start_index]] == 1)
            ch_result[s[temp_start_index] / 64] &=
                (1 << (s[temp_start_index] % 64));
          --ch_count[s[temp_start_index]];
        }
      }
      if (!ch_dict_arr[s[i]]) continue;
      ++ch_count[s[i]];
      if (ch_count[s[i]] == 1) {
        ch_result[s[i] / 64] |= (1 << (s[i] % 64));
      }
      if (sameArr(ch_dict, ch_result)) {
        // shrink window.
        end_index = i + 1;
        max_len = i - start_index;
        for (start_index = i < max_len ? 0 : i - max_len; start_index < i; ++start_index) {
          if (i - start_index < max_len) max_len = i - start_index;
          if (!ch_dict_arr[s[start_index]]) continue;
          assert(ch_count[s[start_index]] != 0);
          if (ch_count[s[start_index]] == 1)
            break;
          else
            --ch_count[s[start_index]];
        }
      }
    }

    if (max_len == s.size())
      return "";
    else
      return {s.cbegin() + start_index, s.cbegin() + end_index};
  }

 private:
  bool sameArr(const size_t *a, const size_t *b, const size_t len = 4) const {
    for (size_t i = 0; i < len; ++i)
      if (a[i] != b[i]) return false;

    return true;
  }
};

int main(void) {
  Solution sln;
  assert("BANC" == sln.minWindow("ADOBECODEBANC", "ABC"));

  auto rtn = sln.minWindow("wegdtzwabazduwwdysdetrrctotpcepalxdewzezbfewbabbseinxbqqplitpxtcwwhuyntbtzxwzyaufihclztckdwccpeyonumbpnuonsnnsjscrvpsqsftohvfnvtbphcgxyumqjzltspmphefzjypsvugqqjhzlnylhkdqmolggxvneaopadivzqnpzurmhpxqcaiqruwztroxtcnvhxqgndyozpcigzykbiaucyvwrjvknifufxducbkbsmlanllpunlyohwfsssiazeixhebipfcdqdrcqiwftutcrbxjthlulvttcvdtaiwqlnsdvqkrngvghupcbcwnaqiclnvnvtfihylcqwvderjllannflchdklqxidvbjdijrnbpkftbqgpttcagghkqucpcgmfrqqajdbynitrbzgwukyaqhmibpzfxmkoeaqnftnvegohfudbgbbyiqglhhqevcszdkokdbhjjvqqrvrxyvvgldtuljygmsircydhalrlgjeyfvxdstmfyhzjrxsfpcytabdcmwqvhuvmpssingpmnpvgmpletjzunewbamwiirwymqizwxlmojsbaehupiocnmenbcxjwujimthjtvvhenkettylcoppdveeycpuybekulvpgqzmgjrbdrmficwlxarxegrejvrejmvrfuenexojqdqyfmjeoacvjvzsrqycfuvmozzuypfpsvnzjxeazgvibubunzyuvugmvhguyojrlysvxwxxesfioiebidxdzfpumyon", "ozgzyywxvtublcl");

  return 0;
}
