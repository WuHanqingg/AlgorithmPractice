/*请你设计并实现一个能够对其中的值进行跟踪的数据结构，并支持对频率相关查询进行应答。

实现 FrequencyTracker 类：

FrequencyTracker()：使用一个空数组初始化 FrequencyTracker 对象。
void add(int number)：添加一个 number 到数据结构中。
void deleteOne(int number)：从数据结构中删除一个 number 。数据结构 可能不包含 number ，在这种情况下不删除任何内容。
bool hasFrequency(int frequency): 如果数据结构中存在出现 frequency 次的数字，则返回 true，否则返回 false。*/
class FrequencyTracker {
    unordered_map<int,int>cnt;
    unordered_map<int,int>num;
public:
    FrequencyTracker() {
        cnt.clear();
        num.clear();
    }
    
    void add(int number) {
        if(!num.count(number)){
            num[number]++;
            cnt[1]++;
        }
        else if(num.count(number)){
            cnt[num[number]]--;
            if(cnt[num[number]]==0)
                cnt.erase(num[number]);
            num[number]++;
            cnt[num[number]]++;
        }
    }
    
    void deleteOne(int number) {
        if(!num.count(number))return;
        else if(num.count(number)){
            cnt[num[number]]--;
            cnt[num[number]-1]++;
            if(cnt[num[number]]==0)cnt.erase(num[number]);
            num[number]--;
            if(!num[number])
                num.erase(number);
        }
        cnt.erase(0);
    }
    
    bool hasFrequency(int frequency) {
        if(cnt.count(frequency))
            return true;
        return false;
    }
};
