//poj2342-Anniversary party-tree_dp
//算法：树形dp
//思路：看着网上大牛的做的，核心思想是dp[i][0]和dp[i][1]分别表示第i个人不去或者去的情况下的总的欢乐贡献值，这道题保证
//只有一个根节点，所以得从叶子节点往根走； father记录上下级关系，visited记录是否访问过
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
    vector<int> largestValues(TreeNode* root) {
        vector<int> ret;
        if (root==NULL)
            return ret;
        queue<TreeNode*> q;
        q.push(root);
        while (q.size()) {
            int len = q.size();
            int maxi = INT_MIN;
            for (int i=0; i<len; i++) {
                TreeNode * temp = q.front();
                q.pop();
                if (temp->val > maxi)
                    maxi = temp->val;
                if (temp->left)
                    q.push(temp->left);
                if (temp->right)
                    q.push(temp->right);
            }
            ret.push_back(maxi);
        }
        return ret;
    }
};
int main()
{
    //Base b;
    cout<<sizeof(Base);

}
