#include <stdio.h> 
#include <stdlib.h>

char * intToRoman(int num){
	char *str = (char *)malloc(sizeof(char) * 20);
	int i = 0, j, k;
	j = num/1000;
	for(k = 0;k < j;k++)
		str[i++] = 'M';
	num %= 1000;
	
	j = num/900;
	for(k = 0;k < j;k++)
	{
		str[i++] = 'C';
		str[i++] = 'M';
	}
	num %= 900;
	
	j = num/500;
	for(k = 0;k < j;k++)
		str[i++] = 'D';
	num %= 500;
	
	j = num/400;
	for(k = 0;k < j;k++)
	{
		str[i++] = 'C';
		str[i++] = 'D';	
	}
	num %= 400;
	
	j = num/100;
	for(k = 0;k < j;k++)
		str[i++] = 'C';
	num %= 100;
	
	j = num/90;
	for(k = 0;k < j;k++)
	{
		str[i++] = 'X';
		str[i++] = 'C';	
	}
	num %= 90;
	
	j = num/50;
	for(k = 0;k < j;k++)
		str[i++] = 'L';
	num %= 50;
	
	j = num/40;
	for(k = 0;k < j;k++)
	{
		str[i++] = 'X';
		str[i++] = 'L';	
	}
	num %= 40;
	
	j = num/10;
	for(k = 0;k < j;k++)
		str[i++] = 'X';
	num %= 10;
	
	j = num/9;
	for(k = 0;k < j;k++)
	{
		str[i++] = 'I';
		str[i++] = 'X';	
	}
	num %= 9;
	
	j = num/5;
	for(k = 0;k < j;k++)
		str[i++] = 'V';
	num %= 5;
	
	j = num/4;
	for(k = 0;k < j;k++)
	{
		str[i++] = 'I';
		str[i++] = 'V';	
	}
	num %= 4;
	
	j = num;
	for(k = 0;k < j;k++)
		str[i++] = 'I';
	
	str[i] = '\0';
	return &str[0];
}

int main()
{
	char *str = intToRoman(58);
	puts(str);
	return 0;
}
