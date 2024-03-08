/*给你两个正整数：n 和 target 。

如果数组 nums 满足下述条件，则称其为 美丽数组 。

nums.length == n.
nums 由两两互不相同的正整数组成。
在范围 [0, n-1] 内，不存在 两个 不同 下标 i 和 j ，使得 nums[i] + nums[j] == target 。
返回符合条件的美丽数组所可能具备的 最小 和，并对结果进行取模 109 + 7。*/
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