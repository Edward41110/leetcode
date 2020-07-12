#include <stdio.h>

int lengthOfLastWord(char * s) {
	int i,length = 0;
	for (i = 0;s[i] != '\0';i++)
		if (s[i] != ' ')
		{
			length = 0;
			while (s[i] != '\0' && s[i] != ' ')
				length++, i++;
            if(s[i] == '\0') break;
		}
	return length;
}

int main()
{
	char str[] = "Hello World ldtrfhj  sdha sa   vfyuo   ";
	printf("%d", lengthOfLastWord(str));
	return 0;
}
