https://www.nowcoder.com/practice/8fecd3f8ba334add803bf2a06af1b993?
class Solution {
public:
    // 自定义的比较函数
    static bool cmp(int x, int y)
    {
        // 把x转为string类型的xs，把y转为string类型的ys
        string xs = to_string(x);
        string ys = to_string(y);
        
        // A = xs+ys
        string A = xs;
        A += ys;
        
        // B = ys+xs
        string B = ys;
        B += xs;
        
        // 若A<B则返回true，否则返回false
        return A<B;
    }
    string PrintMinNumber(vector<int> numbers) {
        // 若传入的整型数组为空，返回空串
        if(numbers.size() == 0)    return "";
        // 按自定义的比较函数cmp进行排序
        sort(numbers.begin(), numbers.end(), cmp);
        string result;    // 定义结果
        // 遍历排序后的数组，将其元素转为字符串后加到result之后
        for(auto i = 0; i < numbers.size(); ++i)
        {
            result += to_string(numbers[i]);
        }
        return result;
    }
};