class Solution {
public:
    int findComplement(int num) {
        if (num == 0) return 1;

        int ans = 0, mul = 1;

        while (num) {
            int bit = (num & 1) ^ 1;
            ans += bit * mul;
            mul <<= 1;
            num >>= 1;
        }
        return ans;
    }
};
