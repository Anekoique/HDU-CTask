#define _CRT_SECURE_NO_WARNINGS 1
#pragma warning(disable: 4996)
#include"main.h"

int Menu(void)
{
	int posy = 5;
	int option;
	int i, j;
	SetPosition(POS_X3, posy);
	printf("ѧ���ɼ�����ϵͳ\n");
	for (i = 0; i < 2; i++)
	{
		SetPosition(POS_X1, ++posy);
		for (j = 0; j < 55; j++)
		{
			printf("-");
		}
	}
	SetPosition(POS_X1, ++posy);
	printf("1.����ѧ����Ϣ");
	SetPosition(POS_X4, posy);
	printf("2.����ѧ����Ϣ");
	SetPosition(POS_X1, posy += 2);
	printf("3.ɾ��ѧ����Ϣ");
	SetPosition(POS_X4, posy);
	printf("4.��ѧ�Ų��Ҽ�¼");
	SetPosition(POS_X1, posy += 2);
	printf("5.���������Ҽ�¼");
	SetPosition(POS_X4, posy);
	printf("6.�޸�ѧ����Ϣ");
	SetPosition(POS_X1, posy += 2);
	printf("7.����ѧ���ɼ�");
	SetPosition(POS_X4, posy);
	printf("8.����γ̳ɼ�");
	SetPosition(POS_X1, posy += 2);
	printf("9.��ѧ������");
	SetPosition(POS_X4, posy);
	printf("10.����������");
	SetPosition(POS_X1, posy += 2);
	printf("11.���ܳɼ���������");
	SetPosition(POS_X4, posy);
	printf("12.���ܳɼ���������");
	SetPosition(POS_X1, posy += 2);
	printf("13.ѧ���ɼ�ͳ��");
	SetPosition(POS_X4, posy);
	printf("14.��ӡѧ����¼");
	SetPosition(POS_X1, posy += 2);
	printf("15.ѧ����¼����");
	SetPosition(POS_X4, posy);
	printf("16.�Ӵ��̶�ȡѧ����¼");
	SetPosition(POS_X1, posy += 2);
	printf("0.�˳�");
	for (i = 0; i < 2; i++)
	{
		SetPosition(POS_X1, ++posy);
		for (j = 0; j < 55; j++)
		{
			printf("-");
		}
	}
	SetPosition(POS_X1, ++posy);
	printf("��ѡ������Ҫ���еĲ���[0~16]:[  ]\b\b\b");
	scanf("%d", &option);
	return option;
}

void SetPosition(int x, int y)
{
	HANDLE hOut;
	COORD pos;

	hOut = GetStdHandle(STD_OUTPUT_HANDLE);
	pos.X = x;
	pos.Y = y;
	SetConsoleCursorPosition(hOut, pos);
}

