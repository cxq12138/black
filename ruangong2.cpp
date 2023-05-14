
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

using namespace std;

int tishu = 1;//题目数量
int fuhaoshu = 1;//符号种类数
char symbo[5] = { 0 };//符号种类
int max_num = 1;//最大数
int kuohao = 0;//是否有括号（1表示有括号，0表示没有括号）
int xiaoshu = 0;//是否有小数（1表示有小数，0表示没有小数）
int Print = 0;//用户选择输出方式（1表示输出到文件，0表示输出屏幕）
float number[5] = { 0 };//使用的数字,默认为0
char symbol[5] = { 0 };//使用的符号

void menu(void)//主菜单界面
{
	printf(" 四则运算习题自动生成器\n");
	printf("\n");
	printf("请按提示设置练习题类型\n");
}
void randomnumber(void)//随机产生数字
{
	for (int i = 0; i < 4; i++)
	{
		if (xiaoshu == 0)//随机产生整数
		{
			number[i] = rand() % (max_num + 1);
		}
		else//随机产生小数
		{
			number[i] = rand() % max_num;
			number[i] = number[i] + rand() % 100 * 0.01;
		}
	}
}

void randomsymbol(void)//随机产生符号
{
	for (int i = 0; i < 3; i++)
	{
		symbol[i] = symbo[rand() % fuhaoshu];
	}
}

void shuchu(void)//输出函数
{
	int kuohaoweizhi;//括号位置
	FILE* fp;
	fp = fopen("四则运算", "w");//打开文件写操作
	for (int m = 0; m < tishu; m++)
	{
		randomnumber();//随机产生数字
		randomsymbol();//随机产生符号
		for (int i = 0; i < 3; i++)
		{
			if ((symbol[i] == '/') && (number[i + 1] == 0))
			{
				number[i + 1] = number[i + 1] + 1;
			}
		}
		if (xiaoshu == 0)//不是小数
		{
			if (Print == 0)//输出到屏幕
			{
				if (kuohao == 0)//没有括号
				{
					printf("%.0f%c%.0f%c%.0f%c%.0f=\n", number[0], symbol[0], number[1], symbol[1], number[2], symbol[2], number[3]);
				}
				else//有括号
				{
					kuohaoweizhi = rand() % 3;
					if (kuohaoweizhi == 0)//括号在第一个数和第二个数上
					{
						printf("（%.0f%c%.0f）%c%.0f%c%.0f=\n", number[0], symbol[0], number[1], symbol[1], number[2], symbol[2], number[3]);
					}
					if (kuohaoweizhi == 1)//括号在第二个数和第三个数上
					{
						printf("%.0f%c(%.0f%c%.0f)%c%.0f=\n", number[0], symbol[0], number[1], symbol[1], number[2], symbol[2], number[3]);
					}
					if (kuohaoweizhi == 2)//括号在第三个数和第四个数上
					{
						printf("%.0f%c%.0f%c(%.0f%c%.0f)=\n", number[0], symbol[0], number[1], symbol[1], number[2], symbol[2], number[3]);
					}
				}
			}
			else//输出到文件
			{
				if (kuohao == 0)//没有括号
				{
					fprintf(fp, "%.0f%c%.0f%c%.0f%c%.0f=\n", number[0], symbol[0], number[1], symbol[1], number[2], symbol[2], number[3]);
				}
				else//有括号
				{
					kuohaoweizhi = rand() % 3;
					if (kuohaoweizhi == 0)
					{
						fprintf(fp, "（%.0f%c%.0f）%c%.0f%c%.0f=\n", number[0], symbol[0], number[1], symbol[1], number[2], symbol[2], number[3]);
					}
					if (kuohaoweizhi == 1)
					{
						fprintf(fp, "%.0f%c(%.0f%c%.0f)%c%.0f=\n", number[0], symbol[0], number[1], symbol[1], number[2], symbol[2], number[3]);
					}
					if (kuohaoweizhi == 2)
					{
						fprintf(fp, "%.0f%c%.0f%c(%.0f%c%.0f)=\n", number[0], symbol[0], number[1], symbol[1], number[2], symbol[2], number[3]);
					}
				}
			}
		}
		else//是小数
		{
			if (Print == 0)//输出到屏幕
			{
				if (kuohao == 0)//没有括号
				{
					printf("%.2f%c%.2f%c%.2f%c%.2f=\n", number[0], symbol[0], number[1], symbol[1], number[2], symbol[2], number[3]);
				}
				else//有括号
				{
					kuohaoweizhi = rand() % 3;
					if (kuohaoweizhi == 0)
					{
						printf("（%.2f%c%.2f）%c%.2f%c%.2f=\n", number[0], symbol[0], number[1], symbol[1], number[2], symbol[2], number[3]);
					}
					if (kuohaoweizhi == 1)
					{
						printf("%.2f%c(%.2f%c%.2f)%c%.2f=\n", number[0], symbol[0], number[1], symbol[1], number[2], symbol[2], number[3]);
					}
					if (kuohaoweizhi == 2)
					{
						printf("%.2f%c%.2f%c(%.2f%c%.2f)=\n", number[0], symbol[0], number[1], symbol[1], number[2], symbol[2], number[3]);
					}
				}
			}
			else//输出到文件
			{
				if (kuohao == 0)//没有括号
				{
					fprintf(fp, "%.2f%c%.2f%c%.2f%c%.2f=\n", number[0], symbol[0], number[1], symbol[1], number[2], symbol[2], number[3]);
				}
				else//有括号
				{
					kuohaoweizhi = rand() % 3;
					if (kuohaoweizhi == 0)
					{
						fprintf(fp, "（%.2f%c%.2f）%c%.2f%c%.2f=\n", number[0], symbol[0], number[1], symbol[1], number[2], symbol[2], number[3]);
					}
					if (kuohaoweizhi == 1)
					{
						fprintf(fp, "%.2f%c(%.2f%c%.2f)%c%.2f=\n", number[0], symbol[0], number[1], symbol[1], number[2], symbol[2], number[3]);
					}
					if (kuohaoweizhi == 2)
					{
						fprintf(fp, "%.2f%c%.2f%c(%.2f%c%.2f)=\n", number[0], symbol[0], number[1], symbol[1], number[2], symbol[2], number[3]);
					}
				}
			}
		}
	}
	fclose(fp);//关闭文件
}

