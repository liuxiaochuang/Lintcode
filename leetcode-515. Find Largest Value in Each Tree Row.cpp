//poj2342-Anniversary party-tree_dp
//�㷨������dp
//˼·���������ϴ�ţ�����ģ�����˼����dp[i][0]��dp[i][1]�ֱ��ʾ��i���˲�ȥ����ȥ������µ��ܵĻ��ֹ���ֵ������Ᵽ֤
//ֻ��һ�����ڵ㣬���Եô�Ҷ�ӽڵ������ߣ� father��¼���¼���ϵ��visited��¼�Ƿ���ʹ�
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
