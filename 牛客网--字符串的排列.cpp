https://www.nowcoder.com/practice/fe6b651b66ae47d7acce78ffdd9a96c7?
class Solution {
public:
    // 判断str是否存在于结果集result中
    bool IsExist(vector<string>& result,string& str)
    {
        // 遍历结果集
        for(auto it=result.begin();it<result.end();++it)
        {
            // 若结果集中有元素和str相等，则表示存在，返回true
            if(*it==str)
            {
                return true;
            }
        }
        // 否则返回false
        return false;
    }
    void _Permutation(string& str,int begin,vector<string>& result)
    {
        // 递归出口，字符串递归到只剩下一个字符，可认为只有一种排列，插入后return
        if(begin==str.length()-1)
        {
            // 去重，str在结果集result中不存在时再尾插到结果集
            if(!IsExist(result,str))
            {
                result.push_back(str);
            }
            return;
        }
        
        for(int i=begin;i<str.length();++i)    // begin当前永远代表第一个元素，意味着i和begin交换，就是以i作为开始
        {
            swap(str[begin],str[i]);    // 交换begin和i，以i对应的字符作为开始(当begin为0时，其实未发生交换)
            _Permutation(str,begin+1,result);    // 递归处理求以i开头的剩余字符的组合，将所有可能保存到了result中
            swap(str[begin],str[i]);    // 回溯，再交换回来，恢复到递归前
        }
    }
    
    vector<string> Permutation(string str) {
        vector<string> result;
        if(str.length()>0)
        {
            _Permutation(str,0,result);
            sort(result.begin(), result.end());
        }
        return result;
    }
};