/*
 * @Author: QDX
 * @Date: 2023-01-28 09:50:49
 * @Description: 
 */
#include "utils.h"


class Solution {

  public:

    void backtrack(vector<int>& candidates, int& target, int idx, int cur_cand_sum) {
        if (cur_cand_sum > target) {
            return ;
        }
        if (cur_cand_sum == target) {
            res.push_back(tmp_cand);
            return ;
        }
        for (int j = idx; j < candidates.size(); j++) {
            int tmp_sum = cur_cand_sum + candidates[j];
            if (tmp_sum > target)
                break;
            if (j > idx && candidates[j-1] == candidates[j])
                continue;
            tmp_cand.push_back(candidates[j]);
            backtrack(candidates, target, j + 1, tmp_sum);
            tmp_cand.pop_back();
        }
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        backtrack(candidates, target, 0, 0);
        return res;
    }

  public:
    vector<vector<int>> res;
    vector<int> tmp_cand;

};


int main() {

    vector<int> candidates = {10,1,2,7,6,1,5};
    int target = 8;
    auto res = Solution().combinationSum2(candidates, target);
    for (auto it = res.begin(); it != res.end(); it++) {
        printVector(*it);
    }
    return 0;
}