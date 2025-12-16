class Solution {
public:
    
    int findTheDistanceValue(vector<int>& arr1, vector<int>& arr2, int d)
    {
        ranges::sort(arr2);
        int ans=0;

        for(int x:arr1)
        {
            auto it=ranges::lower_bound(arr2,x-d);//这里确保了左边的值都满足条件 *it>x+d这个条件满足了右边的值都大于d的距离
            if(it==arr2.end() || *it>x+d) //第一个条件说明最小值已经在arr2的末尾，说明arr2其他值都小于target并且距离够
            {
                ans++;
            }
        }
        return ans;
    }
};