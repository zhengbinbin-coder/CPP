//https://www.nowcoder.com/questionTerminal/b0850698cb41449188344cdb647f3e99
class Replacement {
public:
    string replaceSpace(string iniString, int length) {
        // write code here
        //计算空格个数
        int space=0;
        for(auto e:iniString)
        {
            if(e==' ')    ++space;
        }
        //将长度-1变成数组下标
        length-=1;
        //计算新字符串长度
        int newlen=length+space*2;
        //若新字符串长度==原字符串长度，说明源字符串没有空格，直接返回原字符串
        if(newlen==length)    return iniString;
        //给新字符串扩容并初始化为空格
        iniString+=string(space*2,' ');
        //将原字符串和%20拷贝到新字符串中
        while(length>=0 && newlen>length)
        {
            if(iniString[length]==' ')
            {
                iniString[newlen--]='0';
                iniString[newlen--]='2';
                iniString[newlen--]='%';
            }
            else
            {
                iniString[newlen--]=iniString[length];
            }
            --length;
        }
        return iniString;
    }
};