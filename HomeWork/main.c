#include "stdio.h"
#include "conio.h"
#include "string.h"

//初始化原始密码，定义字符数组
char password[7] = "hello", password0[7] = "张三";
char str[7] = "\0", str1[7];
char DisplayGUI(void);
void Login(void);
void ChangePIN(void);
main()
{
	start:
	switch (DisplayGUI() - '0')
	{
	case 1:Login(); break;
	case 2:ChangePIN(); break;
	case 3:exit(0); break;
	default:
		break;
	}
	system("cls");
	goto start;
	//输入密码	
}

char DisplayGUI(void)	//输出界面
{
	char Cache;
	printf("********************\n");
	printf("****个人账户管理*****\n");
	printf("********************\n\n");
	printf("********************\n");
	printf("****1-账户登录*******\n");
	printf("****2-修改密码*******\n");
	printf("****3-退出***********\n");
	printf("**请输入您要做的操作**\n\n");
	Cache = getch();
	printf("%c\n",Cache);
	return Cache;
}
void Login(void)
{
	int i;
again:
	printf("请输入密码：\n");
	i = 0;
	while ((str[i] = getch()) != '\r')			/*密码显示为* */
	{
		printf("*");
		i++;
	}
	str[i] = '\0';
	printf("\n");

	//判断密码
	if (strcmp(password, str) == 0)
		printf("密码正确！\n");
	else
	{
		printf("密码不正确！\n");
		goto again;
	}
}
void ChangePIN(void)
{
	//提示是否修改密码
snstart:
	printf("是否需要修改密码？Y/N\n");
	gets(str);
	if (strcmp(str, "Y") == 0)
	{
		//密码提示答案验证
		printf("请输入密码提示问题答案：\n我的姓名是：");
		gets(str);
		if (strcmp(str, password0) == 0)
		{
			printf("答案正确！\n");
			goto setsn;
		}
		else
		{
			printf("答案错误！\n");
			exit(0);
		}
		//修改密码
	setsn:
		printf("请输入新的6位数密码：");
		gets(str);
		printf("请再次输入6位数密码：");
		gets(str1);
		if (strcmp(str, str1) == 0)
		{
			printf("新密码设置成功！\n");
			strcpy(password, str1);
		}
		else
		{
			printf("两次输入的密码不同，请重新输入！\n");
			goto setsn;
		}
	}
	else if (strcmp(str, "N") == 0)
	{
		return;
	}
	else
	{
		printf("输入有误，请重新输入");
		goto snstart;
	}
}