https://www.nowcoder.com/practice/72a5a919508a4251859fb2cfb987a0e6?
class Solution {
public:
    int rectCover(int number) {        //本质是斐波那契数列问题
        if(number==0)    return 0;
        if(number==1)    return 1;
        if(number==2)    return 2;
        //动态规划--定义三个变量迭代
        int first=1;
        int second=2;
        int third;
        for(int i=3;i<=number;++i)
        {
            third=first+second;
            first=second;
            second=third;
        }
        return third;
    }
};