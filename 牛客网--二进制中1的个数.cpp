https://www.nowcoder.com/practice/8ee967e43c2c4ec193b040ea7fbb10b8?
class Solution {
public:
     int  NumberOf1(int n) {
         //按位检测
         /*
         //首先判断n是不是负数，当n为负数的时候，直接用后面的while循环会导致死循环，因为负数
         //向左移位的话最高位补1,因此需要一点点特殊操作，可以将最高位的符号位1变成0，也就
         //是n&0x7FFFFFFF，这样就把负数转化成正数了，唯一差别就是最高位由1变成0，因为少了
         //一个1，所以count加1。之后再按照while循环里处理正数的方法来操作
         int count =0;
         if(n<0)
         {
             n=n&0x7FFFFFFF;
             count++;
         }
         while(n)
         {
             if(n & 1==1)
             {
                 ++count;
             }
             n=n>>1;
         }
         return count;
         */
         
         //避免无效检测，每次检测一位1
         int count=0;
         while(n)
         {
             n &= (n-1);
             ++count;
         }
         return count;
     }
};