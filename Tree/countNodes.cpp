class Solution
{
public:
    int countNodes(TreeNode* root)
    {
        if(root==nullptr) return 0;
 
        TreeNode *left=root->left;
        TreeNode *right=root->right;
        int leftdep=0,rightdep=0;
        
        while(left)//求左边子树的深度
        {
            left=left->left;
            leftdep++;
        }

        while(right)
        {
            right=right->right;
            rightdep++;
        }

        if(leftdep==rightdep)
            return (2<<leftdep)-1;

        //左右不相等运行这个一层层递归统计
        int leftNum=countNodes(root->left);     //左
        int rightNum=countNodes(root->right);   //右
        int result=leftNum+rightNum+1;          //中

        return result;
    }
    //nihao
};