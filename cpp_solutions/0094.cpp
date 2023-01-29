/*
 * @Author: QDX
 * @Date: 2023-01-28 17:48:45
 * @Description: 
 */
#include "utils.h"

class Solution {
  public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> res;
        inorder(root, res);
        return res;
    }

    void inorder(TreeNode* root, vector<int>& res) {
        if (!root) return ;
        inorder(root->left, res);
        res.push_back(root->val);
        inorder(root->right, res);
    }
};

/* 迭代 */
class Solution1 {
  public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> res;
        stack<TreeNode*> stk;
        while (!stk.empty() || root != nullptr) {
            while (root != nullptr) {
                stk.push(root);
                root = root->left;
            }
            root = stk.top();
            stk.pop();
            res.push_back(root->val);
            root = root->right;
        }
        return res;
    }
};


int main() {
    vector<int> root_v = {3,9,20,EmptyTN,EmptyTN,15,7};
    TreeNode* root = V2TN(root_v);
    // auto ans = Solution().inorderTraversal(root);
    auto ans = Solution1().inorderTraversal(root);
    printVector(ans);
}
