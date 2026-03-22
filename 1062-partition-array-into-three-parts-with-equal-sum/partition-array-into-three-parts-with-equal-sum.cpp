
/*Most optimal
time: O(n)
space:O(1)*/
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
/*prefix sum+two cuts
same logic as previous just more controlled
time:O(n)
space: O(1)*/
class solution {
public:
 bool canThreePartsEqualSum(vector<int>& arr) {
     int total=0;
for(int x:arr){
total+=x;
    
}
if(total%3!=0) return false;
int target=total/3;
int curr_sum=0;
int cuts=0;

for(int i=0;i<arr.size();i++){
curr_sum+=arr[i];
if(curr_sum==target && cuts==0){
cuts=1;
else if(curr_sum==2*target && i<arr.size()-1){
cuts=2;
break;
}}
return cuts==2;
}};
/*two pointer approach:
time:O(n)
space:O(1)*/
class solution{
public:
 bool canThreePartsEqualSum(vector<int>& arr) {
     int total=0;
for(int x: arr){
total+=x;
if(total%3!=0) return false;
int target=total/3;
int left_sum=0; right_sum=0;
int i=0, j=arr.size()-1;
while(i<j){
if(left_sum!=target) left_sum+=arr[i++];
if(right_sum!=target) right_sum+=arr[j--];
if(left_sum==target && right_sum== arr[j--] && i<j){
return true;}}
return false;
}};
    
/*prefix sum array
time:O(n^2)
space:O(n)*/
class solution{
public:
 bool canThreePartsEqualSum(vector<int>& arr) {
     int n=arr.size();
vector<int>a(n);
a[0]=arr[0];
for(int i=1;i<n;i++){
prefix[i]=prefix[i-1]+arr[i];
}
int total= prefix[n-1];
if(total%3!=0) return false;
int target=total/3;
for(int i=0;i<n-2;i++){
if(prefix[i]==target){
for(int j=i+1;j<n-1;j++){
if (prefix[j] == 2 * target) {
                        return true;
                    }
                }
            }
        }

        return false;
    }
};
/*brute force 
time complexity:O(n^3)
space:O(1)*/
class Solution {
public:
    bool canThreePartsEqualSum(vector<int>& arr) {
        int n = arr.size();

        for (int i = 0; i < n-2; i++) {
            for (int j = i+1; j < n-1; j++) {

                int s1 = 0, s2 = 0, s3 = 0;

                for (int k = 0; k <= i; k++) s1 += arr[k];
                for (int k = i+1; k <= j; k++) s2 += arr[k];
                for (int k = j+1; k < n; k++) s3 += arr[k];

                if (s1 == s2 && s2 == s3) return true;
            }
        }

        return false;
    }
};

