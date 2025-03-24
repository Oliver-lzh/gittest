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
//递归
class Solution {
    public:
            bool compare(TreeNode *left,TreeNode *right)//第一步确定参数和返回值
            {
                //第二部确定返回条件
                if(left==NULL && right !=NULL) return false;
                else if(left !=NULL && right ==NULL) return false;
                else if(left==NULL && right == NULL) return true;
                else if(left->val != right->val) return false;
    
                //第三部.处理单层逻辑
                bool outside=compare(left->left,right->right);
                bool insize=compare(left->right,right->left);
                bool isSame=outside && insize;
                return isSame;
            }
    
        bool isSymmetric(TreeNode* root) 
        {
            if(root ==NULL) return true;
            return compare(root->left,root->right);
        }
    };

//迭代

class Solution {
    public:
        bool isSymmetric(TreeNode* root) 
        {
            queue<TreeNode *> st;
            if(root==NULL) return true;
            st.push(root->left);
            st.push(root->right);
    
            while(!st.empty())
            {
                TreeNode *leftNode=que.front();que.pop();
                TreeNode *rightNode=que.front();que.pop();
    
                if(!leftNode && !rightNode)//说明是对称的
                {
                    continue;
                }
    
                if(!leftNode || !rightNode || (left->val !=rightNode->val))
                {
                    return false;
                }
    
                que.push(leftNode->left);
                que.push(rightNode->right);
                que.push(leftNode->right);
                que.push(rightNode->left);
    
            }
        return true;
        }
    };