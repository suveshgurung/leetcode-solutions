#include <iostream>
#include <vector>

class Solution {
public:
    int removeElement(std::vector<int>& nums, int val) {
        if (nums.size() == 0) {
            return 0;
        }

        std::vector<int> arr;

        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] != val) {
                arr.push_back(nums[i]);
            }
        }

        if (arr.size() == 0) {
            for (int j = 0; j < nums.size(); j++) {
                nums[j] = val - 1;
            }
            return 0;
        }

        for (int i = 0; i < arr.size(); i++) {
            nums[i] = arr[i];
        }

        return arr.size();
    }
};

int main() {
    std::vector<int> nums = {0,1,2,2,3,0,4,2};
    int val = 2;
    Solution solution;

    std::cout << solution.removeElement(nums, val) << std::endl;
    for (int i = 0; i < nums.size(); i++) {
        std::cout << nums[i] << " ";
    }
    std::cout << std::endl;

    return 0;
}
