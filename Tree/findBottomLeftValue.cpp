class Solution {
    public:
        int findBottomLeftValue(TreeNode* root)
        {
            queue<TreeNode *> que;
            int reszult;
            int dep=0;
            int dep1=0;
    
            if(root!=NULL) que.push(root);
    
            while(!que.empty())
            {
                int size=que.size();
                for(int i=0;i<size;i++)
                {
                    TreeNode *node=que.front();
                    que.pop();
                    if(i==0) reszult=node->val; //每次遍历每层的时候都会被重新赋值
                    if(node->left) que.push(node->left);
                    if(node->right) que.push(node->right);
                }           
            }
    
        return reszult;
        }
    };