class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target)
    {
        //对于这道题他的value表示的是下标（it->second）
        //创建一个哈希表无序的，key 和value 都是int值
        std::unordered_map<int,int> map;

        for(int i=0;i<nums.size();i++)
        {
            auto it=map.find(target-nums[i]);

            if(it!=map.end())
            {
                //找到了直接返回2个值
                return {it->second,i};
            }
            map[nums[i]]=i;
        }
        return {};
    }
};