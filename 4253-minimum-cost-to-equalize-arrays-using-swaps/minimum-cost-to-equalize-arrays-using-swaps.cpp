class Solution {
public:
    int minCost(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> cnt1, cnt2;

        for (int x : nums1) cnt1[x]++;
        for (int x : nums2) cnt2[x]++;

        unordered_set<int> allVals;
        for (auto& [v, _] : cnt1) allVals.insert(v);
        for (auto& [v, _] : cnt2) allVals.insert(v);

        int totalExcess = 0;

        for (int v : allVals) {
            int c1 = cnt1.count(v) ? cnt1[v] : 0;
            int c2 = cnt2.count(v) ? cnt2[v] : 0;
            int total = c1 + c2;

            if (total % 2 != 0) return -1;

            int needed = total / 2;

            if (c1 > needed) {
                totalExcess += (c1 - needed);
            }
        }

        return totalExcess;
    }
};