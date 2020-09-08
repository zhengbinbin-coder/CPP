#include<iostream>
#include<string>​
using namespace std;
​int main()
{    
	string s1,s2;    
	while(cin>>s1>>s2)    
	{        
		if(s1.size()==s2.size())        
		{            
			for(int i=0;i<s1.size();++i)            
			{                
				if((0<=s1[i]&&s1[i]<=9)||('a'<=s1[i]&&s1[i]<='z')||('A'<=s1[i]&&s1[i]<='Z'))                
				{                    
				s[i]=1;                
				}                
				else    s[i]=0;            
			}            
			double count = 0;            
			for(int j=0;j<s1.size();++j)            
			{                
				if(s1[i]==s2[i])    count++;            
			}            
			double ret = count/(double)s1.size()*100;            
			printf("%.2lf%",ret);        
		}    
	}    
	return 0;
}







#include<iostream>
#include<string>

using namespace std;
int main()
{    
	string s1,s2;  
	while(cin>>s1>>s2)    
	{        
		if(s1.size()==s2.size())        
		{     
			double count = 0;
			for(int i=0;i<s1.size();++i)            
			{                
				if(('0'<=s1[i]&&s1[i]<='9')||('a'<=s1[i]&&s1[i]<='z')||('A'<=s1[i]&&s1[i]<='Z'))                
				{                    
					s1[i]='1';                
				}                
				else    s1[i]='0';            
			}                        
			for(int j=0;j<s1.size();++j)            
			{                
				if(s1[j]==s2[j])    count++;            
			}            
			double ret = count*100/(double)s1.size();            
			printf("%.2lf%%",ret);        
		}    
	}    
	return 0;
}











