#include <stdio.h> 

int maxArea(int* height, int heightSize) {
	int left = 0, right = heightSize-1, MaxArea = 0;
	while (left != right)
	{
		int area = (right - left) * (height[left] <= height[right] ? height[left] : height[right]);
		MaxArea = MaxArea >= area ? MaxArea : area;
		if (height[left] > height[right]) right--;
		else left++;
	}
	return MaxArea;
}

int main()
{
	int height[] = { 2,3,4,5,18,17,6 };
	printf("area = %d\n", maxArea(height, sizeof(height) / sizeof(height[0])));
	getchar();
	return 0;
}

