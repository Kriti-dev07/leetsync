class Solution {
public:
    bool canThreePartsEqualSum(vector<int>& arr) {
        int total=0;
        for(int x: arr){
            total+=x;
        }
        if(total%3!=0)return false;
        int target=total/3;
        int current_sum=0;
        int count=0;
        for(int i=0;i<arr.size();i++){
            current_sum+=arr[i];
            if(current_sum==target){
                count++;
                current_sum=0;
            }}
            if(count>=3){
                return true;
            }
        else {
            return false;}
    }
};