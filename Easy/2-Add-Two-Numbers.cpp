#include <algorithm>
#include <iostream>
#include <vector>

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
    public:
        ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
            if (l1 == nullptr && l2 == nullptr) {
                return nullptr;
            }
            if (l1 == nullptr) {
                return l2;
            }
            if (l2 == nullptr) {
                return l1;
            }

            ListNode *current = l1;
            std::vector<int> arr_1, arr_2;

            // populate the linked list into an array.
            while (current != nullptr) {
                arr_1.push_back(current->val);
                current = current->next;
            }

            current = l2;
            while (current != nullptr) {
                arr_2.push_back(current->val);
                current = current->next;
            }

            int i = 0, j = 0, carry = 0;
            std::vector<int> sum_digit_arr;
            while (i < arr_1.size() || j < arr_2.size() || carry > 0) {
                int digit_sum = carry;

                if (i < arr_1.size()) {
                    digit_sum += arr_1[i++];
                }
                if (j < arr_2.size()) {
                    digit_sum += arr_2[j++];
                }

                sum_digit_arr.push_back(digit_sum % 10);

                if (std::min(digit_sum, 10) == 10 || digit_sum == 10) {
                    if (digit_sum != 10) {
                        digit_sum /= 10;
                        carry = digit_sum % 10;
                    }
                    else {
                        carry = 1;
                    }
                }
                else {
                    carry = 0;
                }
            }

            ListNode *prev_digit = nullptr;
            for (int i = sum_digit_arr.size() - 1; i >= 0; i--) {
                ListNode *digit = new ListNode(sum_digit_arr[i]);
                if (prev_digit != nullptr) {
                    digit->next = prev_digit;
                }
                prev_digit = digit;
            }

            return prev_digit;
        }
};

int main() {
    // 1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1
    Solution solution;
    ListNode l1[31];
    l1[0].val = 1;
    for (int i = 1; i < 31; i++) {
        if (i != 30) {
            l1[i].val = 0;
        }
        else {
            l1[i].val = 1;
        }
        l1[i - 1].next = &(l1[i]);
    }
    ListNode l2_3(3);
    ListNode l2_2(4, &l2_3);
    ListNode l2_1(2, &l2_2);

    ListNode *answer = solution.addTwoNumbers(&l1[0], &l2_1);
    ListNode *current = answer;
    while (current != nullptr) {
        std::cout << current->val << " ";
        current = current->next;
    }

    return 0;
}
