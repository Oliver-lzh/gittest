class Solution {
public:
    int find_max(vector<int>& potions,double target)
    {
        int left=0,right=potions.size()-1;
       
        while(left<=right)
        {
            int middle=left+(right-left)/2;
            if(potions[middle]>=target)
            {
                right=middle-1;
            }
            else
            {
                left=middle+1;
            }
        }
        return left;
    }

    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success)
    {
        vector<int> result;
        sort(potions.begin(), potions.end());
        for(int i=0;i<spells.size();i++)
        {
            double target=(double)success/spells[i];
            int left=find_max(potions,target);
            result.push_back(potions.size()-left);
        }
        return result;
    }
};