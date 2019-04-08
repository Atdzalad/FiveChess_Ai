#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<memory.h>

void Paint(void);      //绘制棋盘
void Judge(void);      //判断是否有一方获胜
void Ai(void);         //人机对战与双人
void Writeman(void);   //人类下棋
void Writeai(int a);   //ai下棋
int mark(void);         //评估函数   

int map[15][15];
int flag = 1;
int judgewin = 0;
int mode = 0;



int main(void)
{
	memset(map, 0, sizeof(map));
	printf_s("请选择模式：\n1、双人对战\n2、人机对战\n");
	scanf_s("%d", &mode);
	if (mode!=1&&mode!=2)
	{
		printf_s("请重新选择模式\n");
		scanf_s("%d", &mode);
	}
	system("CLS");
	while (flag)
	{
		Paint();
		Writeman();
		system("CLS");
		Paint();
		Judge();
		if (flag==0)
		{
			continue;;
		}
		Writeai(mode);
		system("CLS");
		Paint();
		Judge();
		if (flag == 0)
		{
			continue;;
		}
		system("CLS");
	}
	if (judgewin==1)
	{
		printf_s("P1 WIN\n");
	}
	else if(judgewin==2)
	{
		printf_s("P2 WIN\n");
	}
	system("pause");
	return 0;
}













void Paint(void)
{
	printf_s("输入样例：x y\n");
	for (int i = 1; i < 16; i++)
	{
		for (int j = 1; j < 16; j++)
		{
			if (map[i][j] == 0)
			{
				printf_s("·");
			}
			else if (map[i][j] == 1)
			{
				printf_s("●");
			}
			else if(map[i][j]==2)
			{
				printf_s("○");
			}
		}
		printf_s("\n");
	}

}



void Judge(void)
{
	for (int i=1;i<16;i++)
	{
		for (int j = 1; j < 16; j++)
		{
			if (map[i][j] == 2)
			{                 
				int line, row, left, right,line1, row1, left1, right1;
				line = row = left = right = line1=row1=left1=right1=0;
				//
				int temp = -4;
				while (temp <= 0)
				{
					if (map[i + temp][j] == 2)
					{
						line1++;
					}
					temp++;
				}
				temp--;
				while (temp <=4)
				{
					if (map[i + temp][j] == 2)
					{
						line++;
					}
					temp++;
				}
				if (line >= 5||line1>=5)
				{
					judgewin = 2;
					flag = 0;
				}
				//
				temp = -4;
				while (temp <= 0)
				{
					if (map[i][j + temp] == 2)
					{
						row1++;
					}
					temp++;
				}
				temp--;
				while (temp <=4)
				{
					if (map[i][j + temp] == 2)
					{
						row++;
					}
					temp++;
				}
				if (row >= 5||row1 >= 5)
				{
					judgewin = 2;
					flag = 0;
				}
				//
				temp = -4;
				while (temp <= 0)
				{
					if (map[i+temp][j + temp] == 2)
					{
						right1++;
					}
					temp++;
				}
				temp--;
				while (temp <= 4)
				{
					if (map[i + temp][j + temp] == 2)
					{
						right++;
					}
					temp++;
				}
				if(right>=5||right1>=5)
				{
					judgewin = 2;
					flag = 0;
				}
				//
				temp = -4;
				while (temp <= 0)
				{
					if (map[i+temp][j - temp] == 2)
					{
						left1++;
					}
					temp++;
				}
				temp--;
				while (temp <= 4)
				{
					if (map[i + temp][j - temp] == 2)
					{
						left++;
					}
					temp++;
				}
				if (left >= 5||left1 >= 5)
				{
					judgewin = 2;
					flag = 0;
				}

				
			}
			else if(map[i][j]==1)
			{
			
				int line, row, left, right, line1, row1, left1, right1;
				line = row = left = right = line1 = row1 = left1 = right1 = 0;
				//
				int temp = -4;
				while (temp <= 0)
				{
					if (map[i + temp][j] == 1)
					{
						line1++;
					}
					temp++;
				}
				temp--;
				while (temp <= 4)
				{
					if (map[i + temp][j] == 1)
					{
						line++;
					}
					temp++;
				}
				if (line >= 5 || line1 >= 5)
				{
					judgewin = 1;
					flag = 0;
				}
				//
				temp = -4;
				while (temp <= 0)
				{
					if (map[i][j + temp] == 1)
					{
						row1++;
					}
					temp++;
				}
				temp--;
				while (temp <= 4)
				{
					if (map[i][j + temp] == 1)
					{
						row++;
					}
					temp++;
				}
				if (row >= 5 || row1 >= 5)
				{
					judgewin = 1;
					flag = 0;
				}
				//
				temp = -4;
				while (temp <= 0)
				{
					if (map[i + temp][j + temp] == 1)
					{
						right1++;
					}
					temp++;
				}
				temp--;
				while (temp <= 4)
				{
					if (map[i + temp][j + temp] == 1)
					{
						right++;
					}
					temp++;
				}
				if (right >= 5 || right1 >= 5)
				{
					judgewin = 1;
					flag = 0;
				}
				//
				temp = -4;
				while (temp <= 0)
				{
					if (map[i + temp][j - temp] == 1)
					{
						left1++;
					}
					temp++;
				}
				temp--;
				while (temp <= 4)
				{
					if (map[i + temp][j - temp] == 1)
					{
						left++;
					}
					temp++;
				}
				if (left >= 5 || left1 >= 5)
				{
					judgewin = 1;
					flag = 0;
				}
			}
		}
	}
}




void Writeman(void)
{
	int x, y;
	scanf_s("%d %d", &x, &y);
	if (map[x][y]==0&&x<=15&&y<=15)
	{
		map[x][y] = 1;
	}
	else
	{
		do
		{
			printf_s("请重新落子\n");
			scanf_s("%d %d", &x, &y);
		} while (map[x][y]!=0||x>15||y>15);
		map[x][y] = 1;
	}

}

void Writeai(int mode)
{
	switch (mode)
	{
	case 1:
		int x, y;
		scanf_s("%d %d", &x, &y);
		if (map[x][y] == 0 && x <= 15 && y <= 15)
		{
			map[x][y] = 2;
		}
		else
		{
			do
			{
				printf_s("请重新落子\n");
				scanf_s("%d %d", &x, &y);
			} while (map[x][y] != 0 || x>15 || y>15);
			map[x][y] = 2;
		}
		break;
	case 2:
		Ai();
		break;
	default:
		break;
	}
}




void Ai(void)
{

}