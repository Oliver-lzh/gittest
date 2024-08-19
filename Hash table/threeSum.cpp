class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums)
    {
        //定义一个二维数组
        vector<vector<int>> result;
        //1.对数组进行排序
        sort(nums.begin(),nums.end());
        //2.遍历处理
        for(int i=0;i<nums.size();i++)
        {
    
         //第一个数就大于0直接返回结果
            if(nums[i]>0)
            {
                return result;
            }
            //去重处理 这里i>0一定要放在前面，否则会出现数组越界的问题
            if(i>0 && nums[i]==nums[i-1])
            {
                continue;//跳出当前循环，进行新的一轮循环
            }
            int left=i+1;
            int right=nums.size()-1;
            //3.循环处理左右指针
            while(right>left)
            {
                if(nums[i]+nums[left]+nums[right]>0)
                {
                    right--;
                }
                else if(nums[i]+nums[left]+nums[right]<0)
                {
                    left++;
                }
                else
                {
                    //保存结果
                    result.push_back(vector<int>{nums[i],nums[left],nums[right]});
                    //左右指针的去重处理
                    while(right>left && nums[right]==nums[right-1]) right--;
                    while(right>left && nums[left]==nums[left+1])   left++;
                    right--;
                    left++;
                    
                }
            }
        }
        return result;
    }
};