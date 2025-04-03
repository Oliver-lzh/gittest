class Solution {
    public:
    
        int getheight(TreeNode *node)
        {
            if(node==NULL) return 0;
            int leftheight=getheight(node->left);
            if(leftheight==-1) return -1;
            int rightheight=getheight(node->right);
            if(rightheight==-1) return -1;
    
            int result;
            if(abs(leftheight-rightheight)>1)
                result=-1;
            else
                result=1+max(leftheight,rightheight);
    
            return result;
        }
    
        bool isBalanced(TreeNode* root)
        {
            return getheight(root)==-1? false : true;
        }
    };


//迭代法
    int getDepth(TreeNode *node)
    {
        stack<TreeNode *> st;
        if(node!=NULL) st.push(node);

        int depth=0;
        int result=0;
        while(!st.empty())
        {
            TreeNode *cur=stack.top();
            if(cur!=NULL)
            {
                st.pop();
                st.push(cur);
                st.push(NULL);
                depth++;
                if(cur->right) st.push(node->right);
                if(cur->left)  st.push(node->left);
            }
            else
            {
                st.pop();
                node=st.top();
                st.pop();
                depth--;
            }
           result=result>depth? result:depth;
        }
        return result;
    }

    bool isBalanced(TreeNode* root)
    {
       stack<TreeNode *> st;
       if(root==NULL) return true;
       st.push(root);
       while(!st.empty())
       {
            TreeNode *node=st.top();
            st.pop();
            if(abs(getDepth(node->left)-getDepth(node->right))>1)
                return false;
            if(node->right) st.push(node->right);
            if(node->left)  st.push(node->left);
       }
    return true;
    }
};