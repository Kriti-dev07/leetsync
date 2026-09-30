class Solution {
public:
    int findShortestSubArray(vector<int>& nums) {
        unordered_map<int, int> count;
        unordered_map<int, int> first;

        int degree = 0;
        int ans = nums.size();

        for (int i = 0; i < nums.size(); i++) {

            if (!first.count(nums[i]))
                first[nums[i]] = i;

            count[nums[i]]++;

            int freq = count[nums[i]];

            if (freq > degree) {
                degree = freq;
                ans = i - first[nums[i]] + 1;
            }
            else if (freq == degree) {
                ans = min(ans, i - first[nums[i]] + 1);
            }
        }

        return ans;
    }
};