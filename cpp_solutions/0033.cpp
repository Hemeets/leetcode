/*
 * @Author: QDX
 * @Date: 2023-01-28 11:48:01
 * @Description: 
 */
#include "utils.h"

class Solution {

  public:
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        if (!n) {
            return -1;
        }
        int l = 0, r = n - 1;
        while (l <= r) {
            int m = (l + r) / 2;
            if (nums[m] == target) {
                return m;
            }
            if (nums[l] <= nums[m]) {
                if (nums[l] <= target && target < nums[m]) {
                    r = m - 1;
                } else {
                    l = m + 1;
                }
            } else {
                if (nums[m] < target && target <= nums[r]) {
                    l = m + 1;
                } else {
                    r = m - 1;
                }
            }
        }
        return -1;
    }
};


int main() {
    vector<int> nums = {4,5,6,7,0,1,2};
    int target = 0;
    auto ans = Solution().search(nums, target);
    cout << ans << endl;
}