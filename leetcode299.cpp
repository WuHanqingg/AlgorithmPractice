/*你在和朋友一起玩 猜数字（Bulls and Cows）游戏，该游戏规则如下：

写出一个秘密数字，并请朋友猜这个数字是多少。朋友每猜测一次，你就会给他一个包含下述信息的提示：

猜测数字中有多少位属于数字和确切位置都猜对了（称为 "Bulls"，公牛），
有多少位属于数字猜对了但是位置不对（称为 "Cows"，奶牛）。也就是说，这次猜测中有多少位非公牛数字可以通过重新排列转换成公牛数字。
给你一个秘密数字 secret 和朋友猜测的数字 guess ，请你返回对朋友这次猜测的提示。

提示的格式为 "xAyB" ，x 是公牛个数， y 是奶牛个数，A 表示公牛，B 表示奶牛。

请注意秘密数字和朋友猜测的数字都可能含有重复数字。*/
class Solution {
public:
    string getHint(string secret, string guess) {
        map<char,int> mp,mp1;
        int bull=0,cow=0;
        for(int i=0;i<secret.size();i++){
            if(secret[i]==guess[i])bull++;
                else{
                    mp[secret[i]]++;
                    mp1[guess[i]]++;
                }
            }
        for(auto &i:mp1){
            if(mp.count(i.first))
                cow+=min(mp[i.first],mp1[i.first]);
        }
        string s1="",s2="A",s3="",s4="B";
        if(bull==0)s1='0';if(cow==0)s3='0';//特判
        while(bull){
            s1+=bull%10+'0';
            bull/=10;
        }
        while(cow){
            s3+=cow%10+'0';
            cow/=10;
        }
        
        reverse(s1.begin(),s1.end());
        reverse(s3.begin(),s3.end());
        return s1+s2+s3+s4;
    }
};