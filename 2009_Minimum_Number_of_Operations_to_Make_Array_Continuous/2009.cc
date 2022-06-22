
#include <assert.h>

#include <algorithm>
#include <chrono>
#include <iostream>
#include <vector>

using std::vector;

// beats 60%.
class Solution_beats_60_per_cent {
 public:
  int minOperations(vector<int>& nums) {
    const int nums_size = nums.size();
    std::sort(nums.begin(), nums.end());
    vector<int> dup_count(nums_size, 0);
    for (int i = 1; i < nums_size; ++i) {
      dup_count[i] = dup_count[i - 1];
      if (nums[i - 1] == nums[i])
        ++dup_count[i];
    }
    int max_window = 0;
    for (int i = 0, r_index = 0, left_dup_count = 0, right_dup_count = 0; i < nums_size; ++i) {
      while (r_index + 1 < nums_size && nums[r_index + 1] < nums[i] + nums_size) ++r_index;
      max_window = std::max(max_window, (r_index - i) - (dup_count[r_index] - dup_count[i]));
    }
    return nums_size - max_window - 1;
  }
};

// beats 75%.
class Solution {
 public:
  int minOperations(vector<int>& nums) {
    const int nums_size = nums.size();
    std::sort(nums.begin(), nums.end());
    int max_window = 0;
    for (int i = 0, r_index = 0, left_dup_count = 0, right_dup_count = 0; i < nums_size; ++i) {
      if (0 < i && nums[i - 1] == nums[i]) ++left_dup_count;
      while (r_index + 1 < nums_size && nums[r_index + 1] < nums[i] + nums_size) {
        ++r_index;
        if (nums[r_index] == nums[r_index - 1]) ++right_dup_count;
      }
      max_window = std::max(max_window, (r_index - i) - (right_dup_count - left_dup_count));
    }
    return nums_size - max_window - 1;
  }
};

