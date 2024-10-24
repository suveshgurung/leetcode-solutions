#include <iostream>
#include <string>
#include <vector>

using namespace std;

bool isValid(string s) {
  if (s.size() == 0) {
    return false;
  }

  vector<char> prev;
  int bracketCount = s.length();

  if (s[0] == '(' || s[0] == '{' || s[0] == '[') {
  } else {
    return false;
  }

  for (int i = 0; i < s.length(); i++) {
    if (s[i] == '(') {
      bracketCount--;
      prev.push_back(s[i]);
    }
    if (s[i] == '{') {
      bracketCount--;
      prev.push_back(s[i]);
    }
    if (s[i] == '[') {
      bracketCount--;
      prev.push_back(s[i]);
    }
    if (s[i] == ')') {
      if (prev.size() != 0) {
        if (prev.back() == '(') {
          bracketCount--;  
          prev.pop_back();
        } else {
          return false;
        }
      }
    }
    if (s[i] == '}') {
      if (prev.size() != 0) {
        if (prev.back() == '{') {
          bracketCount--;  
          prev.pop_back();
        } else {
          return false;
        }
      }
    }
    if (s[i] == ']') {
      if (prev.size() != 0) {
        if (prev.back() == '[') {
          bracketCount--;  
          prev.pop_back();
        } else {
          return false;
        }
      }
    }
  }

  if (bracketCount == 0 && prev.empty()) {
    return true;
  } else {
    return false;
  }
}

int main() {
  string s = "[";

  cout << isValid(s);
  
  return 0;
}
