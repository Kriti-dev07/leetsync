class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int, int> freq;
        vector<int> ans;

        for (int x : nums) {
            freq[x]++;
        }

        for (int i = 1; i <= n; i++) {
            if (freq[i] == 0) {
                ans.push_back(i);
            }
        }

        return ans;
    }
};