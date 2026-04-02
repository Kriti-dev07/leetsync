class Solution {
public:
    bool isSorted(vector<int>& nums) {
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] < nums[i - 1]) return false;
        }
        return true;
    }

    int minimumPairRemoval(vector<int>& nums) {
        int ops = 0;

        while (!isSorted(nums)) {
            int n = nums.size();
            int minSum = INT_MAX;
            int idx = 0;

            // find leftmost pair with minimum sum
            for (int i = 0; i < n - 1; i++) {
                int sum = nums[i] + nums[i + 1];
                if (sum < minSum) {
                    minSum = sum;
                    idx = i;
                }
            }

            // merge the pair
            nums[idx] += nums[idx + 1];
            nums.erase(nums.begin() + idx + 1);

            ops++;
        }

        return ops;
    }
};