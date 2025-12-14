class Solution {
public:
    int find(vector<int>& nums, int target)
    {
        int left=0,right=nums.size()-1;

        while(left<=right)
        {
            int middle=left+(right-left)/2;

            if(nums[middle]<=target)
            {
                left=middle+1;
                
            }
            else 
            {
               right=middle-1;
            }
        }
        return left;
    }

    vector<int> searchRange(vector<int>& nums, int target) 
    {
        int left=find(nums,target);
        int right=find(nums,target+1)-1;

        if (left == nums.size() || nums[left] != target) {
            return {-1, -1}; // nums 中没有 target
        }
        return {left,right};
    }
};