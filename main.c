#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>
int buy_soda(int n)
{
	static int flag = 0;//定义静态变量flag
	//（兑换后剩余的空瓶数），保证递归后不会销毁数据。
	if (2 * n + flag < 2)//判断本次能否至少购买一瓶汽水
		return 0;
	if (n % 2 == 0)//偶数瓶瓶盖，全部兑换
		return n + buy_soda(n / 2);
	else if (n % 2 == 1 && flag == 0)//奇数瓶瓶盖，
		//且没有上次兑换的多余的剩瓶盖，则留下一个瓶盖，
		//剩下的全部兑换
	{
		flag = 1;
		return n + buy_soda(n / 2);
	}
	else if (n % 2 == 1 && flag == 1)//奇数瓶瓶盖，
		//且有上次兑换的多余剩的瓶盖，加上这个瓶盖一起兑换
	{
		flag = 0; //将之前剩余的空瓶用掉
		return n + buy_soda(n / 2 + 1);
	}
	return 0;
}
int main()
{
	int money = 0;
	printf("money=");
	scanf("%d", &money);
	printf("可以买 %d 瓶汽水\n", buy_soda(money));
	system("pause");
	return 0;
}
