class Solution {
public:
    int minimumPossibleSum(int n, int target) {
        int pair=target>>1;
        vector<long long> arr;
        long long res=0,size=0;
        for(int i=1;i<=n&&i<=pair;i++){
            res+=i;size=i;
        }
        if(size<n){
            for(int i=target;size<n;i++){
                res+=i;size++;
                }
        }
        return res%(1000000000+7);
    }
};