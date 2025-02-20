class Solution {
public:
    vector<int> beautifulArray(int N) {
        vector<int> result = {1};
        while (result.size() < N) {
            vector<int> temp;
            for (int x : result) {
                if (2 * x - 1 <= N) temp.push_back(2 * x - 1); // Odd numbers
            }
            for (int x : result) {
                if (2 * x <= N) temp.push_back(2 * x); // Even numbers
            }
            result = temp;
        }
        return result;
    }
};