void InputRecord(STU stu[], int* n, int* m)
{
	int i, j;
	int posy = 6;
	SetPosition(POS_X2, posy);
	printf("����ѧ������(n<%d): ", STU_NUM);
	scanf("%d", n);
	SetPosition(POS_X2, posy += 2);
	printf("����γ�����(m<%d): ", COURSE_NUM);
	scanf("%d", m);
	for (i = 0; i < 2; i++)
	{
		SetPosition(POS_X1, ++posy);
		for (j = 0; j < 55; j++)
		{
			printf("-");
		}
	}
	SetPosition(POS_X2, ++posy);
	printf("����ѧ����ѧ�š������͸��ſγ̳ɼ���");
	for (i = 0; i < *n; i++)
	{
		SetPosition(POS_X2, ++posy);
		printf("�����%d��ѧ����Ϣ��\t", i + 1);
		scanf("%ld%s", &stu[i].num, stu[i].name);
		for (j = 0; j < *m; j++)
		{
			scanf("%f", &stu[i].score[j]);
		}
	}
}
void AppendRecord(STU stu[], int* n, int m)
{
	int i, j;
	int num_record;
	printf("��������Ҫ���ӵ�ѧ����¼������");
	scanf("%d", &num_record);
	while (*n + num_record > STU_NUM)
	{
		printf("Ҫ���ӵļ�¼����̫�࣬���������룺");
		scanf("%d", &num_record);
	}
	for (i = *n; i < *n + num_record; i++)
	{
		printf("�����%d��ѧ����Ϣ��\t", i + 1);
		scanf("%ld%s", &stu[i].num, stu[i].name);
		for (j = 0; j < m; j++)
		{
			scanf("%f", &stu[i].score[j]);
		}
	}
	*n = *n + num_record;
	printf("�����ϣ�\n");
}
void DeleteRecord(STU stu[], int* n, int m)
{
	int i, j;
	long id;
	char ch;
	printf("��������Ҫɾ��ѧ����Ϣ��Ӧ��ѧ�ţ�");
	scanf("%ld", &id);
	for (i = 0; i < *n; i++)
	{
		if (stu[i].num == id)
		{
			printf("�ҵ��˸�����¼����ϢΪ:\n");
			printf("%10ld%15s", stu[i].num, stu[i].name);
			for (j = 0; j < m; j++)
			{
				printf("%10.2f", stu[i].score[j]);
			}
			printf("%10.2f%10.2f\n", stu[i].sum, stu[i].name);
			printf("��ȷ���Ƿ���Ҫɾ��������¼����Y/y��N/n����");
			getchar();
			scanf("%c", &ch);
			if (ch == 'Y' || ch == 'y')
			{
				for (j = i; j < *n - 1; j++)
				{
					stu[j] = stu[j + 1];
				}
				(*n)--;
				printf("ɾ�����\n");
			}
			else if (ch == 'N' || ch == 'n')
			{
				printf("�ҵ��˸�ѧ����¼��������ɾ��\n");

			}
			else {
				printf("�������\n");
			}
		}
	}
	printf("δ�ҵ�������¼��\n");

}
void SearchbyNum(STU stu[], int n, int m)
{
	long id;
	int i, j;
	printf("��������Ҫ���ҵ�ѧ����ѧ�ţ�");
	scanf("%ld", &id);
	for (i = 0; i < n; i++)
	{
		if (stu[i].num == id)
		{
			printf("�ҵ��ˣ���ѧ����Ӧ��ѧ����ϢΪ:\n");
			printf("%10ld%15s", stu[i].num, stu[i].name);
			for (j = 0; j < m; j++)
			{
				printf("%10.2f", stu[i].score[j]);
			}
			printf("%10.2f%10.2f", stu[i].sum, stu[i].aver);
		}
	}
	printf("δ�ҵ����ѧ�Ŷ�Ӧ��ѧ����¼\n");
}
void SearchbyName(STU stu[], int n, int m)
{
	int flag = 1;
	int i, j;
	int k = 0;
	char name[NAME_LEN];
	printf("��������Ҫ���ҵ�ѧ����������");
	scanf("%s", name);
	for (i = 0; i < n; i++)
	{
		if (strcmp(stu[i].name, name) == 0)
		{
			printf("�ҵ��ˣ���%dѧ����ϢΪ:\n", ++k);
			printf("%10ld%15s", stu[i].num, stu[i].name);
			for (j = 0; j < m; j++)
			{
				printf("%10.2f", stu[i].score[j]);
			}
			printf("%10.2f%10.2f\n", stu[i].sum, stu[i].aver);
			flag = 0;
		}
	}
	if (flag)
	{
		printf("δ�ҵ����������Ӧ��ѧ����¼\n");
	}
}
void ModifyRecord(STU stu[], int n, int m)
{
	int i, j;
	long id;
	char ch;
	printf("��������Ҫ�޸���Ϣ��Ӧ��ѧ�ţ�");
	scanf("%ld", &id);
	for (i = 0; i < n; i++)
	{
		if (stu[i].num == id)
		{
			printf("�ҵ��˸�����¼����ϢΪ:\n");
			printf("%10ld%15s", stu[i].num, stu[i].name);
			for (j = 0; j < m; j++)
			{
				printf("%10.2f", stu[i].score[j]);
			}
			printf("%10.2f%10.2f\n", stu[i].sum, stu[i].aver);
			printf("��ȷ���Ƿ���Ҫ�޸ģ���Y/y��N/n����");
			getchar();
			scanf("%c", &ch);
			if (ch == 'Y' || ch == 'y')
			{
				printf("������Ҫ�޸ĵ�ѧ����Ϣ��");
				scanf("%ld%s", &stu[i].num, stu[i].name);
				stu[i].sum = 0;
				for (j = 0; j < m; j++)
				{
					scanf("%f", &stu[i].score[j]);
					stu[i].sum += stu[i].score[j];
				}
				stu[i].aver = stu[i].sum / m;
				printf("�޸����\n");


			}
			else if (ch == 'N' || ch == 'n')
			{
				printf("�ҵ��˸�ѧ����¼���������޸�\n");

			}
			else {
				printf("�������\n");
			}
		}
	}
	printf("δ�ҵ�������¼��\n");
}
void CalculateScoreOfStudent(STU stu[], int n, int m)
{
	int i, j;
	printf("ÿ��ѧ�����ſγ̵��ֺܷ�ƽ����Ϊ��\n");
	for (i = 0; i < n; i++)
	{
		stu[i].sum = 0;
		for (j = 0; j < m; j++)
		{
			stu[i].sum += stu[i].score[j];
		}
		stu[i].aver = stu[i].sum / m;
		printf("��%d��ѧ�����ܷ�=%.2f��ƽ����=%.2f\n", i + 1, stu[i].sum, stu[i].aver);
	}
}

