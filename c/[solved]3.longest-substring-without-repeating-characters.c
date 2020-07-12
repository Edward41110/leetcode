//¸¡¶¯´°¿Ú·¨
 
#include <stdio.h> 

int max(int a, int b)
{
	return a > b ? a : b;
}

int lengthOfLongestSubstring(char * s) {
	int location[127] = { 0 };
	int i, start = 0, ans = 0;
	for (i = 0;s[i] != '\0';i++)
	{
		if (location[(int)s[i]] >= start + 1)
			start = location[(int)s[i]];
		location[(int)s[i]] = i + 1;
		ans = max(i - start + 1, ans);
	}
	return ans;
}

int lengthOfLongestSubstring2(char * s){
	int start = 0, end = 0;
	int flag = 0, len = 0, MaxLen = 0;
	for(;s[end] != '\0';len++, end++)
	{
		int i = start;
		for(;i < end;i++)
		{
			if (s[i] == s[end])
			{
				flag = 1;
				start = i+1;
				break;
			}
		}
		if (flag == 1)
		{
			if (len > MaxLen)
			MaxLen = len;
			len = end - start;
			flag = 0;
		}
	}
	if (MaxLen < len) return len;
	return MaxLen;
}

int main()
{
	char s[] = "pwwkew";
	printf("%d\n", lengthOfLongestSubstring(s));
	getchar();
	return 0;
}

