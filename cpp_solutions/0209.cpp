/*
 * @Author: QDX
 * @Date: 2023-01-28 15:55:03
 * @Description: 
 */
#include "utils.h"


class Solution {
  public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int n = nums.size();
        int min_len = n + 1;
        int sum_n = 0, left = 0;
        for (int i = 0; i < n; i++) {
            sum_n += nums[i];
            while (sum_n >= target) {
                min_len = min(min_len, i - left + 1);
                sum_n -= nums[left];
                left += 1;
            }
        }
        return min_len < n + 1 ? min_len : 0;
    }
};


int main() {
    int target = 7;
    vector<int> nums = {2,3,1,2,4,3};
    auto ans = Solution().minSubArrayLen(target, nums);
    cout << ans << endl;
}