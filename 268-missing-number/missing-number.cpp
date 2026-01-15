class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        int expected = n * (n + 1) / 2;

        int actual = 0;
        for (int x : nums) {
            actual += x;             // basically sum of n natural numbers-actual sum 
        }

        return expected - actual;
    }
};
