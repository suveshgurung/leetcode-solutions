#include <iostream>
#include <string>
#include <vector>
#include <bits/stdc++.h>

std::string longestCommonPrefix(std::vector<std::string>& strs) {
  // std::vector<std::vector<char>> separatedWord;
  // std::vector<char> letters;
  // int i, j;
  //
  // for (i = 0; i < strs.size(); ++i) {
  //   for (j = 0; j < strs.at(i).size(); ++j) {
  //     letters.push_back(strs.at(i)[j]);
  //   }
  //   separatedWord.push_back(letters);
  //   letters.clear();
  // }
  // for (i = 0; i < separatedWord.size(); ++i) {
  //   for (j = 0; j < separatedWord.at(i).size(); ++j) {
  //     std::cout << separatedWord.at(i)[j];
  //   }
  // }

  std::sort(strs.begin(), strs.end());

  return "";
}

int main() {
  std::vector<std::string> strs({"flower","flow","flight"});

  longestCommonPrefix(strs);

  for (int i = 0; i < strs.size(); i++) {
    std::cout << strs.at(i) << " ";
  }
  
  return 0;
}
