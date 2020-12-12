https://www.nowcoder.com/practice/5a304c109a544aef9b583dce23f5f5db?tpId
#include<iostream>
#include<vector>

using namespace std;

// 求连续子数组的最大和
int MaxSum(vector<int>& v)
{
    vector<int> sum(v.size());
    sum[0]=v[0];
    int maxSum=sum[0];
    for(int i = 1; i<sum.size();++i)
    {
        sum[i]= sum[i-1]>0? sum[i-1]+v[i]:v[i];
        maxSum = sum[i]>maxSum? sum[i]:maxSum;
    }
    return maxSum;
}

int main()
{
    int n;
    while(cin >>n)
    {
        vector<int> v;
        v.resize(n);
        for(int i = 0; i<n;++i)
        {
            cin>>v[i];
        }
        cout<< MaxSum(v)<<endl;
    }
    return 0;
}