class Solution {
public:
    int fib(int n) {
        if (n == 0) return 0;
        if (n == 1) return 1;

        int first_number = 0, second_number = 1; //starts at 0,1...
        for (int i = 2; i <= n; i++) {  //looping starts at i=2 and moves like i=3,4,5.. so on till it reaches n 
            int c = first_number + second_number; //  first iteration c=1(0+1) then or second a=1 and b=1 so c=2 simlilarly for third a=1b=2 so c=3
            // and for 4 th a=2 and b=3 so c becomes 5
            first_number = second_number;
            second_number = c;
        }
        return second_number;
    }
};
