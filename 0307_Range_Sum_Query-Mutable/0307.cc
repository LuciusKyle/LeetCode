
#define _CRT_SECURE_NO_WARNINGS

#include <assert.h>
#include <limits.h>
#include <rapidjson/document.h>
#include <rapidjson/filereadstream.h>
#include <rapidjson/pointer.h>
#include <rapidjson/rapidjson.h>
#include <rapidjson/reader.h>
#include <rapidjson/writer.h>

#include <algorithm>
#include <chrono>
#include <iostream>
#include <random>
#include <vector>

using std::cout;
using std::endl;
using std::vector;

constexpr int kLevel[] = {0, 1 << 0, 1 << 1, 1 << 2, 1 << 3, 1 << 4, 1 << 5, 1 << 6, 1 << 7, 1 << 8, 1 << 9, 1 << 10, 1 << 11, 1 << 12, 1 << 13, 1 << 14, 1 << 15, 1 << 16, 1 << 17, 1 << 18, 1 << 19, 1 << 20, 1 << 21, 1 << 22, 1 << 23, 1 << 24, 1 << 25, 1 << 26, 1 << 27, 1 << 28, 1 << 29, 1 << 30};

class NumArray {
 public:
  NumArray(const vector<int> nums) : level_(0) {
    while (kLevel[level_] < nums.size()) ++level_;
    ++level_;
    seg_tree_.resize(kLevel[level_]);
    if (seg_tree_.size() < 3) seg_tree_.push_back(0);
    // kLevel[level_]: total number of seg_tree_
    // seg_tree_[kLevel[level_]]: invalid call;
    // seg_tree_[kLevel[level_ - 1]]: first elemet of nums array;
    for (int i = 0; i < nums.size(); ++i) {
      seg_tree_[kLevel[level_ - 1] + i] = nums[i];
    }
    int curr_level = level_;
    while (2 < curr_level) {
      for (int i = kLevel[curr_level - 1]; i < kLevel[curr_level]; i += 2) {
        seg_tree_[i / 2] = seg_tree_[i] + seg_tree_[i + 1];
      }
      --curr_level;
    }
  }

  void update(int index, const int val) {
    const int diff = val - seg_tree_[kLevel[level_ - 1] + index];
    for (int l = level_; 1 < l; --l) {
      seg_tree_[kLevel[l - 1] + index] += diff;
      index /= 2;
    }
  }

  int sumRange(int left, int right) {
    if (left == right) return seg_tree_[kLevel[level_ - 1] + left];
    int answer = 0, curr_level = level_ - 1;
    while (left + 1 < right) {
      if (left % 2) {
        answer += seg_tree_[kLevel[curr_level] + left];
        ++left;
      }
      if ((right + 1) % 2) {
        answer += seg_tree_[kLevel[curr_level] + right];
        --right;
      }
      --curr_level;
      left /= 2;
      right /= 2;
    }
    if (left == right) return answer + seg_tree_[kLevel[curr_level] + left];
    return answer + seg_tree_[kLevel[curr_level] + left] + seg_tree_[kLevel[curr_level] + right];
  }

 private:
  vector<int> seg_tree_;
  int level_;
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */

class NumArray_correct {
 public:
  NumArray_correct(const vector<int> nums) : sums_cache_(nums), nums_(nums) {
    for (size_t i = 1; i < nums.size(); ++i)
      sums_cache_[i] += sums_cache_[i - 1];
  }

  void update(int i, int val) {
    const int var = val - nums_[i];
    nums_[i] = val;
    std::transform(sums_cache_.cbegin() + i, sums_cache_.cend(), sums_cache_.begin() + i, [var](const int sum) -> int { return sum + var; });
  }

  int sumRange(const int begin, const int end) {
    if (begin)
      return sums_cache_[end] - sums_cache_[begin - 1];
    else
      return sums_cache_[end];
  }

