
class Solution {
 public:
  int bitwiseComplement(int N) {
    if (N == 0) return 1;
    unsigned int mask = 0xffffffff;
    int backup = N;
    while (backup != 0) {
      backup = backup >> 1;
      mask = mask << 1;
    }
    return mask ^ (~N);
  }
};

int main(void) {
  Solution sln;
  int rtn = sln.bitwiseComplement(5);
  rtn = sln.bitwiseComplement(7);
  rtn = sln.bitwiseComplement(10);
  return 0;
}
