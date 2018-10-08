

class Solution {
 public:
  int trailingZeroes(int n) {
    return n != 0 ? (n / 5 + trailingZeroes(n / 5)) : 0;
  }
};

int main(void)
{
  Solution sln;
  int rtn = sln.trailingZeroes(13);

  return 0;
}
