#include<stdio.h>
#include<string.h>
int times(char s[],char w[])
{
	int i=0,j,times=0;
	while(s[i])
	{
		j=0;
		while(w[j])
		{
			if(w[j]!=s[i+j])
				break;
			j++;
		}
		if(!w[j])
		{
			times++;
			i+=j-1;
		}
		i++;
	}
	return times;
}
int main()
{
	char s[10000]="";
	printf("请输入:\n");
	gets(s);
	char w[10]="";
	printf("请输入要查询的单词:\n");
	gets(w);
	printf("该单词出现的次数是%d\n",times(strlwr(s),w));
	return 0;
}