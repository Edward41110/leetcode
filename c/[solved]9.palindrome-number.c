#include<stdio.h>
#include<stdbool.h> 

bool isPalindrome(int x){
	if (x < 0 || (x % 10 == 0 && x != 0)) return false;
	int revertedNumber = 0;
    while(x > revertedNumber) {
        revertedNumber = revertedNumber * 10 + x % 10;
        x /= 10;
    }
	return x == revertedNumber || x == revertedNumber / 10;
}

int main()
{
	bool flag = isPalindrome(12321);
	printf("%d\n",flag);
	return 0;
}
