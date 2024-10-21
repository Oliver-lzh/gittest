int minSubArrayLen(int target, int* nums, int numsSize)
{
    int slow=0,fast=0;
    int minsum=INT_MAX;
    int sum=0;
    int length=0;

    //循环条件
    for(;fast<numsSize;fast++)
    {
        sum=sum+nums[fast];
        //考虑1,1,1,100 target=100，因此用while
        while(sum>=target)
        {
            length=fast-slow+1;
            minsum=minsum<length?minsum:length;
            sum=sum-nums[slow];
            slow++;
        }
    }
    return minsum==INT_MAX?0:minsum;
}