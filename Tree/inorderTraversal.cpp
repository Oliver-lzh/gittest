class Solution {
    public:
        vector<int> inorderTraversal(TreeNode* root)
        {
            //指针是空就去栈找元素，栈指向的中间 左中右
            vector<int> result;
            stack<pair<TreeNode *,bool>> st;
            TreeNode *cur=root;
    
            if(root !=nullptr)
                st.push(make_pair(root,false));//为其左右孩子安排位次
    
            while(!st.empty())
            {
                auto node=st.top().first;//智能指针指向树的节点
                auto visited=st.top().second; //指向是否安排位置的第二个值
                st.pop();
    
                if(visited) //表示该节点和2个孩子的位次已经安排了，现在可以处理这个节点了
                {
                    result.push_back(node->val);
                    continue;//继续从while开始 
                }
    
                //visited 当前为 false, 表示初次访问本节点，此次访问的目的是“把自己和两个儿子在栈中安排好位次”。
    
                //下面就是没有安排的时候的代码即visited为false
                //入栈就是 右中左
                if(node->right)
                    st.push(make_pair(node->right,false));
    
                st.push(make_pair(node,true));
    
                if(node->left)
                    st.push(make_pair(node->left,false));
            }
            return result;
        } 
    };