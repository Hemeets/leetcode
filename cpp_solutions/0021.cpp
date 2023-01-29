/*
 * @Author: QDX
 * @Date: 2023-01-28 16:01:33
 * @Description: 
 */
#include "utils.h"

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* prehead = new ListNode(-1);
        ListNode* prev = prehead;
        while (list1 != nullptr && list2 != nullptr) {
            if (list1->val < list2->val) {
                prev->next = list1;
                list1 = list1->next;
            } else {
                prev->next = list2;
                list2 = list2->next;
            }
            prev = prev->next;
        }
        prev->next = list1 == nullptr ? list2 : list1;
        return prehead->next;
    }
};



int main() {
    vector<int> n1 = {1,2,4};
    ListNode* l1 = V2LN(n1);
    vector<int> n2 = {1,3,4};
    ListNode* l2 = V2LN(n2);
    ListNode* ans = Solution().mergeTwoLists(l1, l2);
    auto res = LN2V(ans);
    printVector(res);
}