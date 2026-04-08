class Solution {
public:
    vector<int> smallestTrimmedNumbers(vector<string>& nums, vector<vector<int>>& queries) {
        vector<int> result;

        for (auto &q : queries) {
            int k = q[0];
            int trim = q[1];

            vector<pair<string, int>> temp;

            for (int i = 0; i < nums.size(); i++) {
                string s = nums[i].substr(nums[i].size() - trim);
                temp.push_back({s, i});
            }

            sort(temp.begin(), temp.end());

            result.push_back(temp[k - 1].second);
        }

        return result;
    }
};