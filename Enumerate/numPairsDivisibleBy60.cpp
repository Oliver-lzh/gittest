class Solution {
public:
    int numPairsDivisibleBy60(vector<int>& time) {
        unordered_map<int, int> cnt;
        int result = 0;

        for (int i = 0; i < time.size(); i++) {
            int r = time[i] % 60;
            int complement = (60 - r) % 60;
            result += cnt[complement];
            cnt[r]++;
        }
        return result;
    }
};