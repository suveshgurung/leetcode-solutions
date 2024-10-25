#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

int removeDuplicates(vector<int>& nums) {
  int currValue = nums.at(0), k = 1, i;

  for (i = 1; i < nums.size(); ++i) {
    if (nums.at(i) == currValue) {
      nums.at(i) = 101;
    } else {
      currValue = nums.at(i);
      k++;
    }
  }

  unordered_map<int, int> counts;
  int index = 0;

  for (int n : nums) {
    counts[n]++;
  }

  for (int n : nums) {
    if (counts[n] == 1 && n != 101) {
      nums[index] = n;
      index++;
    }
  }

  for (const auto &entry : counts) {
    if (entry.first == 101) {
      for (i = 0; i < entry.second; ++i) {
        nums[index] = entry.first;
        index++;
      }
    }
  }

  return k;
}

int main() {
  vector<int> nums({1,1,2});

  int k = removeDuplicates(nums);

  cout << k << endl;
  for (int i = 0; i < nums.size(); ++i) {
    cout << nums.at(i) << " ";
  }
  cout << endl;

  return 0;
}
