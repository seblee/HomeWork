#include "stdio.h"
#include "conio.h"
#include "string.h"
#include "stdlib.h"

//��ʼ��ԭʼ���룬�����ַ�����
char password[7] = "hello", password0[7] = "����";
char str[7] = "\0", str1[7];
char DisplayGUI(void);
void Login(void);
void ChangePIN(void);
int main(void)
{
	start:
	switch (DisplayGUI() - '0')
	{
	case 1:Login(); break;
	case 2:ChangePIN(); break;
	case 3:/*exit(0);*/goto exeend; break;
	default:
		break;
	}
	system("cls");
	goto start;
exeend:
	system("pause");
	//��������	
}

char DisplayGUI(void)	//�������
{
	char Cache;
	printf("**********************\n");
	printf("*****�����˻�����*****\n");
	printf("**********************\n\n");
	printf("**********************\n");
	printf("******1-�˻���¼******\n");
	printf("******2-�޸�����******\n");
	printf("******3-�˳�**********\n");
	printf("**��������Ҫ���Ĳ���**\n\n");
	Cache = getch();
	printf("%c\n",Cache);
	return Cache;
}
void Login(void)
{
	int i;
	char Cache;
again:
	printf("���������룺\n");
	i = 0;
	while ((str[i] = getch()) != '\r')			/*������ʾΪ* */
	{
		printf("*");
		i++;
	}
	str[i] = '\0';
	printf("\n");

	//�ж�����
	if (strcmp(password, str) == 0)
	{
		printf("������ȷ��\n");
		printf("�����������....");
		Cache = 0;
		i = 0;
		do
		{
			Cache = 0;
			i++;
		} while (((Cache = getch()) == '\r') && (i < 1));
	}
	else
	{
		printf("���벻��ȷ��\n");
		goto again;
	}
}
void ChangePIN(void)
{
	char Cache, i = 0;
	//��ʾ�Ƿ��޸�����
snstart:
	printf("�Ƿ���Ҫ�޸����룿Y/N\n");
	gets(str);
	if (strcmp(str, "Y") == 0)
	{
		//������ʾ����֤
		printf("������������ʾ����𰸣�\n�ҵ������ǣ�");
		gets(str);
		if (strcmp(str, password0) == 0)
		{
			printf("����ȷ��\n");
			goto setsn;
		}
		else
		{
			printf("�𰸴���\n");
			exit(0);
		}
		//�޸�����
	setsn:
		printf("�������µ�6λ�����룺");
		gets(str);
		printf("���ٴ�����6λ�����룺");
		gets(str1);
		if (strcmp(str, str1) == 0)
		{
			printf("���������óɹ���\n");
			strcpy(password, str1);
			printf("�����������....");
			do
			{
				Cache = 0;
				i++;
			} while (((Cache = getch()) == '\r') && (i < 1));
		}
		else
		{
			printf("������������벻ͬ�����������룡\n");
			goto setsn;
		}
	}
	else if (strcmp(str, "N") == 0)
	{
		return;
	}
	else
	{
		printf("������������������");
		goto snstart;
	}
}

