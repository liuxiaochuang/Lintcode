#include<iostream>
#include<vector>
#include<stack>
using namespace std;

  //Definition of TreeNode:
  class TreeNode {
  public:
      int val;
      TreeNode *left, *right;
      TreeNode(int val) {
          this->val = val;
          this->left = this->right = NULL;
      }
 };
 

class Solution {
public:
    /**
     * @param root: The root of binary tree.
     * @return: Preorder in vector which contains node values.
     */
    vector<int> preorderTraversal(TreeNode *root) {
        vector<int> result;
        stack<TreeNode*> sta;
        TreeNode * temp = root;
        while(temp != NULL || !sta.empty()){
//        	cout<<"temp != NULL"<<endl;
            while(temp!=NULL){
                int a = temp->val;
                //cout<<a<<" ";
                result.push_back(a);
                sta.push(temp);
                temp = temp->left;
            }
            if (!sta.empty()){
                temp = sta.top()->right;
                sta.pop();
            }
        }
        return result;
    }
};
int main(){
	Solution sol;
	TreeNode *n1 = new TreeNode(1);
	TreeNode *n2 = new TreeNode(2);
	TreeNode *n3 = new TreeNode(3);
	n1->left=n2;
	n1->right = n3;
	vector<int> a ;
	a = sol.preorderTraversal(n1);
	for(auto i:a){
		cout<<i<<" ";
	}
	
	
}