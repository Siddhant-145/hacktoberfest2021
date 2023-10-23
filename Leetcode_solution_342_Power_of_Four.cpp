class Solution {
public:
    bool isPowerOfFour(int n) {
        if(n == 1 ) return true;
        long long c =1;
        while( c <=n){
            if(c == n) return true;
            c = 4*c;
        }
        return false;

        
    }
};
