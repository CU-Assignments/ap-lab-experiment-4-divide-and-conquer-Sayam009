class Solution {
public:
    int superPow(int a, vector<int>& b) {
        const int MOD = 1337;
        a %= MOD;
        int result = 1;
        for (int i = b.size() - 1; i >= 0; --i) {
            result = (result * power(a, b[i], MOD)) % MOD;
            a = power(a, 10, MOD); // Update a to a^10 % MOD
        }
        return result;
    }

    int power(int a, int b, int MOD) {
        int result = 1;
        while (b > 0) {
            if (b % 2 == 1) result = (result * a) % MOD;
            a = (a * a) % MOD;
            b /= 2;
        }
        return result;
    }
};
