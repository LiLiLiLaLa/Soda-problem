#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>
int buy_soda(int n)
{
	static int flag = 0;//���徲̬����flag
	//���һ���ʣ��Ŀ�ƿ��������֤�ݹ�󲻻��������ݡ�
	if (2 * n + flag < 2)//�жϱ����ܷ����ٹ���һƿ��ˮ
		return 0;
	if (n % 2 == 0)//ż��ƿƿ�ǣ�ȫ���һ�
		return n + buy_soda(n / 2);
	else if (n % 2 == 1 && flag == 0)//����ƿƿ�ǣ�
		//��û���ϴζһ��Ķ����ʣƿ�ǣ�������һ��ƿ�ǣ�
		//ʣ�µ�ȫ���һ�
	{
		flag = 1;
		return n + buy_soda(n / 2);
	}
	else if (n % 2 == 1 && flag == 1)//����ƿƿ�ǣ�
		//�����ϴζһ��Ķ���ʣ��ƿ�ǣ��������ƿ��һ��һ�
	{
		flag = 0; //��֮ǰʣ��Ŀ�ƿ�õ�
		return n + buy_soda(n / 2 + 1);
	}
	return 0;
}
int main()
{
	int money = 0;
	printf("money=");
	scanf("%d", &money);
	printf("������ %d ƿ��ˮ\n", buy_soda(money));
	system("pause");
	return 0;
}
