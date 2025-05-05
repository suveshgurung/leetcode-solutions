#include <algorithm>
#include <iostream>
#include <vector>

class Solution {
  public:
    std::string longestCommonPrefix(std::vector<std::string>& strs) {
      if (strs.size() == 0) {
        return "";
      }
      if (strs.size() == 1 && strs[0].size() == 0) {
        return "";
      }
      if (strs.size() == 1 && strs[0].size() != 0) {
        return strs[0];
      }
      std::vector<std::string> prefix_array = strs;

      do {
        for (int i = 0; i <= prefix_array.size() - 2; i++) {
          std::string longest_prefix = "";
          for (int j = 0; j < std::min(prefix_array[i].size(), prefix_array[i + 1].size()); j++) {
            if (longest_prefix.length() == j) {
              if (prefix_array[i][j] == prefix_array[i + 1][j]) {
                longest_prefix += prefix_array[i][j];
              }
            }
          }

          prefix_array.erase(prefix_array.begin() + i);
          prefix_array.insert(prefix_array.begin() + i, longest_prefix);
        }

        prefix_array.erase(prefix_array.end());
      } while (prefix_array.size() != 1);

      // no longest common prefix.
      if (prefix_array.size() == 0) {
        return "";
      }
      else {
        return prefix_array.at(0);
      }
    }
};

int main() {
  std::vector<std::string> strs = {"cir", "car"};
  Solution solution;

  std::cout << solution.longestCommonPrefix(strs) << std::endl;

  return 0;
}
