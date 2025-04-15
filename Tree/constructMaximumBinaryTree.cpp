class Solution {

    private:
        TreeNode* buildTree(vector<int>& nums) 
        {
            if (nums.empty()) return nullptr;
    
            // 找到最大值及其索引
            auto maxIt = max_element(nums.begin(), nums.end());//找到最大值的迭代器位置
            int maxIndex = distance(nums.begin(), maxIt);//从起始位置到最大值maxit的距离，即最大值的索引位置
            int maxValue = *maxIt;//最大值
    
            // 创建根节点
            TreeNode* root = new TreeNode(maxValue);
    
            // 递归终止条件
            if (nums.size() == 1) return root;
    
            // 分割左右子数组 已经剔除了最大元素
            vector<int> left(nums.begin(), nums.begin() + maxIndex);
            vector<int> right(nums.begin() + maxIndex + 1, nums.end());
    
            // 递归构建左右子树
            root->left = buildTree(left);
            root->right = buildTree(right);
    
            return root;
        }
    
    public:
        TreeNode* constructMaximumBinaryTree(vector<int>& nums)
        {
            if (nums.empty()) return nullptr;
            return buildTree(nums);
        }
    };