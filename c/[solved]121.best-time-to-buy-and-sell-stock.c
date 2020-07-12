#include <stdio.h>

int maxProfit(int* prices, int pricesSize){
	if (pricesSize < 2) return 0;
	int i, maxProfit = 0;
	int nMinPrice = prices[0];
	for(i = 1;i < pricesSize;i++)
	{
		int this = prices[i] - nMinPrice;
		if (this > maxProfit) maxProfit = this;
		if (prices[i] < nMinPrice) nMinPrice = prices[i];
	}
	return maxProfit;
}

int main()
{
	int prices[] = {7,1,5,3,6,4};
	int maxProfit = maxProfit(prices, sizeof(prices)/sizeof(prices[0]));
	printf("%d\n", maxProfit);
	return 0;
}
