/*给你一个下标从 0 开始的字符串 word ，长度为 n ，由从 0 到 9 的数字组成。另给你一个正整数 m 。

word 的 可整除数组 div  是一个长度为 n 的整数数组，并满足：

如果 word[0,...,i] 所表示的 数值 能被 m 整除，div[i] = 1
否则，div[i] = 0
返回 word 的可整除数组。*/
class Solution {
public:
    vector<int> divisibilityArray(string word, int m) {
        vector<long long> arr;
        arr.push_back(word[0]-'0');
        for(int i=1;i<word.length();i++){
            arr.push_back((arr.back()%m)*10+(word[i]-'0'));
        }
        for(auto &i:arr){
            i = i % m == 0 ? 1 :0;
        }
        vector<int> res;
        for(auto&i:arr)res.push_back(i);
        return res;
    }
};