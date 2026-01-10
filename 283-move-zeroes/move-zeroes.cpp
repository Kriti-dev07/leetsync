class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int idx = 0;

        // move non-zero elements forward
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] != 0) {
                nums[idx++] = nums[i];
            }
        }

        // fill remaining positions with zero
        while (idx < nums.size()) {
            nums[idx++] = 0;
        }
    }
};
