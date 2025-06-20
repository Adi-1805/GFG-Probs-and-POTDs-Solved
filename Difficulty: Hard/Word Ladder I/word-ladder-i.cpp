class Solution {
  public:
    int wordLadderLength(string startWord, string targetWord,
                         vector<string>& wordList) {
        // Code here
        unordered_set<string> words(wordList.begin(), wordList.end());
        queue<pair<string, int>> q;
        q.push({startWord, 1});
        words.erase(startWord);
        
        if(words.find(targetWord) == words.end()) return 0;
        
        while(!q.empty()){
            auto word = q.front().first;
            int curStep = q.front().second; 
            q.pop();
            for(int i = 0; i < word.size(); i++){
                char orig = word[i];
                for(char ch = 'a'; ch <= 'z'; ch++){
                    word[i] = ch;
                    if(words.find(word) != words.end()){
                        q.push({word, curStep+1});
                        words.erase(word);
                    }
                }
                word[i] = orig;
            }
            if(word == targetWord) return curStep;
        }
        return 0;
    }
};