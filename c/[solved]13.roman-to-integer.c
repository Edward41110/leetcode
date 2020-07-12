#include<stdio.h> 

int returnValue(char ch)
{
	if (ch == 'M') return 1000;
	else if(ch == 'D') return 500;
	else if(ch == 'C') return 100;
	else if(ch == 'L') return 50;
	else if(ch == 'X') return 10;
	else if(ch == 'V') return 5;
	else if(ch == 'I') return 1;
	return 0;
}

int romanToInt(char * s){
	int digit, ret = 0;
	int i;
	for(i = 0;s[i] != '\0';i++)
	{
		if (s[i+1] == '\0' || returnValue(s[i]) >= returnValue(s[i+1]))
			digit += returnValue(s[i]);
		else
		{
			digit = returnValue(s[i+1]) - returnValue(s[i]);
			i++;
		}
		ret += digit;
		digit = 0;
	}
	return ret;
}

int romanToInt2(char * s)
{
	int i, ret = 0;
	for(i = 0;s[i] != '\0';i++)
	{
		if (s[i+1] == '\0')
			ret += returnValue(s[i]);
		else
		{
			if(s[i] == 'I' && s[i+1] == 'V') { ret += 4; i++;}
			else if(s[i] == 'I' && s[i+1] == 'X') { ret += 9; i++;}
			else if(s[i] == 'X' && s[i+1] == 'L') { ret += 40; i++;}
			else if(s[i] == 'X' && s[i+1] == 'C') { ret += 90; i++;}
			else if(s[i] == 'C' && s[i+1] == 'D') { ret += 400; i++;}
			else if(s[i] == 'C' && s[i+1] == 'M') { ret += 900; i++;}
			else ret += returnValue(s[i]);
		}
	}
	return ret;
}

int main()
{
	char *s = "IV"; 
	int result = romanToInt(s);
	printf("%d\n", result);
	return 0;
}