void CalculateScoreOfCourse(STU stu[], int n, int m)
{
	int i, j;
	float sum[COURSE_NUM], aver[COURSE_NUM];
	int posy = 7;
	SetPosition(POS_X1, posy);
	printf("���ſγ̵��ֺܷ�ƽ���ֵļ�����Ϊ��");
	for (j = 0; j < m; j++)
	{
		sum[j] = 0;
		for (i = 0; i < n; i++)
			sum[j] += stu[i].score[j];
		aver[j] = sum[j] / n;
		SetPosition(POS_X1, ++posy);
		printf("��%d�ſγ̣��ܷ�=%.2f��ƽ����=%.2f\n", j + 1, sum[j], aver[j]);
	}
}

void SortbyNum( STU* stu, int n, int m) {
	int i, j;
	int k;
	STU temp;

	for (i = 0; i < n; i++)
	{
		k = i;
		for (j = i + 1; j < n; j++)
		{
			if (stu[j].num < stu[k].num)
				k = j;
		}
		if (k != i)
		{
			temp = stu[k];
			stu[k] = stu[i];
			stu[i] = temp;
		}
	}
	printf("��ѧ�Ŵ�С�����ѧ����¼�������");
}


int Descending(float a, float b)
{
	return a > b;
}

int Ascending(float a, float b)
{
	return a < b;
}

void SortbyScore(STU* stu, int n, int m, int(*compare)(float a, float b)) //����Descending��������Ascending������
{
	int i, j;
	int k;
	STU temp;

	for (i = 0; i < n; i++)
	{
		k = i;
		for (j = i + 1; j < n; j++)
		{
			if ((*compare)(stu[j].sum, stu[k].sum))
				k = j;
		}
		if (k != i)
		{
			temp = stu[k];
			stu[k] = stu[i];
			stu[i] = temp;
		}
	}
	printf("��ѧ���ɼ��ֶܷ�ѧ����¼�������");
}


void SortbyName(STU stu[], int n, int m) //����Descending��������Ascending������
{
	int i, j;
	STU temp;

	for (i = 0; i < n; i++)
	{
		for (j = 0; j < n - 1 - i; j++)
		{
			if (strcmp(stu[j].name, stu[j + 1].name))
			{
				temp = stu[j];
				stu[j] = stu[j + 1];
				stu[j + 1] = temp;
			}
		}
	}
	printf("�������ֵ��ѧ����¼�������");
	return;
}


