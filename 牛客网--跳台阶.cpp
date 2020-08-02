https://www.nowcoder.com/practice/8c82a5b80378478f9484d87d1c5f12a4?
#include<unordered_map>
class Solution {
private:
    //使用哈希map对计算斐波那契数列时产生的二叉树进行剪枝
    unordered_map<int,int> m;
public:
    int jumpFloor(int number) {        //本质是斐波那契数列问题
        if(number==0||number==1)    return 1;
        //计算跳上前前一个台阶的方法数
        int ppre=0;
        if(m.find(number-2)==m.end())
        {
            ppre=jumpFloor(number-2);
            m.insert(make_pair(number-2,ppre));
        }
        else
        {
            ppre=m[number-2];
        }
        //计算跳上前一个台阶的方法数
        int pre=0;
        if(m.find(number-1)==m.end())
        {
            pre=jumpFloor(number-1);
            m.insert(make_pair(number-1,pre));
        }
        else
        {
            pre=m[number-1];
        }
        //总方法数=跳上前一个台阶的方法数+跳上前前一个台阶的方法数
        return pre+ppre;
    }
};