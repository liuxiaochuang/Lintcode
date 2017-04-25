//����㣺���ѣ��ݹ飬���ݣ��洢�Ѿ�������Ľ�������㷨���ۡ��д��洢�ĵݹ飩��
//˼·��houseRobber3��������һ���Լ������Լ��ĵݹ麯������Ӧ��ȷ���ú������صĽ��һ����
//�Ըýڵ�Ϊ���ڵ�����ֵ����֮ǰ�˷��˺ܶ�ʱ�䣬���ǽ����ڵ���������ˣ����²�������һҪ��
//���ԣ��ݹ麯������Ҫ��һ������������ˣ�����������ϣ���Ϳ�����map���洢��ǰ�ڵ��
//����ˣ�������㷨��������˵�Ĵ��洢�ĵݹ顣

//�ܽ᣺��֤ÿ�η��صĽ���Ǹø��ڵ�����ս����   ���洢�ĵݹ�

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