int main(void) {
  Solution sln;
  vector<int> test_vec = {4, 2, 5, 3};
  int rtn = sln.minOperations(test_vec);
  assert(rtn == 0);
  test_vec = {1, 2, 3, 5, 6};
  rtn = sln.minOperations(test_vec);
  assert(rtn == 1);
  test_vec = {8, 5, 9, 9, 8, 4};
  rtn = sln.minOperations(test_vec);
  assert(rtn == 2);
  test_vec = {10, 49, 16, 22, 28, 34, 35, 7};
  rtn = sln.minOperations(test_vec);
  assert(rtn == 5);
  test_vec = {4804, 4767, 4609, 4703, 4684, 4647, 5047, 4794, 4626, 4868, 4966, 4619, 4715, 4951, 5026, 4690, 4923, 5025, 4689, 5013, 4656, 4694, 4863, 5056, 4807, 4996, 4772, 4834, 4733, 4838, 4741, 4730, 4613, 4675, 4841, 4917, 4745, 5047, 4584, 4669, 4577, 4589, 4755, 4770, 4788, 4933, 5012, 4813, 4907, 4623, 4686, 4887, 4804, 4752, 4740, 4636, 4648, 4680, 4951, 4917, 4878, 4759, 4754, 4821, 4587, 4882, 4928, 4690, 4938, 4877, 4855, 4720, 4966, 4631, 4670, 4918, 4764, 4814, 4637, 4831, 4810, 4988, 5011, 4908, 4800, 4961, 4920, 5083, 4980, 4834, 5027, 4906, 4721, 4566, 4812, 4839, 4970, 4725, 5021, 4676, 4918, 4773, 4894, 4599, 4707, 4961, 4964, 4820, 4905, 4768, 4892, 4834, 4756, 4751, 4623, 5042, 4782, 4655, 5030, 4815, 4631, 5066, 5048, 5060, 4976, 4814, 4786, 4600, 4693, 4870, 4945, 4962, 5069, 4782, 4670, 4855, 4975, 4793, 4773, 4725, 4969, 5061, 5002, 4924, 4888, 4571, 4851, 5057, 4907, 4964, 4764, 5063, 5049, 4784, 5048, 4760, 4914, 4874, 4572, 5070, 4816, 4715, 4597, 4986, 4577, 4940, 4891, 4570, 5046, 5064, 4959, 4875, 4736, 4817, 4751, 4815, 4703, 4659, 4643, 4592, 4857, 4627, 4615, 5062, 5071, 5063, 4894, 4961, 4999, 4914, 5018, 4762, 4599, 4942, 4839, 4871, 4995, 4923, 4989, 4849, 4904, 4786, 4977, 4944, 4866, 4818, 5032, 4619, 5047, 4999, 4613, 4671, 4969, 4576, 4964, 4843, 4841, 4589, 4928, 4660, 4580, 4716, 4639, 4898, 4834, 4878, 4964, 4759, 4915, 5039, 4857, 4580, 4843, 4985, 5021, 4842, 4949, 4614, 4718, 4703, 4598, 4792, 4813, 4830, 4611, 4807, 4943, 4853, 4796, 4788, 4758, 4747, 4569, 4978, 5044, 4642, 5008, 4936, 4970, 4643, 4975, 4989, 4575, 4620, 4856, 4826, 4803, 4646, 4942, 4781, 4694, 4761, 4832, 4871, 4917, 4879, 5024, 4779, 4651, 4818, 4890, 4942, 4616, 4984, 4985, 4595, 4723, 4639, 5001, 4642, 4770, 4992, 4571, 5005, 4789, 4590, 4982, 5012, 4774, 5019, 4933, 4574, 4812, 4904, 4973, 4752, 4656, 4901, 4713, 5002, 4563, 5039, 5037, 4979, 4788, 5021, 4636, 5075, 4663, 4845, 4726, 5032, 4625, 4750, 4727, 4864, 4782, 4638, 4959, 5064, 5039, 4839, 4685, 4745, 4822, 5010, 5000, 4946, 4904, 4577, 4660, 5060, 4969, 4948, 4977, 4895, 4886, 5051, 4770, 4727, 4752, 4903, 4746, 4872, 4591, 4745, 4933, 4706, 4694, 4849, 5007, 4761, 4900, 4656, 4718, 4803, 4685, 4774, 4609, 4944, 4702, 4946, 4996, 4680, 4720, 5014, 4715, 4874, 4580, 4633, 4955, 4577, 5024, 4576, 4616, 4729, 4563, 4965, 4854, 5037, 4774, 4785, 4988, 4979, 4680, 4856, 4803, 5014, 4888, 5003, 4737, 4741, 4573, 4985, 4931, 4657, 4835, 4601, 5058, 4864, 4717, 4959, 4615, 5079, 4720, 4823, 4842, 4833, 4616, 4623, 4817, 4565, 5036, 4857, 4789, 5070, 4646, 4916, 4978, 4829, 4589, 4838, 4769, 4865, 5054, 4939, 4903, 4980, 4668, 4629, 4937, 5068, 4837, 4698, 5084, 4772, 4839, 4931, 4574, 5035, 4724, 4777, 4873, 4900, 5054, 4727, 4921, 4756, 4846, 4759, 4861, 5070, 5062, 5001, 4609, 5006, 4875, 4766, 4864, 5083, 5005, 4580, 4868, 5015, 4687, 4897, 4988, 4649, 5017, 4769, 4751, 4857, 4824, 4916, 4875, 4580, 4648, 5040, 4704, 4585, 4907, 4983, 4954, 5022, 4679, 4890, 4990, 4806, 4869};
  rtn = sln.minOperations(test_vec);
  assert(rtn == 190);

  auto start = std::chrono::system_clock::now();
  FILE* fp = fopen("testcase.txt", "rb");
  char* buf = new char[2 * 1024 * 1024];
  const size_t read_size = fread(buf, 1, 2 * 1024 * 1024, fp);
  assert(read_size < 2 * 1024 * 1024);
  for (size_t i = 1; i <= read_size; ++i)
    if ((!('0' <= buf[i - 1] && buf[i - 1] <= '9')) && ('0' <= buf[i] && buf[i] <= '9')) test_vec.push_back(atoi(buf + i));
  fclose(fp);
  delete[] buf;
  std::cout << "time to prepare data: " << std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now() - start).count() << " milliseconds" << std::endl;
  start = std::chrono::system_clock::now();
  rtn = sln.minOperations(test_vec);
  std::cout << "time to calculate: " << std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now() - start).count() << " milliseconds" << std::endl;
  assert(rtn == 100167);

  return 0;
}