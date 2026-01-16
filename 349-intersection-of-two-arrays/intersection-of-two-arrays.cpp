class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {

        if (nums1.size() > nums2.size())
            return intersection(nums2, nums1); // swap
    unordered_set<int>s(nums1.begin(),nums1.end()); // turning first array to a unordered set 
    unordered_set<int>result; // declaring unordered set of the resulting intersection 
    for(int x: nums2){   // loops runs for every element in nums 2 
        if(s.count(x)){           //if element of nums 2 exists in nums 1 
            result.insert(x);   //add it to result 
        }
    }
    return vector<int> (result.begin(),result.end());
}
};