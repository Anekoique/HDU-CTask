#define _CRT_SECURE_NO_WARNINGS 1
#pragma warning(disable: 4996)
#include"main.h"

int Menu_Teacher(void)
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
	printf("17.�л����");
	SetPosition(POS_X4, posy);
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

int Menu_Student(void)
{
	int posy = 2;
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
	SetPosition(POS_X2, ++posy);
	printf("1.��ѧ�Ų��Ҽ�¼");
	SetPosition(POS_X2, posy += 2);
	printf("2.���������Ҽ�¼");
	SetPosition(POS_X2, posy += 2);
	printf("3.��ѧ������");
	SetPosition(POS_X2, posy += 2);
	printf("4.����������");
	SetPosition(POS_X2, posy += 2);
	printf("5.���ܳɼ���������");
	SetPosition(POS_X2, posy += 2);
	printf("6.���ܳɼ���������");
	SetPosition(POS_X2, posy += 2);
	printf("7.��ӡѧ����¼");
	SetPosition(POS_X2, posy += 2);
	printf("8.�Ӵ��̶�ȡѧ����¼");
	SetPosition(POS_X2, posy += 2);
	printf("9.�л����");
	SetPosition(POS_X2, posy += 2);
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
	if (option == 1)option = 4;
	else if (option == 2)option = 5;
	else if (option == 3)option = 9;
	else if (option == 4)option = 10;
	else if (option == 5)option = 11;
	else if (option == 6)option = 12;
	else if (option == 7)option = 14;
	else if (option == 8)option = 16;
	else if (option == 9)option = 17;
	else option = -1;
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

void InputRecord(STU* head, int* n, int* m)
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
	STU* current = NULL;
	STU* pre = NULL;
	for (i = 0; i < *n; i++)
	{
		current = (STU*)malloc(sizeof(STU));
		if (head->next == NULL)
			head->next = current;
		else
			pre->next = current;
		current->next = NULL;
		SetPosition(POS_X2, ++posy);
		printf("�����%d��ѧ����Ϣ��\t", i + 1);
		scanf("%ld%s", &current->num, current->name);
		for (j = 0; j < *m; j++)
		{
			scanf("%f", &current->score[j]);
		}
		pre = current;
	}
}
void AppendRecord(STU* head, int* n, int m)
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
	STU* current = head;
	STU* pre = NULL;
	while (current != NULL)
		current = current->next;
	for (i = *n; i < *n + num_record; i++)
	{
		current = (STU*)malloc(sizeof(STU));
		if (pre != NULL)
			pre->next = current;
		current->next = NULL;
		printf("�����%d��ѧ����Ϣ��\t", i + 1);
		scanf("%ld%s", &current->num, current->name);
		for (j = 0; j < m; j++)
		{
			scanf("%f", &current->score[j]);
		}
		pre = current;
	}
	*n = *n + num_record;
	printf("�����ϣ�\n");
}
void DeleteRecord(STU* head, int* n, int m)
{
	int i, j;
	long id;
	char ch;
	printf("��������Ҫɾ��ѧ����Ϣ��Ӧ��ѧ�ţ�");
	scanf("%ld", &id);
	STU* current = head->next;
	STU* pre = NULL;
	for (i = 0; i < *n; i++)
	{
		if (current->num == id)
		{
			printf("�ҵ��˸�����¼����ϢΪ:\n");
			printf("%10ld%15s", current->num, current->name);
			for (j = 0; j < m; j++)
			{
				printf("%10.2f", current->score[j]);
			}
			printf("%10.2f%10.2f\n", current->sum, current->name);
			printf("��ȷ���Ƿ���Ҫɾ��������¼����Y/y��N/n����");
			getchar();
			scanf("%c", &ch);
			if (ch == 'Y' || ch == 'y')
			{
				pre->next = current->next;
				current = current->next;
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
		else {
			pre = current;
			current = current->next;
		}
	}
	printf("δ�ҵ�������¼��\n");

}
void SearchbyNum(STU* head, int n, int m)
{
	long id;
	int i, j;
	printf("��������Ҫ���ҵ�ѧ����ѧ�ţ�");
	scanf("%ld", &id);
	STU* current = head->next;
	for (i = 0; i < n; i++)
	{
		if (current->num == id)
		{
			printf("�ҵ��ˣ���ѧ����Ӧ��ѧ����ϢΪ:\n");
			printf("%10ld%15s", current->num, current->name);
			for (j = 0; j < m; j++)
			{
				printf("%10.2f", current->score[j]);
			}
			printf("%10.2f%10.2f", current->sum, current->aver);
		}
		else
		{
			current = current->next;
		}
	}
	printf("δ�ҵ����ѧ�Ŷ�Ӧ��ѧ����¼\n");
}
void SearchbyName(STU* head, int n, int m)
{
	int flag = 1;
	int i, j;
	int k = 0;
	char name[NAME_LEN];
	printf("��������Ҫ���ҵ�ѧ����������");
	scanf("%s", name);
	STU* current = head->next;
	for (i = 0; i < n; i++)
	{
		if (strcmp(current->name, name) == 0)
		{
			printf("�ҵ��ˣ���%dѧ����ϢΪ:\n", ++k);
			printf("%10ld%15s", current->num, current->name);
			for (j = 0; j < m; j++)
			{
				printf("%10.2f", current->score[j]);
			}
			printf("%10.2f%10.2f\n", current->sum, current->aver);
			flag = 0;
		}
		else
			current = current->next;
	}
	if (flag)
	{
		printf("δ�ҵ����������Ӧ��ѧ����¼\n");
	}
}
void ModifyRecord(STU* head, int n, int m)
{
	int i, j;
	long id;
	char ch;
	printf("��������Ҫ�޸���Ϣ��Ӧ��ѧ�ţ�");
	scanf("%ld", &id);
	STU* current = head->next;
	for (i = 0; i < n; i++)
	{
		if (current->num == id)
		{
			printf("�ҵ��˸�����¼����ϢΪ:\n");
			printf("%10ld%15s", current->num, current->name);
			for (j = 0; j < m; j++)
			{
				printf("%10.2f", current->score[j]);
			}
			printf("%10.2f%10.2f\n", current->sum, current->aver);
			printf("��ȷ���Ƿ���Ҫ�޸ģ���Y/y��N/n����");
			getchar();
			scanf("%c", &ch);
			if (ch == 'Y' || ch == 'y')
			{
				printf("������Ҫ�޸ĵ�ѧ����Ϣ��");
				scanf("%ld%s", &current->num, current->name);
				current->sum = 0;
				for (j = 0; j < m; j++)
				{
					scanf("%f", &current->score[j]);
					current->sum += current->score[j];
				}
				current->aver = current->sum / m;
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
void CalculateScoreOfStudent(STU* head, int n, int m)
{
	int i, j;
	STU* current = head->next;
	printf("ÿ��ѧ�����ſγ̵��ֺܷ�ƽ����Ϊ��\n");
	for (i = 0; i < n; i++)
	{
		current->sum = 0;
		for (j = 0; j < m; j++)
		{
			current->sum += current->score[j];
		}
		current->aver = current->sum / m;
		printf("��%d��ѧ�����ܷ�=%.2f��ƽ����=%.2f\n", i + 1, current->sum, current->aver);
		current = current->next;
	}
}

void CalculateScoreOfCourse(STU* head, int n, int m)
{
	int i, j;
	float sum[COURSE_NUM], aver[COURSE_NUM];
	int posy = 7;
	SetPosition(POS_X1, posy);
	printf("���ſγ̵��ֺܷ�ƽ���ֵļ�����Ϊ��");
	STU* current = head->next;
	for (j = 0; j < m; j++)
	{
		current = head->next;
		sum[j] = 0;
		for (i = 0; i < n; i++) {
			sum[j] += current->score[j];
			current = current->next;
		}
		aver[j] = sum[j] / n;
		SetPosition(POS_X1, ++posy);
		printf("��%d�ſγ̣��ܷ�=%.2f��ƽ����=%.2f\n", j + 1, sum[j], aver[j]);
	}
}

void SortbyNum( STU* head, int n, int m) {
	int i, j;
	int k;
	int flag = 0;
	STU* pre = head;
	STU* current = head->next;
	STU* Next = current->next;
	STU* temp = NULL;
	STU* init = head;
	for (i = 0; i < n - 1; i++)
	{
		if (i == 1) {
			pre = head;
			current = head->next;
			Next = current->next;
			temp = NULL;
		}
		else {
			init = init->next;
			for (int k = i; k > 0; k--)
			{
				STU* pre = init;
				STU* current = init->next;
				STU* Next = current->next;
				STU* temp = NULL;
			}
		}
		for (j = 0; j < n - 1 - i; j++) {
			if (!flag && current->num > Next->num)
			{
				current->next = Next->next;
				pre->next = Next;
				Next->next = current;
				flag = 1;
			}
			else if (flag && current->num > Next->num)
			{
				Next->next = current->next;
				pre->next = current;
				current->next = Next;
				flag = 0;
			}
			else {
				pre = pre->next;
				current = current->next;
				Next = Next->next;
			}
		}
		
	}
	printf("��ѧ�Ŵ�С�����ѧ����¼�������");
}


int Descending(float a, float b) {
	return a > b;
}

int Ascending(float a, float b) {
	return a < b;
}

void SortbyScore(STU* head, int n, int m, int(*compare)(float a, float b)) {
	int i, j;
	STU* temp, * current;

	for (i = 0; i < n; i++) {
		current = head->next;
		temp = head->next;
		for (j = 0; j < n - i - 1; j++) {
			if ((*compare)(current->sum, current->next->sum)) {
				if (current == head->next) {
					head->next = current->next;
					temp = current->next;
					current->next = temp->next;
					temp->next = current;
				}
				else {
					temp->next = current->next;
					current->next = current->next->next;
					temp->next->next = current;
					temp = temp->next;
				}
			}
			else {
				temp = current;
				current = current->next;
			}
		}
	}
	printf("��ѧ���ɼ��ֶܷ�ѧ����¼�������\n");
}

void SortbyName(STU* head, int n, int m) {
	int i, j;
	STU* temp, * current;

	for (i = 0; i < n; i++) {
		current = head->next;
		temp = head->next;
		for (j = 0; j < n - i - 1; j++) {
			if (strcmp(current->name, current->next->name) > 0) {
				if (current == head->next) {
					head->next = current->next;
					temp = current->next;
					current->next = temp->next;
					temp->next = current;
				}
				else {
					temp->next = current->next;
					current->next = current->next->next;
					temp->next->next = current;
					temp = temp->next;
				}
			}
			else {
				temp = current;
				current = current->next;
			}
		}
	}
	printf("�������ֵ��ѧ����¼�������\n");
}

void StatisticAnalysis(STU* head, int n, int m)
{
	int i, j, t[6];
	STU* current = head->next;
	for (j = 0; j < m; j++)
	{
		printf("\n�γ�%d�ɼ�ͳ�ƽ��Ϊ��\n", j + 1);
		printf("������\t����\tռ��\n");

		memset(t, 0, sizeof(t));
		for (i = 0; i < n; i++)
		{
			if (current->score[j] >= 0 && current->score[j] < 60)
				t[0]++;
			else if (current->score[j] < 70)
				t[1]++;
			else if (current->score[j] < 80)
				t[2]++;
			else if (current->score[j] < 90)
				t[3]++;
			else if (current->score[j] < 100)
				t[4]++;
			else if (current->score[j] == 100)
				t[5]++;
			current = current->next;
		}
		current = head->next;
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
	current = head->next;
	for (i = 0; i < n; i++)
	{
		if (current->aver >= 0 && current->aver < 60)
			t[0]++;
		else if (current->aver < 70)
			t[1]++;
		else if (current->aver < 80)
			t[2]++;
		else if (current->aver < 90)
			t[3]++;
		else if (current->aver < 100)
			t[4]++;
		else if (current->aver == 100)
			t[5]++;
		current = current->next;
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


void WritetoFile(int n, int m, STU* head)
{
	int i, j;
	FILE* fp; 
	STU* current = head->next;
	if ((fp = fopen("D:\\storage\\student_score\\student.txt", "w")) == NULL)
	{
		printf("�����ļ�student.txt�޷���");
		return;
	}
	fprintf(fp, "%10d%10d\n", n, m);
	for (i = 0; i < n; i++)
	{
		fprintf(fp, "%10ld%10s\n", current->num, current->name);
		for (j = 0; j < m; j++)
		{
			fprintf(fp, "%10.2f", current->score[j]);
		}
		fprintf(fp, "%10.2f%10.2f\n", current->sum, current->aver);
		current = current->next;
	}
	fclose(fp);
	printf("�������!\n");
}


int ReadfromFile(int* n, int* m, STU* head, int* first)
{
	FILE* fp;
	int i, j;
	int posy = 8;
	STU* current = head->next;
	SetPosition(POS_X1, posy);
	if ((fp = fopen("D:\\storage\\student_score\\student.txt", "r")) == NULL)
	{
		printf("�����ļ�student.txt�޷���");
		return 1;
	}
	fscanf(fp, "%10d%10d", n, m);
	for (i = 0; i < *n; i++)
	{
		fscanf(fp, "%10ld", current->num);
		fscanf(fp, "%10s", current->name);
		for (j = 0; j < *m; j++)
		{
			fscanf(fp, "%10f", current->score[j]);
		}
		fscanf(fp, "%10f%10f", current->sum, current->aver);
		current = current->next;
	}
	*first = 0;
	fclose(fp);
	printf("���ݴӴ��̶�ȡ��ϣ�");
	return 0;
}


void PrintRecord(STU* head, int n, int m)
{
	int i, j;
	STU* current = head->next;
	printf("ѧ��\t\t����\t\t");
	for (j = 0; j < m; j++)
	{
		printf("�γ�%d\t\t", j + 1);
	}
	printf("�ܷ�\t\tƽ����\n");

	for (i = 0; i < n; i++)
	{
		printf("%-16ld%-16s", current->num, current->name);
		for (j = 0; j < m; j++)
		{
			printf("%-16.2lf", current->score[j]);
		}
		printf("%-16.2lf%-16.2lf\n", current->sum, current->aver);
		current = current->next;
	}
	return;
}

void TidyupRecord(STU* head, int n, int m)
{
	int i, j;
	STU* current = head->next;
	for (i = 0; i < n; i++)
	{
		current->sum = 0;
		for (j = 0; j < m; j++)
		{
			current->sum += current->score[j];
		}
		current->aver = current->sum / (float)m;
		current = current->next;
	}
}

int Exchange_identity()
{
	int identity;
	SetPosition(POS_X2, 15);
	printf("1.��ʦ");
	SetPosition(POS_X2, 17);
	printf("2.ѧ��");
	SetPosition(POS_X2, 23);
	printf("��ѡ������Ҫѡ������:[  ]\b\b\b");
	scanf("%d", &identity);
	if (identity == 1)
	{
		system("cls");
		printf("�ɹ�ѡ����ݣ���ʦ");
	}
	else if (identity == 2)
	{
		system("cls");
		printf("�ɹ�ѡ����ݣ�ѧ��");
	}
	else
	{
		system("cls");
		printf("ѡ�����ʧ��");
	}
	return identity;
}