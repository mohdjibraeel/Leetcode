class Solution {
public:
    long long countCommas(long long n) {
        long long ans=0;
        long long p=1000;
        while(n>=p){
            ans+=n-p+1;
            p=p*1000;
        }
        return ans;
    }
};