#include <stdio.h> 

int myAtoi(char * str) {
	int max = 0x7fffffff, min = 0x80000000;
	int i, digit, negativeFlag = 1;
	double num = 0;
	for (i = 0;str[i] != '\0';i++)
	{
		if (str[i] == ' ') continue;
		else if (str[i] == '+' || str[i] == '-' || (str[i] >= '0' && str[i] <= '9'))
		{
			if (str[i] == '+') i++;
			else if (str[i] == '-')
			{
				i++;
				negativeFlag = -1;
			}
			while (str[i] != '\0')
			{
				int cnt = 0;
				if (str[i] >= '0' && str[i] <= '9')
				{
					digit = str[i] - '0';
					num = num * 10 + digit;
					i++, cnt++;
					if (cnt > 10) break;
				}
				else break;
			}
		}
		num *= negativeFlag;
		if (num > max) return max;
		else if (num < min) return min;
		else return (int)num;
	}
	return 0;
}

int main()
{
	char str[] = "+1";
	printf("digit = %d\n", myAtoi(str));
	return 0;
}
