https://www.nowcoder.com/practice/fbcf95ed620f42a88be24eb2cd57ec54?
class Gift {
public:
    int getValue(vector<int> gifts, int n) {
        // write code here
		// 找出数组中超过一半的元素
        sort(gifts.begin(),gifts.end());
        int ret = gifts[gifts.size()/2];
        int count =0;
        for(auto e : gifts)
        {
            if( e == ret )
            {
                ++count;
            }
        }
        if(count > gifts.size()/2)    return ret;
        return 0;
    }
};