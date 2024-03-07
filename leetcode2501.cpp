/*给你一个整数数组 nums 。如果 nums 的子序列满足下述条件，则认为该子序列是一个 方波 ：

子序列的长度至少为 2 ，并且
将子序列从小到大排序 之后 ，除第一个元素外，每个元素都是前一个元素的 平方 。
返回 nums 中 最长方波 的长度，如果不存在 方波 则返回 -1 。

子序列 也是一个数组，可以由另一个数组删除一些或不删除元素且不改变剩余元素的顺序得到。*/
class Solution {
public:
    int longestSquareStreak(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<int> a(nums.back()+1);
        for(auto &i:nums)a[i]=1;
        for(int i=0;i<nums.size();i++){
            int x=sqrt(nums[i]);
            if(x*x==nums[i])
            a[nums[i]]=a[x]+1;
        }
        int len=1;
        for(int i=0;i<=nums.back();i++)
            len=max(len,a[i]);
        return len==1?-1:len;
    }
};