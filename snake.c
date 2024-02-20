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
	//ʳ���������
	do {
		food[0] = rand() % WIDE;
		food[1] = rand() % HIGH;
	} while (IsFoodOnSnake()); // ���ʳ���Ƿ����ߵ�������
}

int IsFoodOnSnake()
{
	for (int i = 0; i < snake.size; i++) {
		if (food[0] == snake.body[i].X && food[1] == snake.body[i].Y) {
			return 1; // ʳ�����ߵ�������
		}
	}
	return 0; // ʳ�ﲻ���ߵ�������
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
	//����ĩβ�ո�
	coord.X = lx;
	coord.Y = ly;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
	putchar(' ');
	//��ʾ�ߵ�λ��
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
		//��ʾʳ��λ��
		coord.X = food[0];
		coord.Y = food[1];
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
		putchar('#');
}

void PlayGame()
{
	//�ٶȿ���
	int Sleeptime = 200;
	int startscore = 10;

	char key = 'D';//��ʼ����
	while (snake.body[0].X >= 0 && snake.body[0].X < WIDE &&
		snake.body[0].Y >= 0 && snake.body[0].Y < HIGH)
	{
		InitWall();
		//��ʾ����
		ShowUI();
		//�������
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

		//�Ƿ��������ײ
		for (int i = 1; i < snake.size; i++)
		{
			if (snake.body[0].X == snake.body[i].X && snake.body[0].Y == snake.body[i].Y)
			{
				return;
			}
		}

		// ��Ϸ������ʵʱ��ʾ����
		COORD scoreCoord = { WIDE + 2, 0 }; // ���ù��λ��
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), scoreCoord);
		printf("Score: %d", score);

		//�ߺ�ʳ�����ײ
		if (snake.body[0].X == food[0] && snake.body[0].Y == food[1])
		{
			//�����ʳ��
			InitFood();
			snake.size++;
			//��������
			score += 10;
		}

		//�������ı�ʱ��
		if (score >= startscore && Sleeptime > 60 )
		{
			Sleeptime -= 50;
			startscore += 10;
		}
		//�����ߵ�����

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
	system("cls"); // �����Ļ
	printf("�˾Ͷ������䲻��ͱ���\n     ����: %d\n", score);
	if (score > highScore) {
		highScore = score;
		printf("    ��߷�: %d\n", highScore);
	}
	else {
		printf("    ��߷�: %d\n", highScore);
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
	printf("��Ҫ������ (Y/N): ");
	char choice;
	scanf(" %c", &choice);
	if (choice == 'Y' || choice == 'y') {
		system("cls");
		// ���³�ʼ����Ϸ������ PlayGame() ����
	// ���³�ʼ����Ϸ״̬
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

	//ȥ������̨���
	CONSOLE_CURSOR_INFO cci;
	cci.bVisible = FALSE;
	cci.dwSize = sizeof(cci);
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cci);

	do {
		// �����Ļ
		system("cls");
		InitFood();
		InitSnake();
		//ShowUI();
		PlayGame();
	} while (RestartGame() == 'Y' || RestartGame() == 'y');
	return EXIT_SUCCESS;
}

