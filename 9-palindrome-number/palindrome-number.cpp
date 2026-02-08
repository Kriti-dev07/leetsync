class Solution {
public:
    bool isPalindrome(int x) {
        // negative numbers or numbers ending with 0 (except 0 itself)
   if(x<0||( x%10==0 && x!=0)){
    return false;
   }
   int reversehalf=0;
   while(x>reversehalf){
    reversehalf=reversehalf*10+x%10;
    x/=10;
   }
   return(x==reversehalf|| x==reversehalf/10);
    }
};