 private:
  vector<int> sums_cache_;
  vector<int> nums_;
};

constexpr size_t kBufSize = 2 * 1024 * 1024;

int main(int argc, char* argv[]) {
  // NumArray arr(vector<int>{1, 3, 5});
  // assert(9 == arr.sumRange(0, 2));
  // assert(4 == arr.sumRange(0, 1));
  // assert(8 == arr.sumRange(1, 2));
  // return 0;

  auto start = std::chrono::system_clock::now();
  char* buf = new char[kBufSize];
  for (int i = 1; i < argc; ++i) {
    start = std::chrono::system_clock::now();
    FILE* fp = fopen(argv[i], "rb");
    if (fp == nullptr) continue;
    memset(buf, 0, kBufSize);
    const int file_size = fread(buf, 1, kBufSize, fp);
    fclose(fp);
    int new_line = 0;
    while (buf[new_line] != '\n') {
      ++new_line;
    }
    rapidjson::Document d;
    d.Parse(buf, new_line);
    vector<int> operation_vec;
    for (rapidjson::SizeType i = 0; i != d.Size(); ++i) {
      if (0 == strcmp("NumArray", d[i].GetString())) {
        operation_vec.push_back(0);
      }
      if (0 == strcmp("update", d[i].GetString())) {
        operation_vec.push_back(1);
      }
      if (0 == strcmp("sumRange", d[i].GetString())) {
        operation_vec.push_back(2);
      }
    }
    vector<vector<int>> parameter_vec(operation_vec.size());
    d.Parse(buf + new_line + 1);
    for (rapidjson::SizeType i = 0; i != d.Size(); ++i) {
      switch (operation_vec[i]) {
        case 0: {
          rapidjson::Value& v_l1 = d[i];
          rapidjson::Value& v_l2 = v_l1[0];
          for (rapidjson::SizeType j = 0; j != v_l2.Size(); ++j) {
            parameter_vec[i].push_back(v_l2[j].GetInt());
          }
        } break;
        case 1:
        case 2:
          for (rapidjson::SizeType j = 0; j != d[i].Size(); ++j) {
            parameter_vec[i].push_back(d[i][j].GetInt());
          }
          break;
        default:
          abort();
          break;
      }
    }
    cout << "prepare data: " << std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now() - start).count() << " milliseconds\n";
    start = std::chrono::system_clock::now();
    NumArray test_num_arr(parameter_vec[0]);
    for (int i = 1; i < operation_vec.size(); ++i) {
      switch (operation_vec[i]) {
        case 1:
          test_num_arr.update(parameter_vec[i][0], parameter_vec[i][1]);
          break;
        case 2:
          test_num_arr.sumRange(parameter_vec[i][0], parameter_vec[i][1]);
          break;
        default:
          break;
      }
    }
    cout << "run solution: " << std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now() - start).count() << " milliseconds\n";
  }
  delete[] buf;
  cout << "time: " << std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now() - start).count() << " milliseconds\nstart validation!\n";

  std::random_device rd;
  std::default_random_engine re(rd());
  std::uniform_int_distribution value_dist(-3000, 3001);
  std::uniform_real_distribution<double> operation_dist(-1.0, 1.0);
  std::uniform_int_distribution index_dist(0, 30000 - 1);
  vector<int> test_vec;
  test_vec.reserve(30000);
  for (int i = 0; i < 30000; ++i) {
    test_vec.push_back(value_dist(re));
  }
  NumArray my_arr(test_vec);
  NumArray_correct corr_arr(test_vec);
  for (int i = 0; i < 10000000; ++i) {
    if (0 < operation_dist(re)) {
      const int index = index_dist(re);
      const int value = value_dist(re);
      my_arr.update(index, value);
      corr_arr.update(index, value);
    } else {
      const int index1 = index_dist(re);
      const int index2 = index_dist(re);
      const int& left = index1 < index2 ? index1 : index2;
      const int& right = index1 < index2 ? index2 : index1;
      const int my_result = my_arr.sumRange(left, right);
      const int corr_result = corr_arr.sumRange(left, right);
      if (my_result != corr_result) {
        cout << "wrong answer!" << endl;
        abort();
      }
    }
  }
  return 0;
}