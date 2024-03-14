/*给你一个数组 arr ，数组中有 n 个 非空 字符串。

请你求出一个长度为 n 的字符串 answer ，满足：

answer[i] 是 arr[i] 最短 的子字符串，且它不是 arr 中其他任何字符串的子字符串。如果有多个这样的子字符串存在，answer[i] 应该是它们中字典序最小的一个。如果不存在这样的子字符串，answer[i] 为空字符串。
请你返回数组 answer 。*/
/*
1.枚举所有子串放到哈希表
2.遍历每个字符串，将其所有子串哈希表中减一
3.遍历子串，找到哈希表中值为0的
4.比较过后加入返回vector
5.没有就添加一个空字符串
6.把所有子串添加回哈希表
*/
class Solution {
public:
vector<string> shortestSubstrings(vector<string>& arr) {
    unordered_map<string, int>mp;
    for (int i = 0; i < arr.size(); i++) {
        for (int j = 1; j <= arr[i].size(); j++) {
            for (int k = 0; k + j <= arr[i].size(); k++) {
                mp[arr[i].substr(k, j)]++;
            }
        }
    }
    vector<string> res;
    for (int i = 0; i < arr.size(); i++) {
        for (int j = 1; j <= arr[i].size(); j++) {
            for (int k = 0; k + j <= arr[i].size(); k++) {
                mp[arr[i].substr(k, j)]--;
            }
        }
        for (int j = 1; j <= arr[i].size(); j++) {
            for (int k = 0; k + j <= arr[i].size(); k++) {
                string temp = arr[i].substr(k, j);
                if (mp.at(temp)==0) {
                    if (res.size() < i + 1)res.push_back(temp);
                    else if (res.size() == i + 1) {
                        res[i] = res[i] > temp ? temp : res[i];
                    }
                }
            }
            if (res.size() == i + 1)break;
        }
        if (res.size() != i + 1)res.push_back("");
        for (int j = 1; j <= arr[i].size(); j++) {
            for (int k = 0; k + j <= arr[i].size(); k++) {
                mp[arr[i].substr(k, j)]++;
            }
        }
    }
    return res;
}
};