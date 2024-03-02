class Solution {
private:
    vector<int> solution1(string &s, vector<string>& words) {
        int wordsCount = words.size();
        int wordLength = words.front().size();
        int permutationStringSize = wordLength * wordsCount;
        int mainStringSize = s.size();
        vector<int> ans;

        if(mainStringSize < permutationStringSize) return ans;

        unordered_map<string, pair<vector<int>, int>> wordPositions;
        unordered_map<string, pair<vector<int>, int>>::iterator wordPositionsIterator;
        vector<int> wordLastPosition(wordsCount, -1);
        vector<int> whichWordStart(mainStringSize, -1);

        for(int i{0};i<wordsCount;++i) wordPositions[words[i]].first.push_back(i);
        int iterationEnd = mainStringSize-wordLength;

        for(int i{0};i<wordLength;++i) {
            for(int y{i};y<=iterationEnd;y+=wordLength) {
                if((wordPositionsIterator = wordPositions.find(s.substr(y, wordLength))) != wordPositions.end()) {
                    whichWordStart[y] = wordPositionsIterator->second.first[wordPositionsIterator->second.second];
                    ++wordPositionsIterator->second.second;
                    if(wordPositionsIterator->second.second == wordPositionsIterator->second.first.size()) wordPositionsIterator->second.second = 0;
                }
            }
            for(int &ip: wordLastPosition) ip = -1;
            int count{0}, j{i};
            for(;j<i+permutationStringSize;j+=wordLength) {
                if(whichWordStart[j] != -1) {
                    if(wordLastPosition[whichWordStart[j]] == -1) ++count;
                    wordLastPosition[whichWordStart[j]] = j;
                }
            }
            if(count == wordsCount) ans.push_back(j-permutationStringSize);
            for(;j<=iterationEnd;j+=wordLength) {
                int x = j-permutationStringSize;
                if(whichWordStart[x] != -1 && wordLastPosition[whichWordStart[x]] == x) {
                    --count;
                }
                if(whichWordStart[j] != -1) {
                    if(wordLastPosition[whichWordStart[j]] <= x) ++count;
                    wordLastPosition[whichWordStart[j]] = j;
                }
                if(count == wordsCount) ans.push_back(j-permutationStringSize+wordLength);
            }
        }
        sort(ans.begin(), ans.end());
        return ans;
    }
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        return solution1(s, words);
    }
};