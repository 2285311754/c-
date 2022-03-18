#include<stdio.h>
#include<windows.h>
#include<conio.h>
#define ROW 9
#define COL 11
char map[ROW][COL+1]={
        {"*#*********"},
		{"***###*###*"},
		{"###**#****#"},
		{"*#**###**#*"},
		{"***********"},
        {"#####*##*##"},
		{"**#*****#*E"},
		{"***#*###**#"},
		{"*#*********"},
};

void print_map()
{
	int i;
	for(i = 0;i < ROW;i++)
	{
		puts(map[i]);
	}
}

void show_cursor(int x,int y)
{
	COORD pos;
	pos.X=x;
	pos.Y=y;
	printf("curX=%d,curY=%d\n",x,y);
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),pos);
}
char z;
int a;
int curX,curY;
int main()
{
	printf("�밴�Թ��߳�ȥ������Ϊw����Ϊs���a�ұ�d,�������뷨���״̬����wsad\n");
	printf("׼�������밴1��ʼ");
	scanf("%d",&a);
	if(a == 1 )
	{
		while(1)
		{
			system("cls");
			print_map();
			show_cursor(curX,curY);		
			z =	getch();
			if(z == 'w')
			{
				if((curY-1)>=0&&(map[curY-1][curX]=='*'||map[curY-1][curX]=='E')) curY--;
			}
			else if(z == 's')
			{
				if((curY+1)<ROW&&(map[curY+1][curX]=='*'||map[curY+1][curX]=='E')) curY++;
			
			}
			else if(z == 'a')
			{
				if((curX-1)>=0&&(map[curY][curX-1]=='*'||map[curY][curX-1]=='E')) curX--;
			}
			else if(z == 'd')
			{
				if((curX+1)<COL&&(map[curY][curX+1]=='*'||map[curY][curX+1]=='E'))curX++;
			}
			if(map[curY][curX]=='E')
			{   
			    printf("���ӳ��˻ĵ���\t");
				break;
			}
		}
	}
	else if(a != 1)
	{
		printf("��淶����\n");
	}
	return 0;
}
