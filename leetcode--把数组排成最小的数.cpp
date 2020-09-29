https://leetcode-cn.com/problems/ba-shu-zu-pai-cheng-zui-xiao-de-shu-lcof/
class Solution {
public:
    // 自定义的比较函数
    static bool cmp(int x,int y)
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

    string minNumber(vector<int>& nums) {
        // 若传入的整型数组为空，返回空串
        if(nums.size() == 0)  return "";
        // 按自定义的比较函数cmp进行排序
        sort(nums.begin(), nums.end(), cmp);
        string result;      // 定义结果
        // 遍历排序后的数组，将其元素转为字符串后加到result之后
        for(auto i = 0; i < nums.size(); ++i)
        {
            result += to_string(nums[i]);
        }
        return result;
    }
};
