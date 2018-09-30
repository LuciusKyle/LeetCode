
#include<vector>
#include<string>
#include<unordered_map>
//#include<unordered_set>

using std::vector;
using std::string;
using std::unordered_map;
//using std::unordered_set;

class Solution {
 public:
  int ladderLength(string beginWord, string endWord, vector<string> &wordList) {
    if (wordList.size() == 1) return wordList[0] == endWord ? 2 : 0;

    vector<size_t> steps_count(wordList.size(), 0);
    vector<string> buffer;
    for (size_t i = 0; i < wordList.size(); ++i)
      if (ValidTransformation(beginWord, wordList[i])) {
        if (wordList[i] == endWord) return 2;
        steps_count[i] = 1;
        buffer.push_back(wordList[i]);
      }

    vector<string> buffer2;
    for (size_t i = 2; i <= wordList.size(); ++i) {
      for (const auto &word : buffer) {
        for (size_t ii = 0; ii < wordList.size(); ++ii) {
          if (steps_count[ii] == 0 && ValidTransformation(word, wordList[ii])) {
            steps_count[ii] = i;
            if (wordList[ii] == endWord) {
              return static_cast<int>(i + 1);
            }
            buffer2.push_back(wordList[ii]);
          }
        }
      }
      std::swap(buffer, buffer2);
      buffer2.clear();
    }
    return 0;
  }

 private:
  bool ValidTransformation(const string &beginWord, const string &endWord) {
    bool only_one_difference = false;
    for (size_t i = 0; i < beginWord.size(); ++i)
      if (beginWord[i] != endWord[i])
        if (only_one_difference)
          return false;
        else
          only_one_difference = true;
    return only_one_difference;
  }
};

int main(void) {
	Solution sln;
	// auto rtn = sln.findLadders("hit", "cog", { "hot","dot","dog","lot","log","cog" });
	// rtn = sln.findLadders("qa", "sq", { "si","go","se","cm","so","ph","mt","db","mb","sb","kr","ln","tm","le","av","sm","ar","ci","ca","br","ti","ba","to","ra","fa","yo","ow","sn","ya","cr","po","fe","ho","ma","re","or","rn","au","ur","rh","sr","tc","lt","lo","as","fr","nb","yb","if","pb","ge","th","pm","rb","sh","co","ga","li","ha","hz","no","bi","di","hi","qa","pi","os","uh","wm","an","me","mo","na","la","st","er","sc","ne","mn","mi","am","ex","pt","io","be","fm","ta","tb","ni","mr","pa","he","lr","sq","ye" });
	
	int rtn2 = sln.ladderLength("hit", "cog", { "hot","dot","dog","lot","log","cog" });
	rtn2 = sln.ladderLength("qa", "sq", { "si","go","se","cm","so","ph","mt","db","mb","sb","kr","ln","tm","le","av","sm","ar","ci","ca","br","ti","ba","to","ra","fa","yo","ow","sn","ya","cr","po","fe","ho","ma","re","or","rn","au","ur","rh","sr","tc","lt","lo","as","fr","nb","yb","if","pb","ge","th","pm","rb","sh","co","ga","li","ha","hz","no","bi","di","hi","qa","pi","os","uh","wm","an","me","mo","na","la","st","er","sc","ne","mn","mi","am","ex","pt","io","be","fm","ta","tb","ni","mr","pa","he","lr","sq","ye" });
	return 0;
}
