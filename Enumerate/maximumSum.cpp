class Solution {
public:
    int get_sum(int sum)
    {
        int result = 0;
        while (sum)
        {
            result += sum % 10;
            sum /= 10;
        }
        return result;
    }

    int maximumSum(vector<int>& nums)
    {
        unordered_map<int, int> cnt; // key: 数位和, value: 该数位和对应的最大数值的索引
        int result = -1;

        for (int i = 0; i < nums.size(); i++)
        {
            int middle = get_sum(nums[i]);
            
            if(cnt.count(middle))
            {
                result=max(result,nums[i]+cnt[middle]);
                cnt[middle]=max(cnt[middle],nums[i]);//将同一位数的哈希表更新为最的值（左维护）
            }
            else//没有遇到同意位数的存储位数和对应的数值
            {
                cnt[middle]=nums[i];
            }
        }
        return result;
    }
};