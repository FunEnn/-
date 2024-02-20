#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<time.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
#include<Windows.h>
#include"snack.h"

int highScore = 0;
int score1 = 0;

void InitFood()
{
	srand((size_t)time(NULL));
	//食物随机产生
	do {
		food[0] = rand() % WIDE;
		food[1] = rand() % HIGH;
	} while (IsFoodOnSnake()); // 检查食物是否在蛇的身体上
}

int IsFoodOnSnake()
{
	for (int i = 0; i < snake.size; i++) {
		if (food[0] == snake.body[i].X && food[1] == snake.body[i].Y) {
			return 1; // 食物在蛇的身体上
		}
	}
	return 0; // 食物不在蛇的身体上
}

void InitSnake()
{
	snake.size = 2;

	snake.body[0].X = WIDE / 2;
	snake.body[0].Y = HIGH / 2;

	snake.body[1].X = WIDE / 2 - 1;
	snake.body[1].Y = HIGH / 2;
}

void ShowUI()
{
	COORD coord;
	//更新末尾空格
	coord.X = lx;
	coord.Y = ly;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
	putchar(' ');
	//显示蛇的位置
	for (int i = 0; i < snake.size; i++)
	{
		coord.X = snake.body[i].X;
		coord.Y = snake.body[i].Y;
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
		if (i == 0)
			putchar('0');
		else
			putchar('*');
	}
		//显示食物位置
		coord.X = food[0];
		coord.Y = food[1];
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
		putchar('#');
}

void PlayGame()
{
	//速度控制
	int Sleeptime = 200;
	int startscore = 10;

	char key = 'D';//开始方向
	while (snake.body[0].X >= 0 && snake.body[0].X < WIDE &&
		snake.body[0].Y >= 0 && snake.body[0].Y < HIGH)
	{
		InitWall();
		//显示界面
		ShowUI();
		//方向控制
		while (_kbhit())
		{
			key = _getch();
		}
		switch (key)
		{
		case 'D': case 'd': dx = 1; dy = 0; break;
		case 'A': case 'a': dx = -1; dy = 0; break;
		case 'W': case 'w': dx = 0; dy = -1; break;
		case 'S': case 's': dx = 0; dy = 1; break;
		}

		//是否和自身碰撞
		for (int i = 1; i < snake.size; i++)
		{
			if (snake.body[0].X == snake.body[i].X && snake.body[0].Y == snake.body[i].Y)
			{
				return;
			}
		}

		// 游戏进行中实时显示分数
		COORD scoreCoord = { WIDE + 2, 0 }; // 设置光标位置
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), scoreCoord);
		printf("Score: %d", score);

		//蛇和食物的碰撞
		if (snake.body[0].X == food[0] && snake.body[0].Y == food[1])
		{
			//随机新食物
			InitFood();
			snake.size++;
			//分数增长
			score += 10;
		}

		//分数来改变时间
		if (score >= startscore && Sleeptime > 60 )
		{
			Sleeptime -= 50;
			startscore += 10;
		}
		//更新蛇的坐标

		lx = snake.body[snake.size - 1].X;
		ly = snake.body[snake.size - 1].Y;
			for (int i = snake.size - 1; i > 0; i--)
		{
			snake.body[i].X = snake.body[i - 1].X;
			snake.body[i].Y = snake.body[i - 1].Y;
		}
		snake.body[0].X += dx;
		snake.body[0].Y += dy;

		Sleep(Sleeptime);
		ClearScreen();
	}
	system("cls"); // 清空屏幕
	printf("菜就多练，输不起就别玩\n     分数: %d\n", score);
	if (score > highScore) {
		highScore = score;
		printf("    最高分: %d\n", highScore);
	}
	else {
		printf("    最高分: %d\n", highScore);
	}
}

void InitWall()
{
	for (int i = 0; i < HIGH; i++) {
		for (int j = 0; j < WIDE; j++)
		{
			if (i == HIGH - 1)
				putchar('=');
			else if (j == WIDE - 1)
				putchar('=');
			else
				putchar(' ');
		}
		putchar('\n');
	}
}
void ClearScreen()
{
	COORD coord = { 0, 0 };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}
char RestartGame()
{
	printf("你要重来吗？ (Y/N): ");
	char choice;
	scanf(" %c", &choice);
	if (choice == 'Y' || choice == 'y') {
		system("cls");
		// 重新初始化游戏并调用 PlayGame() 函数
	// 重新初始化游戏状态
		InitFood();
		InitSnake();
		score = 0;
		dx = 0;
		dy = 0;
		lx = 0;
		ly = 0;
		PlayGame();
	}
	return choice;
}
int main()
{
	srand((size_t)time(NULL));

	//去掉控制台光标
	CONSOLE_CURSOR_INFO cci;
	cci.bVisible = FALSE;
	cci.dwSize = sizeof(cci);
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cci);

	do {
		// 清空屏幕
		system("cls");
		InitFood();
		InitSnake();
		//ShowUI();
		PlayGame();
	} while (RestartGame() == 'Y' || RestartGame() == 'y');
	return EXIT_SUCCESS;
}

