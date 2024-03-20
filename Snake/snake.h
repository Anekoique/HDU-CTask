#include<stdio.h>
#include<Windows.h>
#include<conio.h>
#include<time.h>
#define MAP_WIDTH 100
#define MAP_HEIGHT 30
#define UP 'w'
#define DOWN 's'
#define LEFT 'a'
#define RIGHT 'd'

typedef struct {
	int x;
	int y;
}Food, Snakenode, Obstacle;
typedef struct {
	Snakenode snakeNode[1000];
	int length;
	int speed;

}Snake;

typedef struct record    //��¼
{
	int fraction;        //����z
	int hour;
	int min;
	int sec;
	int year;
	int mon;
	int day;
}record;

void GotoXY(int, int);
void Hide();
int Menu();
void Help();
void About();
void InitMap();
void PrintFood();
void PrintObstacle();
int MoveSnake();
int IsCorrect();
void SpeedControl();
void Recordeddata();   //����ɼ�
void Rankinglist();   //���а�
int Cmpfunc(const void* a, const void* b);