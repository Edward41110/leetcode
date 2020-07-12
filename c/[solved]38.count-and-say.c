#include <stdio.h>
#include <stdlib.h>

char* OnceCAS(char *src, char *dst)
{
	int i = 0, j = 0;
	char ch = src[0];
	int cnt = '1';
	while (src[i] != '\0')
	{
		if (src[i + 1] != '\0' && src[i + 1] == ch)
			i++, cnt++;
		else
		{
			dst[j++] = cnt;
			dst[j++] = ch;
			i++;
			ch = src[i];
			cnt = '1';
		}
	}
	dst[j] = '\0';
	return dst;
}

char* countAndSay(int n) {
	char *str1 = (char*)malloc(sizeof(char) * 4500);
	char *str2 = (char*)malloc(sizeof(char) * 4500);
	str1[0] = '1';
	str1[1] = '\0';
	int i;
	for (i = 0;i < n;i++)
		if (i % 2) OnceCAS(str2, str1);
		else OnceCAS(str1, str2);
	if (i % 2)
	{
		free(str1);
		return str2;
	}
	else
	{
		free(str2);
		return str1;
	}
}

int main()
{
	puts(countAndSay(4));
	getchar();
	return 0;
}
