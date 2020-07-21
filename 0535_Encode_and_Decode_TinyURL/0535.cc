
#include <array>
#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

using std::string;
using std::unordered_map;
using std::vector;

const int ID_dict[] = { 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,53,0,0,54,55,56,57,58,59,60,61,62,63,0,0,0,0,0,0,0,26,27,28,29,30,31,32,33,34,35,36,37,38,39,40,41,42,43,44,45,46,47,48,49,50,51,0,0,0,0,52,0,0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25 };
const char dict[] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ_-0123456789";

class Solution {
 public:
  // Encodes a URL to a shortened URL.
  string encode(string longUrl) {
    longURLs.push_back(longUrl);
    return "http://tinyurl.com/" + IDToShortURL(longURLs.size() - 1);
  }

  // Decodes a shortened URL to its original URL.
  string decode(string shortUrl) {
    string url = shortUrl.c_str() + 19;
    int index = shortURLToID(url);
    return longURLs[index];
  }

 private:
  vector<string> longURLs;
  int shortURLToID(const string &shortURL) {
    int ID = 0;
    for (const char ch : shortURL) ID = ID * 64 + ID_dict[ch];
    return ID;
  }
  string IDToShortURL(int ID) {
    string shortURL;
    while (ID) {
      shortURL.push_back(dict[ID % 64]);
      ID /= 64;
    }
    return {shortURL.crbegin(), shortURL.crend()};
  }
};

// Your Solution object will be instantiated and called as such:
// Solution solution;
// solution.decode(solution.encode(url));

int main(void) {
  // for (int i = 0; i < 256; ++i) std::cout << i << std::endl;
  for (const char ch : dict) std::cout << ID_dict[ch] << std::endl;
  Solution sln;
  return 0;
}