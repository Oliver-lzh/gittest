class Solution {
    public:
        bool hasPathSum(TreeNode* root, int targetSum)
        {
            if(root==NULL) return false;
    
            queue<pair<TreeNode *,int>> q;
            q.push({root,root->val});
    
            while(!q.empty())
            {
                auto [node,current]=q.front();
                q.pop();
    
                if(node->left==NULL && node->right==NULL)
                {
                    if(current==targetSum) return true;
                }
                else
                {
                    if(node->left!=NULL) 
                    {q.push({node->left,current+node->left->val});}
                    if(node->right!=NULL) 
                    {q.push({node->right,current+node->right->val});}
                }
            }
            return false;    
        }
    };