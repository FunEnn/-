#pragma once
#define WIDE 30
#define HIGH 20

struct BODY
{
	int X;
	int Y;
};
struct SNAKE
{
	int size;
	struct BODY body[WIDE * HIGH];
}snake;

int food[2] = { 0 };//food[0]为X坐标，food[1]为Y坐标

int score = 0;
//偏移坐标
int dx = 0;
int dy = 0;
//记录蛇末尾坐标
int lx = 0;
int ly = 0;
void InitFood();
int IsFoodOnSnake();
void InitSnake();
void ShowUI();
void PlayGame();
void InitWall();
void ClearScreen();
void RestartGame(); 
extern int highScore;
extern int score1;
