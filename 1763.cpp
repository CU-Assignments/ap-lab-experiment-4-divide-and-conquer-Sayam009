class Solution {
public:
    string longestNiceSubstring(string s) {
        int n = s.length();
        if (n < 2) return "";

        auto isNice = [](const string& str) {
            unordered_set<char> lower, upper;
            for (char c : str) {
                if (islower(c)) lower.insert(c);
                if (isupper(c)) upper.insert(c);
            }
            for (char c : lower) {
                if (upper.find(toupper(c)) == upper.end()) return false;
            }
            for (char c : upper) {
                if (lower.find(tolower(c)) == lower.end()) return false;
            }
            return true;
        };

        string result = "";
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j <= n; j++) {
                string sub = s.substr(i, j - i);
                if (isNice(sub) && sub.length() > result.length()) {
                    result = sub;
                }
            }
        }

        return result;
    }
};
