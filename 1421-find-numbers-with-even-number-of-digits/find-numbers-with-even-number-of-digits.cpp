class Solution {
public:
    int findNumbers(vector<int>& nums) {
        int result = 0;

        for (int x : nums) {
            int digits = log10(x) + 1;
            if (digits % 2 == 0) result++;
        }

        return result;
    }
};