class Solution {
public:
    

        /* unoredered set approach 
        while (n != 1) {
            if (seen.count(n)) return false;  
            seen.insert(n);

            int s = 0;
            while (n > 0) {
                int digit = n % 10;
                s += digit * digit;
                n /= 10;
            }

            n = s; 
        }

        return true; 
   
*/
/*
mathematical trick as every unhappy cycle will reach 4 

    int getNext(int n) {
        int sum = 0;
        while (n) {
            int digit = n % 10;
            sum += digit * digit;
            n /= 10;
        }
        return sum;
    }

    bool isHappy(int n) {
        while (n != 1 && n != 4) {
            n = getNext(n);
        }
        return n == 1;
 
*/
 int getNext(int n) {
int sum=0;
while(n>0){
    int digit=n%10;
    sum+= digit*digit;
    n/=10;
}
return sum;
 }
    
    bool isHappy(int n) {
        int slow = n;
        int fast = getNext(n);
        
        while (fast != 1 && slow != fast) {
            slow = getNext(slow);
            fast = getNext(getNext(fast));
        }
        
        return fast == 1;

        
    }
};