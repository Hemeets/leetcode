/*
 * @Author: QDX
 * @Date: 2023-01-11 23:03:31
 * @Description: 
 */
#include "utils.h"



void printVector(vector<int>& v) {
	for (vector<int>::iterator it = v.begin(); it != v.end(); it++) {
		cout << *it << " ";
	}
	cout << endl;
}


void printArray(int arr[], int len) {
	for (int i = 0; i < len; i++) {
		cout << arr[i] << endl;
	}
}


void printMap(map<int, int>& m) {
	for (map<int, int>::iterator it = m.begin(); it != m.end(); it++) {
		cout << "key = " << it->first << " value = " << it->second << endl;
	}
	cout << endl;
}


void printUnorderedMap(unordered_map<int, int>& m) {
	for (unordered_map<int, int>::iterator it = m.begin(); it != m.end(); it++) {
		cout << "key = " << it->first << " value = " << it->second << endl;
	}
	cout << endl;
}


ListNode* V2LN(vector<int>& nums) {
    ListNode* fnode = new ListNode;
    ListNode* pnode = fnode;
    for (int num: nums) {
        // ListNode* next_n = new ListNode(num);
        pnode->next = new ListNode(num);
        pnode = pnode->next;
    }
    return fnode->next;
}

vector<int> LN2V(ListNode* ln, int max_len) {
    vector<int> vec;
    int cnt = 0;
    while (ln) {
        vec.push_back(ln->val);
        ln = ln->next;
        cnt += 1;
        if (cnt > max_len) break;
    }
    return vec;
}


TreeNode* V2TN(vector<int> nums) {
    if (nums.empty()) return nullptr;
    int node_n = nums.size();
    double h = log2(node_n + 1);
    if (int(h) != h) {
        int pad_n = pow(2, (int(h) + 1)) - 1 - node_n;
        for (int i = 0; i < pad_n; ++i) {
            nums.push_back(EmptyTN);
        }
		printVector(nums);
    }

    vector<TreeNode*> tn_vec;
    for (int num: nums) {
        TreeNode* cur_n = new TreeNode(num);
        tn_vec.push_back(cur_n);
    }

    for (int i = 0; i < tn_vec.size(); ++i) {
        auto cur_n = tn_vec[i];
        int cur_left_idx = i * 2 + 1;
        int cur_right_idx = i * 2 + 2;
        if (cur_left_idx >= node_n) break;
        if (nums[cur_left_idx] != EmptyTN) {
            cur_n->left = tn_vec[cur_left_idx];
        }
        if (nums[cur_right_idx] != EmptyTN) {
            cur_n->right = tn_vec[cur_right_idx];
        }
    }
    return tn_vec[0];
}