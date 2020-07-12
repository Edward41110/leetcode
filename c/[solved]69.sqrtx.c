#include <stdio.h> 

float InvSqrt(float x)
{
    float xhalf = 0.5f*x;
    int i = *(int*)&x; // get bits for floating VALUE
    i = 0x5f375a86 - (i>>1); // gives initial guess y0
    x = *(float*)&i; // convert bits BACK to float
    x = x*(1.5f-xhalf*x*x); // Newton step, repeating increases accuracy
    x = x*(1.5f-xhalf*x*x); // Newton step, repeating increases accuracy
    x = x*(1.5f-xhalf*x*x); // Newton step, repeating increases accuracy
    return (int)(1/x);
}

long long s;

double mathlab(int i)
{
    long long res = ( i + (s / i)) / 2.0;
    if (res * res <= s && (res + 1) * (res + 1) > s) return res;
    else return mathlab(res);
}

int mySqrt(int x){
    s = x;
    if (x == 0) return x;
    else return (int)mathlab(x);
}

int main()
{
	printf("%d\n", mySqrt(2147395599));
	return 0;
}

