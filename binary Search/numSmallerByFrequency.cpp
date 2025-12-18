class Solution {
public:
    vector<int> numSmallerByFrequency(vector<string>& queries, vector<string>& words)
    {
        vector<int> word_min(words.size());
        vector<int> result;

        for(int i=0;i<words.size();i++)
        {
            char min_char = *min_element(words[i].begin(), words[i].end());
            int size_word=std::count(words[i].begin(), words[i].end(),min_char);
            word_min.push_back(size_word);
        }
        ranges::sort(word_min);

        for(int i=0;i<queries.size();i++)
        {
            char min_char2=*std::min_element(queries[i].begin(),queries[i].end());
            int size_word2=std::count(queries[i].begin(),queries[i].end(),min_char2);
            
            auto it=ranges::upper_bound(word_min,size_word2);
            result.push_back(word_min.end()-it);
        }
        return result;
    }
};