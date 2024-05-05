#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<time.h>
#define SIZE 150             // ���ݼ���С
#define TRAIN_RATE 0.8       // ѵ��������
#// define K 68

typedef struct {             // �ṹ�����β������
	double feature[4];
	int species;
}Iris;
typedef struct {             // �ṹ���Ų��Լ���ѵ��������ľ���
	double distance;
	int species;
}Dis;

int readTxt(Iris*);          // ��ȡ���ݼ� 
void preProcess(Iris*);      // ���ݼ�Ԥ����
void getMinMax(Iris*, double*, double*);       // �ҵ������������Сֵ   
void MinMaxScalar(Iris*, double*, double*);    // ��׼��
void shuffleData(Iris*);      // ����������ݼ�
void splitData(Iris*, Iris*, Iris*);      // �������ݼ�
void swap(Iris*, Iris*);      // ��������
void swap(Dis*, Dis*);        // ����Ľ�������
void quickSort(Dis*, int, int);   // �Ե�ÿһ��ѵ�����ľ�������
void predict(Iris*, Iris*, int);     // �����㷨
void getRank(Dis*, Iris*, Iris*, int, int);    // ���K���ڵ�����
// void getPrecision(double*, Iris*, Dis*, int);     // ����׼ȷ��
int getSpecie(int*);        // ��ȡԤ�������

extern size_t trainSize;    // ѵ������С
extern size_t testSize;     // ���Լ���С