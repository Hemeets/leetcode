/*
 * @Author: QDX
 * @Date: 2023-01-28 10:40:14
 * @Description: 
 */
#include "utils.h"


class Solution1 {

  public:
    vector<int> singleNumber(vector<int>& nums) {
        unordered_map<int, int> freq;
        for (int num: nums) {
            ++freq[num];
        }
        vector<int> ans;
        for (auto it = freq.begin(); it != freq.end(); it++) {
            if (it->second == 1) {
                ans.push_back(it->first);
            }
        }
        return ans;
    }
};


class Solution {
  public:
    vector<int> singleNumber(vector<int>& nums) {
        int xor_num = 0;
        for (int num: nums) {
            xor_num ^= num;
        }
        int bit = 1;
        while (!(bit & xor_num)) {
            bit = bit << 1;
        }
        int a = 0, b = 0;
        for (int num: nums) {
            if (!(num & bit)) {
                a ^= num;
            } else {
                b ^= num;
            }
        }
        return {a, b};
    }
};



int main() {
    vector<int> nums = {1,2,1,3,2,5};
    // auto ans = Solution1().singleNumber(nums);
    auto ans = Solution().singleNumber(nums);
    printVector(ans);
}