void shezhi()
{
	printf("请设置题目数量\n");
	scanf("%d", &tishu);
	if (tishu <= 0)
	{
		printf("请重新设置题目数量\n");
		scanf("%d", &tishu);
	}
	printf("请设置运算符种类数(1~4之间的整数)\n");
	scanf("%d", &fuhaoshu);
	if ((fuhaoshu < 1) || (fuhaoshu > 4))
	{
		printf("请重新设置运算符种类数(1~4之间的整数)\n");
		scanf("%d", &fuhaoshu);
	}
	printf("请连续输入使用的运算符（在“+”，“-”，“*”，“/”中选择输入）\n");
	scanf("%s", symbo);
	printf("请设置最大数\n");
	scanf("%d", &max_num);
	if (max_num <= 0)
	{
		printf("请重新设置最大数（正整数）\n");
		scanf("%d", &max_num);
	}
	printf("请选择是否有括号（0表示没有括号，1表示有括号）\n");
	scanf("%d", &kuohao);
	printf("请选择是否有小数（0表示没有小数，1表示有小数）\n");
	scanf("%d", &xiaoshu);
	printf("请选择输出方式（0表示输出到屏幕，1表示输出到文件）\n");
	scanf("%d", &Print);
}

int main()
{
	menu();//主菜单界面
	shezhi();//参数设置
	srand((int)time(0));//保证每次产生的随机数不同
	shuchu();//输出函数
	system("pause");
	return 0;
}
