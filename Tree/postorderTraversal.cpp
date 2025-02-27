/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:

      void traversal(TreeNode *cur,vector<int> &vec)
    {
        if(cur == NULL) return; //空数组
        traversal(cur->left,vec); //左
        traversal(cur->right,vec);//右
        vec.push_back(cur->val);  //中
    }


    vector<int> postorderTraversal(TreeNode* root)
    {
        vector<int> result;
        traversal(root,result);
        return result;
    }
};