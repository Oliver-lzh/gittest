/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** generateMatrix(int n, int* returnSize, int** returnColumnSizes) 
{
    //初始化返回的数组的大小
    *returnSize = n;
    *returnColumnSizes = (int*)malloc(sizeof(int) * n);
    //初始化返回结果数组ans
    int** ans = (int**)malloc(sizeof(int*) * n);//这个ans是指向二位数组，二位数组里面分为三个数组， 每个数组都有一个指针指向。
    int i;
    for(i = 0; i < n; i++) {
        ans[i] = (int*)malloc(sizeof(int) * n);
        (*returnColumnSizes)[i] = n;
    }
    
    //设置每次循环的起始位置
    int startX = 0;
    int startY = 0;
    //设置二维数组的中间值，若n为奇数。需要最后在中间填入数字
    int mid = n / 2;
    //循环圈数
    int loop = n / 2;
    //偏移数
    int offset = 1;
    //当前要添加的元素
    int count = 1;

    while(loop)
    {
        int i=startX;
        int j=startY;

        //从左到右 1+4-3
        for(;j<startY+n-offset;j++)
        {
            ans[startX][j]=count++;
        }

        //从上到下
        for(;i<startX+n-offset;i++)
        {
            ans[i][j]=count++;
        }
        //从右到左
        for(;j>startY;j--)
        {
            ans[i][j]=count++;
        }
        //从下到上
        for(;i>startX;i--)
        {
            ans[i][j]=count++;
        }

        //经过了一圈的外层后，减少2个元素，因此处理下一圈的时候就减少2个元素处理，因此这里偏移+2 for循环就减少2个元素的处理
        offset+=2;
        //x y表示的是一圈的初始位置 每一圈的初始位置都是从0,0开始的对角线 一直下去就是1,1 2,2。
        startX++;
        startY++;
        loop--;
    }
    
    //若n为奇数需要单独给矩阵中间赋值
    if(n%2)
        ans[mid][mid] = count;

    return ans;
}