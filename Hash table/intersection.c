int* intersection(int* nums1, int nums1Size, int* nums2, int nums2Size, int* returnSize)
{
    int nums1Cnt[1001]={0};
    int lessSize=nums1Size<nums2Size? nums1Size:nums2Size;
    int *result=(int *)calloc(lessSize,sizeof(int));
    int resultIndex=0;
    int *tmpNums;

    int i;

    //记录出现的数字
    for(i=0;i<nums1Size;i++)
    {
        nums1Cnt[nums1[i]]++;
    }

    for(i=0;i<nums2Size;i++)
    {
        if(nums1Cnt[nums2[i]]>0)//判断是否出现过在1数组中，出现过就会保存出现次数
        {
            result[resultIndex]=nums2[i];
            resultIndex++;
            nums1Cnt[nums2[i]]=0;//避免重复出现返回
        }
    }

    *returnSize=resultIndex;

    return result;
}