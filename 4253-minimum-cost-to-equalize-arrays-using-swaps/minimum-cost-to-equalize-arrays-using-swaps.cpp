 class Solution {
public:
    int minCost(vector<int>& nums1, vector<int>& nums2) {
     vector<int> t=nums1;
        unordered_map<int,int> freq;
        int n=nums1.size();
        for(int x:nums1)freq[x]++;
        for(int x:nums2)freq[x]++;

        for(auto&p :freq){
            if(p.second % 2) return -1;
        }
        unordered_map<int, int> diff;
        for(int x:nums1) diff[x]++;
        for(int x:nums2) diff[x]--;
        long long ans=0;
        for(auto &p :diff){
            ans+=abs(p.second);
        }
        return ans/4;
    }
};