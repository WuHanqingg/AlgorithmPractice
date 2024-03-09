/*给你一个下标从 0 开始的整数数组 nums 。在一步操作中，移除所有满足 nums[i - 1] > nums[i] 的 nums[i] ，其中 0 < i < nums.length 。

重复执行步骤，直到 nums 变为 非递减 数组，返回所需执行的操作数。*/
// 单调栈
// 1. 每个元素一定时被左侧第一个更大的元素消除的
// 2. 设 x 消除 y，也就是 [x] .... [y]，那么
//    中间的 .... 一定先被消除，再 +1 次消除（x 消除 y）
// 3. 那么，x 被消除所需轮数就是 [....] 中的最大消除轮数 + 1

class Solution {
public:
    int totalSteps(vector<int>& nums) {
        stack<int> stk;
        int res=0,f[nums.size()];//储存每个数被删除需要几步
        for(int i=0;i<nums.size();i++){
            int cur=0;//当前数字被删除前执行了几次
            while(!stk.empty()&&nums[i]>=nums[stk.top()]){
                cur=max(cur,f[stk.top()]);
                stk.pop();
            }
            if(!stk.empty()){
                res=max(res,cur+1);
                f[i]=cur+1;
            }
            stk.push(i);
        }
        return res;
    }
};