/*给定一个不含重复数字的数组 nums ，返回其 所有可能的全排列 。你可以 按任意顺序 返回答案。*/
class Solution {
    vector<int> vec;
    vector<vector<int>> res;
    int a[7]={0,0,0,0,0,0,0};
    void dfs(int a[],vector<int> &nums){
        if(vec.size()==nums.size()){
            res.push_back(vec);
            return;
        }
        for(int i=0;i<nums.size();i++){
            if(!a[i]){
                vec.push_back(nums[i]);
                a[i]=1;
                dfs(a,nums);
                a[i]=0;
                vec.pop_back();
            }
        }
    }
public:
    vector<vector<int>> permute(vector<int>& nums) {
        dfs(a,nums);
        return res;
    }
};