int* sortedSquares(int* nums, int numsSize, int* returnSize)
{
    int left=0,right=numsSize-1;
    int *res=(int *)malloc(sizeof(int)*numsSize);
    *returnSize = numsSize;
    int result=numsSize-1;
    int leftres=0,rightres=0;
      
    for(int i=0;i<numsSize;i++)
    {
        leftres=nums[left]*nums[left];
        rightres=nums[right]*nums[right];

        if(leftres>rightres)
        {
            res[result]=leftres;
            result--;
            left++;
        }
        else
        {
            res[result]=rightres;
            result--;
            right--;
        }
    }
    return res;
}