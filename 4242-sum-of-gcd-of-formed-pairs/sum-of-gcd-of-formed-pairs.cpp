class Solution {
public:
    long long gcdSum(vector<int>& nums) {
       vector<int> a=nums;
        int n=nums.size();
        vector<long long>prefixGcd(n);
        long long m=0;
        for(int i=0; i<n;i++){
            m=max(m,(long long )nums[i]);
            prefixGcd[i]=gcd((long long)nums[i],m);
            
        }
        sort(prefixGcd.begin(), prefixGcd.end());
        long long ans=0;
        int l=0, r=n-1;
        while(l<r){
            ans+=gcd(prefixGcd[l], prefixGcd[r]);
            l++;
            r--;
        }
        return ans;
    }
};