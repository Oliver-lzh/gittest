class Solution {
public:
    int maxDistance(vector<vector<int>>& arrays) {
        int result = 0;
        int min_val = arrays[0][0];  // 第一个数组的第一个元素（最小值）
        int max_val = arrays[0].back(); // 第一个数组的最后一个元素（最大值）

        // 从第二个数组开始遍历
        for (int i = 1; i < arrays.size(); ++i) {
            int curr_min = arrays[i][0];
            int curr_max = arrays[i].back();

            // 当前数组的最小值 和 全局最大值 的差
            result = max(result, abs(curr_min - max_val));
            // 当前数组的最大值 和 全局最小值 的差
            result = max(result, abs(curr_max - min_val));

            // 更新全局最小值和最大值（用于后续数组比较）
            min_val = min(min_val, curr_min);
            max_val = max(max_val, curr_max);
        }

        return result;
    }
};