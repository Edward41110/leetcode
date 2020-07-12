#include <stdio.h> 

int climbStairs(int n){
	if ( n == 0 ) return 0;
	if ( n == 1 ) return 1;
	int a1 = 1, a2 = 1, cnt;
	for (cnt = 1;cnt < n;cnt++)
		if (a1 > a2) a2 = a1 + a2;
		else a1 = a1 + a2;
	return a1>a2?a1:a2;
}

int main()
{
	FILE *fp = fopen("70.climbing-stairs.c","w");
	fprintf(fp, "int climbStairs(int n){\n\tint result = 0;\n\tswitch (n){\n");
	int i;
	for (i = 0;i < 47;i++)
		fprintf(fp, "\t\tcase %d: result = %d; break;\n", i, climbStairs(i));
	fprintf(fp, "\t}\n\treturn result;\n}");
	fclose(fp);
	return 0;
}

