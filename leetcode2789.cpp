/*给你一个下标从 0 开始、由正整数组成的数组 nums 。

你可以在数组上执行下述操作 任意 次：

选中一个同时满足 0 <= i < nums.length - 1 和 nums[i] <= nums[i + 1] 的整数 i 。将元素 nums[i + 1] 替换为 nums[i] + nums[i + 1] ，并从数组中删除元素 nums[i] 。
返回你可以从最终数组中获得的 最大 元素的值。*/
class Solution {
public:
    long long maxArrayValue(vector<int>& nums) {
     long long temp=nums.back(),res=nums.back();
     for(int i=nums.size()-2;i>=0;i--){
        if(temp>=nums[i])temp+=nums[i];
        else if(temp<nums[i]){
            res=max(res,temp);
            temp=nums[i];
        }
        if(i==0)res=max(temp,res);
     }   
     return res;
    }
};