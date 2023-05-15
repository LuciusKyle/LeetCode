
#include <queue>
#include <set>
#include <vector>

using std::pair;
using std::vector;

class MyComparator {
 public:
  bool operator()(const std::pair<int, int>& _x, const std::pair<int, int>& _y) {
    return _x.first + _x.second < _y.first + _y.second;
  }
};

class Solution_01 {
  struct Node {
    int v1, v2;
    int i1, i2;
    bool operator<(const Node& other) const {
      return v1 + v2 > other.v1 + other.v2;
    }
  };

 public:
  vector<vector<int>> kSmallestPairs(const vector<int>& nums1, const vector<int>& nums2, int k) {
    vector<vector<int>> answer;
    answer.reserve(k);
    std::priority_queue<Node> min_heap;
    for (int i = 0; i < nums1.size() && i < k; ++i) {
      Node node;
      node.i1 = i;
      node.i2 = 0;
      node.v1 = nums1[i];
      node.v2 = nums2[0];
      min_heap.push(node);
    }
    while (k != 0 && !min_heap.empty()) {
      --k;
      Node top_node = min_heap.top();
      min_heap.pop();
      answer.push_back({top_node.v1, top_node.v2});
      if (top_node.i2 + 1 < nums2.size()) {
        top_node.i2++;
        top_node.v2 = nums2[top_node.i2];
        min_heap.push(top_node);
      }
    }
    return answer;
  }
};

// official solution :
class Solution_CHN {
 public:
  vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
    int m = nums1.size();
    int n = nums2.size();
    auto count = [&](int target) {
      long long cnt = 0;
      int start = 0;
      int end = n - 1;
      while (start < m && end >= 0) {
        if (nums1[start] + nums2[end] > target) {
          end--;
        } else {
          cnt += end + 1;
          start++;
        }
      }
      return cnt;
    };

    /*二分查找第 k 小的数对和的大小*/
    int left = nums1[0] + nums2[0];
    int right = nums1.back() + nums2.back();
    int pairSum = right;
    while (left <= right) {
      int mid = left + ((right - left) >> 1);
      if (count(mid) < k) {
        left = mid + 1;
      } else {
        pairSum = mid;
        right = mid - 1;
      }
    }

    vector<vector<int>> ans;
    int pos = n - 1;
    /*找到小于目标值 pairSum 的数对*/
    for (int i = 0; i < m; i++) {
      while (pos >= 0 && nums1[i] + nums2[pos] >= pairSum) {
        pos--;
      }
      for (int j = 0; j <= pos && k > 0; j++, k--) {
        ans.push_back({nums1[i], nums2[j]});
      }
    }
    /*找到等于目标值 pairSum 的数对*/
    pos = n - 1;
    for (int i = 0; i < m && k > 0; i++) {
      int start1 = i;
      while (i < m - 1 && nums1[i] == nums1[i + 1]) {
        i++;
      }
      while (pos >= 0 && nums1[i] + nums2[pos] > pairSum) {
        pos--;
      }
      int start2 = pos;
      while (pos > 0 && nums2[pos] == nums2[pos - 1]) {
        pos--;
      }
      if (nums1[i] + nums2[pos] != pairSum) {
        continue;
      }
      int count = (int)min((long)k, (long)(i - start1 + 1) * (start2 - pos + 1));
      for (int j = 0; j < count && k > 0; j++, k--) {
        ans.push_back({nums1[i], nums2[pos]});
      }
    }
    return ans;
  }

  long min(long num1, long num2) {
    return num1 <= num2 ? num1 : num2;
  }
};

// official solution:
class Solution_ENG {
 public:
  vector<vector<int>> kSmallestPairs(const vector<int>& nums1, const vector<int>& nums2, int k) {
    int m = nums1.size();
    int n = nums2.size();

    vector<vector<int>> ans;
    std::set<pair<int, int>> visited;

    std::priority_queue<pair<int, std::pair<int, int>>, vector<pair<int, pair<int, int>>>,
                        std::greater<pair<int, pair<int, int>>>>
        minHeap;
    minHeap.push({nums1[0] + nums2[0], {0, 0}});
    visited.insert({0, 0});

    while (k-- && !minHeap.empty()) {
      auto top = minHeap.top();
      minHeap.pop();
      int i = top.second.first;
      int j = top.second.second;

      ans.push_back({nums1[i], nums2[j]});

      if (i + 1 < m && visited.find({i + 1, j}) == visited.end()) {
        minHeap.push({nums1[i + 1] + nums2[j], {i + 1, j}});
        visited.insert({i + 1, j});
      }

      if (j + 1 < n && visited.find({i, j + 1}) == visited.end()) {
        minHeap.push({nums1[i] + nums2[j + 1], {i, j + 1}});
        visited.insert({i, j + 1});
      }
    }

    return ans;
  }
};

class Solution {
  struct Node {
    int v1, v2;
    int i1, i2;
    bool operator<(const Node& other) const {
      return v1 + v2 > other.v1 + other.v2;
    }
  };

 public:
  vector<vector<int>> kSmallestPairs(const vector<int>& nums1, const vector<int>& nums2, int k) {
    vector<vector<int>> answer;
    answer.reserve(k);
    std::priority_queue<Node> min_heap;
    for (int i = 0; i < nums1.size() && i < k; ++i) {
      Node node;
      node.i1 = i;
      node.i2 = 0;
      node.v1 = nums1[i];
      node.v2 = nums2[0];
      min_heap.push(node);
    }
    while (k != 0 && !min_heap.empty()) {
      --k;
      Node top_node = min_heap.top();
      min_heap.pop();
      answer.push_back({top_node.v1, top_node.v2});
      if (top_node.i2 + 1 < nums2.size()) {
        top_node.i2++;
        top_node.v2 = nums2[top_node.i2];
        min_heap.push(top_node);
      }
    }
    return answer;
  }
};

int main(int argc, char* argv[]) {
  Solution sln;
  sln.kSmallestPairs({1, 2, 4, 5, 6}, {3, 5, 7, 9}, 3);
  sln.kSmallestPairs({1, 1, 2}, {1, 2, 3}, 10);
  sln.kSmallestPairs({1, 7, 11}, {2, 4, 6}, 3);
  sln.kSmallestPairs({1, 1, 2}, {1, 2, 3}, 2);
  sln.kSmallestPairs({1, 2}, {3}, 3);
  return 0;
}
