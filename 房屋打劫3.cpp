//考察点：深搜，递归，回溯，存储已经计算过的结果（《算法导论》中带存储的递归），
//思路：houseRobber3函数就是一个自己调用自己的递归函数，他应该确保该函数返回的结果一定是
//以该节点为根节点的最大值，我之前浪费了很多时间，就是将根节点分类讨论了，导致不满足这一要求，
//所以，递归函数很重要的一点就是这个。因此，有了这个保障，你就可以用map来存储当前节点的
//结果了！这就是算法导论中所说的带存储的递归。

//总结：保证每次返回的结果是该根节点的最终结果；   带存储的递归

#include<iostream>
#include<limits.h>
#include<map>

using namespace std;

//  Definition of TreeNode:
  class TreeNode {
  public:
      int val;
      TreeNode *left, *right;
      TreeNode(int x,TreeNode *l,TreeNode *r) : val(x), left(l), right(r) {}
  };
/**
 * Definition of TreeNode:
 * class TreeNode {
 * public:
 *     int val;
 *     TreeNode *left, *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * }
 */
class Solution {
public:
    /**
     * @param root: The root of binary tree.
     * @return: The maximum amount of money you can rob tonight
     */
     map<TreeNode *, int > MyMap;
    int houseRobber3(TreeNode* root) {
        if (root == NULL)
            return 0;
        int rob=root->val, norob=0;
        if(MyMap.find(root) != MyMap.end()) {
            return MyMap[root];
        }
       if (root->left != NULL) {
            rob += houseRobber3(root->left->left);
            rob += houseRobber3(root->left->right);
       }
       if (root->right != NULL) {
            rob += houseRobber3(root->right->left);
            rob += houseRobber3(root->right->right);
       }
       norob += houseRobber3(root->left);
       norob += houseRobber3(root->right);

       int max1 = max(rob,norob);
       if (MyMap.find(root) != MyMap.end()) {
            if (MyMap[root] < max1)
                MyMap[root] = max1;
        } else {
            MyMap[root] = max1;
        }
        return MyMap[root];
    }
 /*   int help(TreeNode * root,  bool flag) {
       // cout<<flag<<endl;
        if (root == NULL )
            return 0;
        if (MyMap.find(root) != MyMap.end())
            return MyMap[root];
        int sum1=0,sum2=0,sum3=0;
        if (!flag){
            sum1 = help(root->left,  true) + help(root->right, true);
            sum2 = help(root->left,  true) + help(root->right, false);
            sum3 = help(root->left,  false) + help(root->right, true);
        } else {
            sum1 = help(root->left,  false) + help(root->right, false);
            //sum2 = help(root->right, sum, true);
        }
        int temp = sum2;
        if (sum1 > sum2) temp = sum1;
        if (!flag){
            temp =(temp>sum3 ? temp : sum3);
            if (MyMap.find(root) != MyMap.end()){
                if (temp > MyMap[root])
                    MyMap[root] = temp;
            } else {
                MyMap[root] = temp;
            }
            cout<<"map root:"<<MyMap[root]<<endl;
            return MyMap[root];
        }

        else{
            temp = root->val + sum1;
            if (root->val == 3) {
                cout<<root->val<<" "<<sum1<<endl;
            }
            if (MyMap.find(root) != MyMap.end()){
                if (temp > MyMap[root])
                    MyMap[root] = temp;
            } else {
                MyMap[root] = temp;
            }
            cout<<"map root:"<<MyMap[root]<<endl;
            return MyMap[root];

        }

    }*/
};

int main() {

    int a ;
    //cin>>a;
    TreeNode *n0 = new TreeNode(5,NULL,NULL);
    TreeNode *n1 = new TreeNode(4,NULL,NULL);
    //TreeNode * n2 = new TreeNode(1,NULL,NULL);
    TreeNode *n3 = new TreeNode(2,n0,n1);
    TreeNode *n4 = new TreeNode(3,NULL,NULL);
    TreeNode *n5 = new TreeNode(1,n3,n4);
    Solution sol;
    int res = sol.houseRobber3(n5);
    cout<<res<<endl;
    cout<<sol.MyMap.size();

}
