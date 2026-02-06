class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int idx = 0;

        // move non-zero elements forward
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] != 0) {                 // here we overwrite values but doesnt matter once loops reaches end of array we are done scanning and in the final array space left is filled by zeros
                nums[idx++] = nums[i];
            }
        }

        // fill remaining positions with zero
        while (idx < nums.size()) {
            nums[idx++] = 0; // alternate way to write nums[idx]; idx++;

        }
    }
};
