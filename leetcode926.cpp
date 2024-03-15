/*如果一个二进制字符串，是以一些 0（可能没有 0）后面跟着一些 1（也可能没有 1）的形式组成的，那么该字符串是 单调递增 的。

给你一个二进制字符串 s，你可以将任何 0 翻转为 1 或者将 1 翻转为 0 。

返回使 s 单调递增的最小翻转次数。

1.两个数组dpone[i]表示第i个位置以1结尾最短需要多少，dpzero同理
2.显然dpzero由到位置i位置的1的数量决定，所以可以先求出dpzero
3.对于dpone[i],if(s[i]=='1'){
                dpone.push_back(min(dpzero[i-1],dpone[i-1]));
            }
            else if(s[i]=='0')
                dpone.push_back(min(dpzero[i-1],dpone[i-1])+1);
*/
class Solution {
public:
    int minFlipsMonoIncr(string s) {
        int res=0;
        vector<int> dpone,dpzero;
        for(int i=0;i<s.size();i++){
            if(s[i]=='1')res++;
            dpzero.push_back(res);
        }
        if(s[0]=='1')dpone.push_back(0);
        else dpone.push_back(1);
        for(int i=1;i<s.size();i++){
            if(s[i]=='1'){
                dpone.push_back(min(dpzero[i-1],dpone[i-1]));
            }
            else if(s[i]=='0')
                dpone.push_back(min(dpzero[i-1],dpone[i-1])+1);
        }
        res=min(dpone.back(),dpzero.back());
        return res;
    }
};