/*
 * @Author: QDX
 * @Date: 2023-01-11 22:24:53
 * @Description: 
 */
#include "utils.h"


class Solution {
  public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> hashtable;
        for (int i = 0; i < nums.size(); ++i) {
            auto it = hashtable.find(target - nums[i]);
            if (it != hashtable.end()) {
                return {it->second, i};
            }
            hashtable[nums[i]] = i;
        }
        return {};
    }
    
};


int main() {
    vector<int> nums = {2,7,11,15};
    int target = 9;
    auto res = Solution().twoSum(nums, target);
    printVector(res);
    return 0;
}

