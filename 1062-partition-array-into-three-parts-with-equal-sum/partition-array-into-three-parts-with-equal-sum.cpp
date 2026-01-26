class Solution {
public:
    bool canThreePartsEqualSum(vector<int>& arr) {
        int total = 0;
        for (int x : arr) total += x;

        if (total % 3 != 0) return false;

        int target = total / 3;
        int currSum = 0;
        int count = 0;

        for (int i = 0; i < arr.size(); i++) {
            currSum += arr[i];
            if (currSum == target) {
                count++;
                currSum = 0;
            }
        }

        return count >= 3;
    }
};
