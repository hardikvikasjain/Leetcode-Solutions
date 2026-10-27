class Solution {
public:
    int mySqrt(int x) {
        //ans = pow(x,0.5);
        for(int i =0;i <=x;i++){
            if((long long)i * i> x){
                return i - 1;
            }
        }
        return x;
    }
};