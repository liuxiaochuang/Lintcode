#include <cstdio>
 #include <cstring>
 #include<algorithm>
 #include<math.h>
 #include<set>
 #include<queue>
 #include<vector>
 #include<stdlib.h>
 #include<iostream>
 #include<sstream>
 #include<utility>

 #include<stack>
 #define INF 0x7fffffff
 #include<fstream>
 #include<time.h>
 //#define lxc
using namespace std;
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    void insert(TreeNode* root, int num) {
        if (root->val > num) {
            if (root->left) {
                insert(root->left, num);
            } else {
                root->left = new TreeNode(num);
            }
        } else {
            if (root->right) {
                insert(root->right, num);
            } else {
                root->right = new TreeNode(num);
            }
        }
    }
    void dfs(TreeNode* root, int start, int stop, vector<int> &nums) {
        if (start > stop) {
            return;
        }
        int mid = start + (stop - start) / 2;
        insert(root, nums[mid]);
        dfs(root, start, mid -1, nums);
        dfs(root, mid + 1, stop, nums);
    }
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        TreeNode* root = NULL;
        int len = nums.size();
        if (len < 1)
            return root;
        int mid = (len - 1) / 2;
        root = new TreeNode(nums[mid]);
        dfs(root, 0, mid - 1, nums);
        dfs(root, mid + 1,  len - 1, nums);
        return root;
    }
};
