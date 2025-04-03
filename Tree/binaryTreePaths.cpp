class Solution {
    public:
    
        void getpath(TreeNode *cur,vector<int> &path,vector<string> &result)
        {
            path.push_back(cur->val);//中
            if(cur->left==NULL && cur->right==NULL)
            {
                string sPath;
                for(int i=0;i<path.size()-1;i++)//将path记录的路径用string连接
                {
                    sPath+=to_string(path[i]);
                    sPath+="->"
                }
                //拼接最后一个叶子节点 因为最后一个节点不需要连接->符号
                sPath+=to_string(path[path.size()-1]);
                result.push_back(sPath);
                return;
            }
            if(cur->left)//左
            {
                getpath(cur->left,path,result);
                path.pop_back();
            }
            if(cur->right)//右
            {
                getpath(cur->right,path,result);
                path.pop_back();
            }
        }
    
        vector<string> binaryTreePaths(TreeNode* root)
        {
            vector<string> result;
            vector<int> path;
            if(root==NULL) return result;
            getpath(root,paht,result);
            return result;
        }
    };