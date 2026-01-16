class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {

        // size optimization (your logic)
        if (nums1.size() > nums2.size())
            return intersect(nums2, nums1);

             unordered_map<int, int> freq;
        for (int x : nums1) {
            freq[x]++;
        }


        vector<int>result;
        for(int x:nums2){
            if (freq[x] > 0) {
                result.push_back(x);   // not insert
                freq[x]--;             // handle duplicates
            }
        }

        return result;
    }
};