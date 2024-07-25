
//删除重复元素
int removeDuplicates(int* nums, int numsSize)
{
    int slow=1,fast=1;
    for(;fast<numsSize;fast++)
    {
        //这里出现的问题就是如果fast是最后一个元素，数组再加一就没有对应的元素了
        if(nums[fast]!=nums[fast-1])
        {
            //如果不修改数组中的元素，就默认保留之前存在的，不要对其重新赋值。
            nums[slow]=nums[fast];
            slow++;
        }
    }
    return slow;
}