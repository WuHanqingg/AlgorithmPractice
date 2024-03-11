/*给你一个字符串 title ，它由单个空格连接一个或多个单词组成，每个单词都只包含英文字母。请你按以下规则将每个单词的首字母 大写 ：

如果单词的长度为 1 或者 2 ，所有字母变成小写。
否则，将单词首字母大写，剩余字母变成小写。
请你返回 大写后 的 title 。*/
class Solution {
public:
    string capitalizeTitle(string title) {
        string res="";string temp="";
        vector<string> vc;
        for(int i=0;i<title.size();i++){
            if(title[i]==' '||i==title.size()-1){
                if(i==title.size()-1){
                    temp+=title[title.size()-1];
                }
                int length=temp.size();
                if(length>2){
                    if(temp[0]>='a'&&temp[0]<='z')
                        temp[0]=temp[0]-'a'+'A';
                    for(int i=1;i<temp.size();i++){
                        if(temp[i]>='A'&&temp[i]<='Z')
                            temp[i]=temp[i]-'A'+'a';
                    }
                    vc.push_back(temp);temp="";
                }
                else{
                    for(int i=0;i<temp.size();i++){
                        if(temp[i]>='A'&&temp[i]<='Z')
                            temp[i]=temp[i]-'A'+'a';
                    }
                    vc.push_back(temp);temp="";
                }
            }
            else
            temp+=title[i];
        }
        res+=vc[0];res+=' ';
        if(vc.size()>1){
            for(int i=1;i<vc.size();i++){
                res+=vc[i];res+=' ';
            }
        }
        res.erase(res.end()-1);
        return res;
    }
};