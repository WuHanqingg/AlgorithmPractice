/*给你一个 无重复元素 的整数数组 candidates 和一个目标整数 target ，找出 candidates 中可以使数字和为目标数 target 的 所有 不同组合 ，并以列表形式返回。你可以按 任意顺序 返回这些组合。

candidates 中的 同一个 数字可以 无限制重复被选取 。如果至少一个数字的被选数量不同，则两种组合是不同的。 

对于给定的输入，保证和为 target 的不同组合数少于 150 个。*/
class Solution {
    vector<int> vc;
    vector<vector<int>> res;  
    void dfs(int idx,int target,vector<int> &candidates){
        if(target<0)return;
        if(!target){
            res.push_back(vc);
            return;
        }
        for(int i=0;i<=idx;i++){
            vc.push_back(candidates[i]);
            dfs(i,target-candidates[i],candidates);
            vc.pop_back();
        }
    }
public:    
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        sort(candidates.begin(),candidates.end());
        dfs(candidates.size()-1,target,candidates);
        return res;
    }
};