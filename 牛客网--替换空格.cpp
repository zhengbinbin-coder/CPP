// https://www.nowcoder.com/practice/4060ac7e3e404ad1a894ef3e17650423?
class Solution {
public:
	void replaceSpace(char *str,int length) {
        //计算空格个数
        int space=0;
        char* start = str;
        while(*start)
        {
            if(isspace(*start))    ++space;
            ++start;
        }
        //计算原字符串的尾和新字符串的尾
        char* old_end = str + length;
        char* new_end = str + length + space*2;
        //替换空格
        while(old_end >= str && new_end >= str)
        {
            //将非空格的字符挪动到指定位置
            if(!isspace(*old_end))
            {
                *new_end=*old_end;
                new_end--;
                old_end--;
            }
            //将空格替换为20%
            else
            {
                *new_end--='0';
                *new_end--='2';
                *new_end--='%';
                old_end--;
            }
        }
	}
};