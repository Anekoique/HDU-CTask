#define _CRT_SECURE_NO_WARNINGS 1
#include"main.h"
int Menu(void);
void SetPosition(int x, int t);
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
		scanf("%ls%s", &stu[i].num, stu[i].name);
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
		scanf("%ld%s",&stu[i].num, stu[i].name);
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
void SearchbyNumber(STU stu[], int n, int m)
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
void CalculateScoreOfCourse(STU stu[], int n, int m);
void SortbyNum(STU stu[], int n, int m);
void SortbyName(STU stu[], int n, int m);
void SortbyScore(STU stu[], int n, int m, int(*compare)(float a, float b));
int Ascending(float a, float b);
int Descending(float a, float b);
void StatisticAnalysis(STU stu[], int n, int m);
void PrintRecord(STU stu[], int n, int m);
void WritetoFile(STU stu[], int n, int m);
int ReadfromFile(STU stu[], int* n, int* m, int* first);
int main()
{
	int n = 0;
	int m = 0;
	int i, j;
	char ch;
	int first = 1;
	STU stu[STU_NUM];
	system("mode con cols=130 Lines=60");
	system("color 0E");
	while (1)
	{
		system("cls");
		ch = Menu();
		switch (ch) {
		case 1:
			system("cls");
			InputRecord(stu,&n, &m);
			break;
		case 2:
			system("cls");
			if (first)
			{
				printf("ϵͳ������ѧ���ɼ���Ϣ���������룡\n");
				system("pause");
				break;
			}
			AppendRecord(stu, &n, m);
			system("pause");
			break;
		case 3:
			system("cls");
			if (first)
			{
				printf("ϵͳ������ѧ���ɼ���Ϣ���������룡\n");
				system("pause");
				break;
			}
			DeleteRecord(stu, &n, m);
			system("pause");
			break;
			break;
		case 4:
			system("cls");
			if (first)
			{
				printf("ϵͳ������ѧ���ɼ���Ϣ���������룡\n");
				system("pause");
				break;
			}
			SearchbyNumber(stu, n, m);
			system("pause");
			break;
		case 5:
			system("cls");
			if (first)
			{
				printf("ϵͳ������ѧ���ɼ���Ϣ���������룡\n");
				system("pause");
				break;
			}
			SearchbyName(stu, n, m);
			system("pause");
			break;
		case 6:
			system("cls");
			if (first)
			{
				printf("ϵͳ������ѧ���ɼ���Ϣ���������룡\n");
				system("pause");
				break;
			}
			ModifyRecord(stu, n, m);
			system("pause");
			break;
		case 7:
			system("cls");
			if (first)
			{
				printf("ϵͳ������ѧ���ɼ���Ϣ���������룡\n");
				system("pause");
				break;
			}
			CalculateScoreOfStudent(stu, n, m);
			system("pause");
			break;
		case 8:
			system("cls");
			if (first)
			{
				SetPosition(POS_X3, POS_Y);
				printf("ϵͳ������ѧ���ɼ���Ϣ���������룡\n");
				getch();
				break;
			}
			CalculateScoreOfCourse(stu, n, m);
			getch();
			break;
		case 9:
			break;
		case 10:
			break;
		case 11:
			break;
		case 12:
			break;
		case 13:
			break;
		case 14:
			break;
		case 15:
			break;
		case 16:
			break;
		case 0:
			break;
		default:
			break;
		}
	}
}