class Solution {
public:
    string shortestCompletingWord(string licensePlate, vector<string>& words) {
        vector<int> neededLetters(26, 0);

        for (char ch : licensePlate) {
            if (isalpha(ch)) {
                ch = tolower(ch);
                neededLetters[ch - 'a']++;
            }
        }

        auto canComplete = [&](const string& word) {
            vector<int> wordLetters(26, 0);
            for (char ch : word) {
                ch = tolower(ch);
                wordLetters[ch - 'a']++;
            }
            for (int i = 0; i < 26; i++) {
                if (wordLetters[i] < neededLetters[i]) {
                    return false; // Missing some letters
                }
            }
            return true;
        };

        string shortestWord = "";
        for (const string& word : words) {
            if (canComplete(word)) {
                if (shortestWord.empty() || word.size() < shortestWord.size()) {
                    shortestWord = word;
                }
            }
        }

        return shortestWord;
    }
};