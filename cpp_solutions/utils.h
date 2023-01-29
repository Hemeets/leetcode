/*
 * @Author: QDX
 * @Date: 2023-01-11 23:05:18
 * @Description: 
 */
#include <iostream>
#include <vector>
#include <stack>
#include <unordered_map>
#include <map>
#include <cmath>
#include <string>

using namespace std;

#define EmptyTN -100000

void printVector(vector<int>& v);

void printArray(int arr[], int len);

void printMap(map<int, int>& m);

void printUnorderedMap(unordered_map<int, int>& m);

// struct ListNode;
struct ListNode {
	int val;
	ListNode *next;
	ListNode() : val(0), next(nullptr) {}
	ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode* V2LN(vector<int>& nums);

vector<int> LN2V(ListNode* ln, int max_len=1000);


struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};


TreeNode* V2TN(vector<int> nums);


