// Project Euler 2019
// Vinicius Rodrigues 21.10.2019
// Coin Sums : Problem 31

#include <iostream>

using namespace std;

int range = 8;
int coins[] = {1, 2, 5, 10, 20, 50, 100, 200};

int countCoins(int num, int coin)
{
	int count = 0;
	if(coin == -1)
		for(int i = 0; i < range; i++)
			count += countCoins(num, i);
	else
	{
		num -= coins[coin];
		if(num == 0) return 1;
		else if(num < 0) return 0;

		for(int i = coin; i < range; i++)
			count += countCoins(num, i);
	}

	return count;
}

int main()
{
	int count = countCoins(200, -1);
	cout << count << endl;
}