void StatisticAnalysis(STU* stu, int n, int m)
{
	int i, j, t[6];

	for (j = 0; j < m; j++)
	{
		printf("\n�γ�%d�ɼ�ͳ�ƽ��Ϊ��\n", j + 1);
		printf("������\t����\tռ��\n");

		memset(t, 0, sizeof(t));
		for (i = 0; i < n; i++)
		{
			if (stu[i].score[j] >= 0 && stu[i].score[j] < 60)
				t[0]++;
			else if (stu[i].score[j] < 70)
				t[1]++;
			else if (stu[i].score[j] < 80)
				t[2]++;
			else if (stu[i].score[j] < 90)
				t[3]++;
			else if (stu[i].score[j] < 100)
				t[4]++;
			else if (stu[i].score[j] == 100)
				t[5]++;
		}

		for (i = 0; i < 6; i++)
		{
			if (i == 0)
				printf("<60\t%d\t%.2f%%\n", t[i], (float)t[i] / n * 100);
			else if (i == 5)
				printf("100\t%d\t%.2f%%\n", t[i], (float)t[i] / n * 100);
			else
				printf("%d-%d\t%d\t%.2f%%\n", (i + 5) * 10, (i + 5) * 10 + 9, t[i], (float)t[i] / n * 100);
		}
	}
	printf("\nѧ���ɼ�ƽ����ͳ�ƽ��Ϊ��\n");
	printf("������\t����\tռ��\n");
	memset(t, 0, sizeof(t));
	for (i = 0; i < n; i++)
	{
		if (stu[i].aver >= 0 && stu[i].aver < 60)
			t[0]++;
		else if (stu[i].aver < 70)
			t[1]++;
		else if (stu[i].aver < 80)
			t[2]++;
		else if (stu[i].aver < 90)
			t[3]++;
		else if (stu[i].aver < 100)
			t[4]++;
		else if (stu[i].aver == 100)
			t[5]++;
	}
	for (i = 0; i < 6; i++)
	{
		if (i == 0)
			printf("<60\t%d\t%.2f%%\n", t[i], (float)t[i] / n * 100);
		else if (i == 5)
			printf("100\t%d\t%.2f%%\n", t[i], (float)t[i] / n * 100);
		else
			printf("%d-%d\t%d\t%.2f%%\n", (i + 5) * 10, (i + 5) * 10 + 9, t[i], (float)t[i] / n * 100);
	}
}


void WritetoFile(int n, int m, STU stu[])
{
	int i, j;
	FILE* fp; 
	if ((fp = fopen("D:\\storage\\student_score\\student.txt", "w")) == NULL)
	{
		printf("�����ļ�student.txt�޷���");
		return;
	}
	fprintf(fp, "%10d%10d\n", n, m);
	for (i = 0; i < n; i++)
	{
		fprintf(fp, "%10ld%10s\n", stu[i].num, stu[i].name);
		for (j = 0; j < m; j++)
		{
			fprintf(fp, "%10.2f", stu[i].score[j]);
		}
		fprintf(fp, "%10.2f%10.2f\n", stu[i].sum, stu[i].aver);
	}
	fclose(fp);
	printf("�������!\n");
}


int ReadfromFile(int* n, int* m, STU stu[], int* first)
{
	FILE* fp;
	int i, j;
	int posy = 8;
	SetPosition(POS_X1, posy);
	if ((fp = fopen("D:\\storage\\student_score\\student.txt", "r")) == NULL)
	{
		printf("�����ļ�student.txt�޷���");
		return 1;
	}
	fscanf(fp, "%10d%10d", n, m);
	for (i = 0; i < *n; i++)
	{
		fscanf(fp, "%10ld", &stu[i].num);
		fscanf(fp, "%10s", stu[i].name);
		for (j = 0; j < *m; j++)
		{
			fscanf(fp, "%10f", &stu[i].score[j]);
		}
		fscanf(fp, "%10f%10f", &stu[i].sum, &stu[i].aver);
	}
	*first = 0;
	fclose(fp);
	printf("���ݴӴ��̶�ȡ��ϣ�");
	return 0;
}


void PrintRecord(STU* stu, int n, int m)
{
	int i, j;
	printf("ѧ��\t\t����\t\t");
	for (j = 0; j < m; j++)
	{
		printf("�γ�%d\t\t", j + 1);
	}
	printf("�ܷ�\t\tƽ����\n");

	for (i = 0; i < n; i++)
	{
		printf("%-16ld%-16s", stu[i].num, stu[i].name);
		for (j = 0; j < m; j++)
		{
			printf("%-16.2lf", stu[i].score[j]);
		}
		printf("%-16.2lf%-16.2lf\n", stu[i].sum, stu[i].aver);
	}
	return;
}

void TidyupRecord(STU stu[], int n, int m)
{
	int i, j;
	for (i = 0; i < n; i++)
	{
		stu[i].sum = 0;
		for (j = 0; j < m; j++)
		{
			stu[i].sum += stu[i].score[j];
		}
		stu[i].aver = stu[i].sum / (float)m;
	}
}