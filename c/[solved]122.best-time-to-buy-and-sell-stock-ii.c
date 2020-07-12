#include <stdio.h> 
#include <stdbool.h>

int maxProfit(int* prices, int pricesSize){
	if (pricesSize < 2) return 0;
	bool has = false;
	int i, buyPrice, sum = 0;
	for(i = 0;i < pricesSize - 1;i++)
	{
		if (has)
			if (prices[i] < prices[i + 1]) continue;
			else
			{
				sum += prices[i] - buyPrice;
				has = false;
			}
		else
			if (prices[i] > prices[i + 1]) continue;
			else
			{
				buyPrice = prices[i];
				has = true;
			}
	}
	if (has && prices[i] > buyPrice)
		sum += prices[i] - buyPrice;
	return sum; 
}

int main()
{
	int prices[] = {7, 1, 5, 3, 6, 4};
	int sum = maxProfit(prices, sizeof(prices)/sizeof(prices[0]));
	printf("%d\n", sum);
	return 0;
}
