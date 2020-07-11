class Solution {
public:
    string replaceSpace(string s) {
        //若s大小为0，则直接返回
        if(s.length()==0)   return s;

        //计算s长度和空格个数
        int len=s.size()-1;
        int space=0;
        for(auto c:s)
        {
            if(c==' ')  ++space;
        }

        //计算新字符串长度
        int newlen=len+space*2;

        //若新长度和原长度相同，则说明原字符串中没有空格，直接返回
        if(newlen==len)   return s;

        //给新字符串扩容并初始化为空格
        s+=string(space*2,' ');


        //将s和%20拷贝到新字符串中
        while(len>=0 && newlen>len)
        {
            if(s[len]==' ')
            {
                s[newlen--]='0';
                s[newlen--]='2';
                s[newlen--]='%';
            }
            else
            {
                s[newlen--]=s[len];
            }
            --len;
        }
        return s;
    }
};
