#include <stdio.h>
#include <stdlib.h>

//1.    O(n^3)
int main()
{
	int i = 0;
	int j = 0;
	int k = 0;
	for (i = 0; i <= 50; i++)
	{
		for (j = 0; j <= 50; j++)
		{
			for (k = 0; k <= 50; k++)
			{
				if ((i + j + k == 50 )&& (i + 2*j + 5*k == 100))
				{
					printf("%3d %3d %3d \n", i, j, k);
				}
			}
		}
	}
	system("pause");
	return 0;
}


//2.     O(n^2)
int main()
{
	int i = 0;
	int j = 0;
	int k = 0;
	for (i = 0; i <= 50; i++)
	{
		for (j = 0; j <= 50; j++)
		{
			k = 50 - i - j;
			if (i + 2 * j + 5 * k == 100)
				printf("%3d %3d %3d \n", i, j, k);
		}
	}
	system("pause");
	return 0;
}
