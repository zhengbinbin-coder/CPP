https://www.nowcoder.com/practice/c6c7742f5ba7442aada113136ddea0c3?
class Solution {
private:
    unordered_map<int,int> filter;
public:
    int Fibonacci(int n) {
        
        //递归
        /*
        if(n==0)    return 0;
        if(n==1||n==2)    return 1;
        return Fibonacci(n-1)+Fibonacci(n-2);
        */
        
        //动态规划--迭代
        /*
        if(n==0)    return 0;
        if(n==1||n==2)    return 1;
        int f1=0;
        int f2=1;
        int ret=0;
        for(int i=2;i<=n;++i)
        {
            ret=f1+f2;
            f1=f2;
            f2=ret;
        }
        return ret;
        */
        
        //使用hashmap定义一个过滤器对斐波那契二叉树进行剪枝
        if(n==0||n==1)
        {
            return n;
        }

        int ppre=0;    //前前一个n-2
        if(filter.find(n-2)==filter.end())    //没找到前前一个
        {
            ppre=Fibonacci(n-2);
            filter.insert({n-2,ppre});
        }
        else    //找到了前前一个
        {
            ppre=filter[n-2];
        }

        int pre=0;    //前一个n-1
        if(filter.find(n-1)==filter.end())    //没找到前一个
        {
            pre=Fibonacci(n-1);
            filter.insert({n-1,pre});
        }
        else    //找到了前一个
        {
            pre=filter[n-1];
        }

        return pre+ppre;
    }
};