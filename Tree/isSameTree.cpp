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
        bool isSameTree(TreeNode* p, TreeNode* q)
        {
            queue<TreeNode *>que;
    
            que.push(p);
            que.push(q);
            if(q==NULL && p==NULL)
            {
                return true;
            }
            if(q!=NULL && p==NULL)
                return false;
            if(p!=NULL && q==NULL)
                return false;
    
            while(!que.empty())
            {
                TreeNode *leftNode=que.front();
                que.pop();
                TreeNode *rightNode=que.front();
                que.pop();
    
                if(!leftNode && !rightNode)//表示左右都为空
                    continue;//结束本次循环
                if(!leftNode || !rightNode || leftNode->val!=rightNode->val)//这里判断的是不对称的情况
                    return false;
                que.push(leftNode->left);
                que.push(rightNode->left);
                que.push(rightNode->right);
                que.push(leftNode->right);
          
            } 
            return true;
        }
    };