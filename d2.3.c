#include<stdio.h>
#include<conio.h>  
#include<stdlib.h> 
#include<string.h>
#include<windows.h>
#define MAX 100
#define INT_MAX 99999
FILE *fp;
int visited[100];
int ok;
int stop = 1;
char name[50], pass[50];
char textstring[100];
typedef struct
{
	int adj;
}ArcType;
typedef struct
{
	int num;
	char name[MAX];
	char introduction[MAX];
}PType;

typedef struct
{
	PType vertexs[MAX];   //��������
	ArcType arcs[MAX][MAX];  //�ڽӾ���
	int vexnum, arcnum;   //������������
}GraphType;
//�ڽӱ�
typedef struct arc
{
	int adjvex;   //�ڽӵ���
	int weight;   //Ȩֵ��
	struct arc *next;  //ָ����һ�ڽӵ�
}ArcType1;

typedef struct
{
	int data;
	ArcType1 *firstarc;
}VertexType;     //�����ڵ�

typedef struct
{
	VertexType vextexs[MAX];
	int vexnum, arcnum;
}AdjList;   //�ڽӱ�

GraphType *create(GraphType *G)  //��������ͼ
{
	int i, j;
	if ((fp = fopen("D:\\file.txt", "wt+")) == NULL)
	{
		printf("\nerror on open D:\\file.txt file!");
		exit(0);   //���������е����˳�����
	}
	else
	{
		G = (GraphType *)malloc(sizeof(GraphType));
		G->vexnum = 14;
		G->arcnum = 23;
		G->vertexs[1].num = 1;
		strcpy(G->vertexs[1].name, "ѧУ����");
		strcpy(G->vertexs[1].introduction, "λ���¹Ĵ�� 48�š�");
		fprintf(fp, "%d %s %s\n", G->vertexs[1].num, G->vertexs[1].name, G->vertexs[1].introduction);
		G->vertexs[2].num = 2;
		strcpy(G->vertexs[2].name, "����¥");
		strcpy(G->vertexs[2].introduction, "ѧУ�쵼�ڴ˰칫��");
		fprintf(fp, "%d %s %s\n", G->vertexs[2].num, G->vertexs[2].name, G->vertexs[2].introduction);
		G->vertexs[3].num = 3;
		strcpy(G->vertexs[3].name, "��ѧ¥1-4");
		strcpy(G->vertexs[3].introduction, "������ÿ���Ͽ��������ܼ��ĵط�����������ѧԺ�����ǵĸ���ʵ�����");
		fprintf(fp, "%d %s %s\n", G->vertexs[3].num, G->vertexs[3].name, G->vertexs[3].introduction);
		G->vertexs[4].num = 4;
		strcpy(G->vertexs[4].name, "ͼ���");
		strcpy(G->vertexs[4].introduction, "ͼ���������ѧУ��һ�󱦲أ���ʷ�ƾã�����ḻ�ģ��¾�����ͨ��¥��������һ�����ճ�ѧϰ�ĺ�ȥ����");
		fprintf(fp, "%d %s %s\n", G->vertexs[4].num, G->vertexs[4].name, G->vertexs[4].introduction);
		G->vertexs[5].num = 5;
		strcpy(G->vertexs[5].name, "�ۺ�¥���ڶ����ֲ�");
		strcpy(G->vertexs[5].introduction, "�ۺ�¥1-2¥�����ǵ�УҽԺ�������Ķ��ǽ��ң��ڶ����ֲ�ƽʱ����һЩ���ݣ�����������Ŀ");
		fprintf(fp, "%d %s %s\n", G->vertexs[5].num, G->vertexs[5].name, G->vertexs[5].introduction);
		G->vertexs[6].num = 6;
		strcpy(G->vertexs[6].name, "������");
		strcpy(G->vertexs[6].introduction, "�����������и����赸���٤����ȭ������ϰ��");
		fprintf(fp, "%d %s %s\n", G->vertexs[6].num, G->vertexs[6].name, G->vertexs[6].introduction);
		G->vertexs[7].num = 7;
		strcpy(G->vertexs[7].name, "��ѧ¥9-18");
		strcpy(G->vertexs[7].introduction, "����������������Ҫ�Ľ�ѧ�������󲿷�ѧԺ����������");
		fprintf(fp, "%d %s %s\n", G->vertexs[7].num, G->vertexs[7].name, G->vertexs[7].introduction);
		G->vertexs[8].num = 8;
		strcpy(G->vertexs[8].name, "�ﾶ��");
		strcpy(G->vertexs[8].introduction, "�����ǱȽϴ��͵Ļ����˶�������У�졢�˶���һ��������ٰ�");
		fprintf(fp, "%d %s %s\n", G->vertexs[8].num, G->vertexs[8].name, G->vertexs[8].introduction);
		G->vertexs[9].num = 9;
		strcpy(G->vertexs[9].name, "��Ӿ��");
		strcpy(G->vertexs[9].introduction, "ѧ��ĩ��ҷ�������������Ӿ�Σ�ƽʱ������⿪��");
		fprintf(fp, "%d %s %s\n", G->vertexs[9].num, G->vertexs[9].name, G->vertexs[9].introduction);
		G->vertexs[10].num = 10;
		strcpy(G->vertexs[10].name, "����¥6-16");
		strcpy(G->vertexs[10].introduction, "�ųơ�����֮�ۡ�����ѧУ�������");
		fprintf(fp, "%d %s %s\n", G->vertexs[10].num, G->vertexs[10].name, G->vertexs[10].introduction);
		G->vertexs[11].num = 11;
		strcpy(G->vertexs[11].name, "ѧ������");
		strcpy(G->vertexs[11].introduction, "�ṩ�������Ʒ");
		fprintf(fp, "%d %s %s\n", G->vertexs[11].num, G->vertexs[11].name, G->vertexs[11].introduction);
		G->vertexs[12].num = 12;
		strcpy(G->vertexs[12].name, "����¥1-5");
		strcpy(G->vertexs[12].introduction, "��������������ڵ���λ���������Ƶĵط�");
		fprintf(fp, "%d %s %s\n", G->vertexs[12].num, G->vertexs[12].name, G->vertexs[12].introduction);
		G->vertexs[13].num = 13;
		strcpy(G->vertexs[13].name, "��ܰԷ������Է");
		strcpy(G->vertexs[13].introduction, "��ܰԷ�����ǵ����������װ��Ư�����Ҳ�Ʒ���ֶ���������Է�Ǿ�ʳ�ã���Ʒȫ���Ҽ۸�ʵ��");
		fprintf(fp, "%d %s %s\n", G->vertexs[13].num, G->vertexs[13].name, G->vertexs[13].introduction);
		G->vertexs[14].num = 14;
		strcpy(G->vertexs[14].name, "���");
		strcpy(G->vertexs[14].introduction, "��������������£��峿����ĺ�ȥ��");
		fprintf(fp, "%d %s %s\n", G->vertexs[14].num, G->vertexs[14].name, G->vertexs[14].introduction);
		for (i = 1; i <= G->vexnum; i++)
			for (j = 1; j <= G->vexnum; j++)
				G->arcs[i][j].adj = INT_MAX;
		for (i = 1; i <= G->vexnum; i++)
			G->arcs[i][i].adj = 0;
		G->arcs[1][2].adj = G->arcs[2][1].adj = 300;
		G->arcs[1][14].adj = G->arcs[14][1].adj = 400;
		G->arcs[2][3].adj = G->arcs[3][2].adj = 200;
		G->arcs[2][6].adj = G->arcs[6][2].adj = 250;
		G->arcs[3][4].adj = G->arcs[4][3].adj = 50;
		G->arcs[3][14].adj = G->arcs[14][3].adj = 100;
		G->arcs[4][5].adj = G->arcs[5][4].adj = 50;
		G->arcs[4][6].adj = G->arcs[6][4].adj = 100;
		G->arcs[4][14].adj = G->arcs[14][4].adj = 100;
		G->arcs[5][6].adj = G->arcs[6][5].adj = 50;
		G->arcs[5][13].adj = G->arcs[13][5].adj = 50;
		G->arcs[6][7].adj = G->arcs[7][6].adj = 50;
		G->arcs[6][8].adj = G->arcs[8][6].adj = 50;
		G->arcs[7][8].adj = G->arcs[8][7].adj = 50;
		G->arcs[8][9].adj = G->arcs[9][8].adj = 50;
		G->arcs[8][10].adj = G->arcs[10][8].adj = 100;
		G->arcs[9][10].adj = G->arcs[10][9].adj = 50;
		G->arcs[10][11].adj = G->arcs[11][10].adj = 50;
		G->arcs[10][13].adj = G->arcs[13][10].adj = 200;
		G->arcs[11][12].adj = G->arcs[12][11].adj = 50;
		G->arcs[12][13].adj = G->arcs[13][12].adj = 50;
		G->arcs[12][14].adj = G->arcs[14][12].adj = 100;
		G->arcs[13][14].adj = G->arcs[13][14].adj = 150;
		for (i = 1; i <= G->vexnum; i++)
		{
			for (j = 1; j <= G->vexnum; j++)
			{
				fprintf(fp, "%d\t", G->arcs[i][j].adj);
			}
		}
	}
	fclose(fp);
	return G;
}

AdjList *list(GraphType *G, AdjList *g)  //�ڽӾ���ת��Ϊ�ڽӱ�
{
	int i, j;
	ArcType1 *p;
	for (i = 1; i <= G->vexnum; i++)
		g->vextexs[i].firstarc = NULL;
	for (i = 1; i <= G->vexnum; i++)
		for (j = G->vexnum; j >= 1; j--)
		{
			if (G->arcs[i][j].adj != INT_MAX)
			{
				p = (ArcType1 *)malloc(sizeof(ArcType1));
				p->adjvex = j;
				p->next = g->vextexs[i].firstarc;   //ͷ�巨
				g->vextexs[i].firstarc = p;
			}
		}
	g->vexnum = G->vexnum;
	g->arcnum = G->arcnum;
	return g;
}

void inquiry(GraphType *G)   //��ѯ������Ϣ
{
	int n;
	printf("�����ѯ�ľ�����Ϊ��");
	scanf("%d", &n);
	printf("%d,%s", G->vertexs[n].num, G->vertexs[n].name);
	printf("\n�������:");
	printf("%s\n", G->vertexs[n].introduction);
}
void shortest(GraphType *G, int P[][MAX], int D[][MAX]) //������·�����Լ���Ҫ�����ľ���
{
	int m, n;
	printf("��ϣ����ѯ������?\n");
	scanf("%d", &m);
	printf("��\n");
	scanf("%d", &n);
	if (m < n)
	{
		printf("%s��%s֮������·������Ϊ%d\n", G->vertexs[m].name, G->vertexs[n].name, D[m][n]);//������·��
		printf("path: %s", G->vertexs[n].name);            //���Դ��
		while (P[m][n] != 0)                               //�����ýڵ�
		{
			printf("<--%s", G->vertexs[P[m][n]].name);     //���·������һ���ڵ�
			if (m < n)
				n = P[m][n];
			else
				m = P[n][m];
		}
		printf("<--%s", G->vertexs[m].name);
	}
	else
	{
		printf("%s��%s֮������·������Ϊ%d\n", G->vertexs[m].name, G->vertexs[n].name, D[m][n]);
		printf("path: %s", G->vertexs[m].name);
		while (P[m][n] != 0)
		{
			printf("-->%s", G->vertexs[P[m][n]].name);
			if (m < n)
				n = P[m][n];
			else
				m = P[n][m];
		}
		printf("-->%s", G->vertexs[n].name);
		//		printf("%s��%s֮������·������Ϊ%d\n", G->vertexs[m].name, G->vertexs[n].name, D[m][n]);
	}
}

void floyd(GraphType *G)   // �����㷨          �������� �㷨ʱ�临�Ӷ�:O(n3)
{
	int D[MAX][MAX];       //D[i][j]��¼���·��Ȩֵ
	int P[MAX][MAX];       // P[i][j]Ϊi��j�ĵ�ǰ���·��
	int i, j, k;
	for (j = 1; j <= G->vexnum; j++)
	{
		for (k = 1; k <= G->vexnum; k++)
		{
			D[j][k] = G->arcs[j][k].adj;       //��ʼ������֮���ȨֵD
			P[j][k] = 0;                       //��ʼ��P   δ��ʼ���ң������м�ڵ��ʼ��Ϊ0
		}
	}
	for (i = 1; i <= G->vexnum; i++)           //��i��j֮��k�μ����м�ڵ�
	{
		for (j = 1; j <= G->vexnum; j++)
		{
			for (k = 1; k <= G->vexnum; k++)
			{
				if (D[j][k] > D[j][i] + D[i][k])      //�ж�·���ֿ�����ֱ��     �ж����·��
				{
					D[j][k] = D[j][i] + D[i][k];
					P[j][k] = i;
					P[k][j] = i;  //��¼������·��
				}
			}
		}
	}
	shortest(G, P, D);
}
void AllPath(GraphType *G, AdjList *g, int m, int n, int path[], int d) //�����������·��
{
	int w, i;
	ArcType1 *p;
	visited[m] = 1;
	d++;
	path[d] = m;
	if (m == n && d >= 1)
	{
		printf(" ");
		for (i = 0; i < d; i++)
			printf("%s->", G->vertexs[path[i]].name);
		printf("%s", G->vertexs[path[d]].name);
		printf("\n");
	}
	p = g->vextexs[m].firstarc;
	while (p != NULL)
	{
		w = p->adjvex;
		if (visited[w] == 0)
			AllPath(G, g, w, n, path, d);
		p = p->next;
	}
	visited[m] = 0;
}
void GetAllPath(GraphType *G, AdjList *g)  //�ó�����·��
{
	int m, n;
	int path[MAX];
	printf("��ϣ����ѯ������?\n");
	scanf("%d", &m);
	printf("��");
	scanf("%d", &n);
	AllPath(G, g, m, n, path, -1);
}

void update(GraphType *G, FILE *fp) //���¾�����Ϣ
{
	int num0, num; //num0 ������ ��num ������Ϣ���
	fp = fopen("D:\\file.txt", "at+");  //���ļ���aָд�봦���ʱ�����ļ���������д�룬tָ���ı�����Ϊ�ı��ļ���+ָ���ļ���ȡ+д��
	printf("���������޸ľ�����:");
	scanf("%d", &num0);
	printf("��Ҫ���ĵ���1������  2�����\n�������ţ�");
	scanf("%d", &num);
	switch (num)
	{
	case 1:
		printf("�������޸ĺ������:");
		scanf("%s", G->vertexs[num0].name);
		break;
	case 2:
		printf("�������޸ĺ�Ľ���:");
		scanf("%s", G->vertexs[num0].introduction);
		break;
	}
	fclose(fp);  //�رո�ָ��
}

void menu()
{
	printf("��������������������������������������������������������������������������������\n");
	printf("��                               ������������                                 ��\n");
	printf("��                               �� �˵��� ��                                 ��\n");
	printf("��                               ������������                                 ��\n");
	printf("�� ����������������������������                ����������������������������   ��\n");
	printf("�� ��       0.�˳�ϵͳ       ��                ��     1.��ѯ������Ϣ     ��   ��\n");
	printf("�� ����������������������������                ����������������������������   ��\n");
	printf("�� ����������������������������                ����������������������������   ��\n");
	printf("�� �� 2.��ѯ�����������·�� ��                ��3.��ѯ�������������·����   ��\n");
	printf("�� ����������������������������                ����������������������������   ��\n");
	printf("�� ����������������������������                ����������������������������   ��\n");
	printf("�� ��       4.���¾���       ��                ��          5.��¼        ��   ��\n");
	printf("�� ����������������������������                ����������������������������   ��\n");
	printf("�� ����������������������������                ����������������������������   ��\n");
	printf("�� ��         6.ע��         ��                ��      7.�Ƽ�����·��    ��   ��\n");
	printf("�� ����������������������������                ����������������������������   ��\n");
	printf("��                                                                            ��\n");
	printf("��    ע��                                                                    ��\n");
	printf("��        ����ע���Ϊ����Ա�ſ�ִ��4                                         ��\n");
	printf("��                                                                            ��\n");
	printf("��������������������������������������������������������������������������������\n");
	printf("\n");
}
void map()
{
	printf("��������������������������������������������������������������������������������\n");
	printf("��                                                                            ��\n");
	printf("��                                         ��������������������������         ��\n");
	printf("��                                         ��       9.��Ӿ��       ��         ��\n");
	printf("��            ���������������������������� ��                      ��         ��\n");
	printf("��            ��                      ��   ��������������������������         ��\n");
	printf("��            ��                      ��               ��                     ��\n");
	printf("��      ��������     10. ����¥       ��   ��������������������������         ��\n");
	printf("��11.   ��    ��         6-16         ��   ��                      ��         ��\n");
	printf("����������������                      ���� ��       8.�ﾶ��       ��         ��\n");
	printf("����ѧ�����Щ���                      ���� ��                      ��         ��\n");
	printf("������������������������������������������ ��                      ��         ��\n");
	printf("��    ��            ��                     ��                      ��         ��\n");
	printf("���������������������������������������� ����������������������������         ��\n");
	printf("����  12.   ����13.     ����    ��            ��              ��              ��\n");
	printf("���� ����¥ ���� ��ܰԷ �� ��������������  �������������� ��������������      ��\n");
	printf("����  1-5   ���� ����Է ��_��5.�ۺ�¥  ��  ��          �� ��          ��      ��\n");
	printf("����        �������������� ���ڶ����ֲ�������          �� ��          ��      ��\n");
	printf("������������������         ��������������  ��          �� ��          ��      ��\n");
	printf("��     ��     ��               ��          ��          �� ��          ��      ��\n");
	printf("��     ��     ��          ��������������   ��          ��_��          ��      ��\n");
	printf("��  ������������������������4.ͼ���  �� ����6. ������ �� ��          ��      ��\n");
	printf("��  ��  14.     ��        ��������������   ��          �� ��7. ��ѧ¥ ��      ��\n");
	printf("��  ��          ��             ��          ��          �� ��          ��      ��\n");
	printf("��  ��    ���  ��        ��������������   ��          �� ��          ��      ��\n");
	printf("��  ������������������������3. ��ѧ¥ ��   ��          �� ��          ��      ��\n");
	printf("��     ��                 ��    1-4   ��   �������������� ��  9-18    ��      ��\n");
	printf("��     ��                 ��          ��     ��           ��          ��      ��\n");
	printf("��     ��                 ��������������     ��           ��          ��      ��\n");
	printf("��     ��                           ��       ��           ��          ��      ��\n");
	printf("��     ��                          ����������������       ��          ��      ��\n");
	printf("��     ��                          ��2. ú̿¥   ��       ��          ��      ��\n");
	printf("��     ��                          ����������������       ��          ��      ��\n");
	printf("��     ��                          ��   ����¥   ��       ��          ��      ��\n");
	printf("��      ��������������������       ����������������       ��          ��      ��\n");
	printf("��                         ��       ��                    ��          ��      ��\n");
	printf("��                         ��       ��                    ��������������      ��\n");
	printf("��                         ��       ��                                        ��\n");
	printf("��                       ����������������������                               ��\n");
	printf("��                       ��   1. ѧУ����    ��                               ��\n");
	printf("��                       ����������������������                               ��\n");
	printf("��������������������������������������������������������������������������������\n");
	printf("\n");
	//	fflush(stdin);      //������뻺����
}
void LogOn()  //����Ա��¼ϵͳ
{
	FILE *fp;
	int len = 0;
	printf("�������˺�:");
	scanf("%s", name);
	printf("����������:");
	scanf("%s", pass);
	strcat(name, pass);    //�ַ������� 
	strcat(name, "\n");
	fp = fopen("D:\\users0.txt", "at+");
	if (NULL == fp)
	{
		printf("failed to open users0.txt\n");
	}

	while (!feof(fp))  //�ļ�ָ�뵽ĩβ������ֵΪ����
	{
		memset(textstring, 0, sizeof(textstring));  //��ʼ��textstring[]
		fgets(textstring, sizeof(textstring) - 1, fp); //��ָ���ļ���һ���ַ������ַ�������
		if (strcmp(name, textstring) == 0)  //�ַ����Ƚ�
		{
			ok = 1;
			break;
		}
	}
	if (ok)
		printf("    ��¼�ɹ�!\n");
	else
		printf("    ��¼ʧ��!\n");
	fclose(fp);

}
void SignUp()
{
	FILE *fp = fopen("D:\\users0.txt", "at+");
	printf("�������˺�:");
	scanf("%s", name);
	printf("����������:");
	scanf("%s", pass);
	fputs(name, fp);
	fputs(pass, fp);
	fputs("\n", fp);
	fflush(stdin);
	fclose(fp);
	printf("ע��ɹ������¼:\n");
	LogOn();
}
void run()
{
	int m, n;
	GraphType *G;
	AdjList *g;
	G = (GraphType *)malloc(sizeof(GraphType));
	g = (AdjList *)malloc(sizeof(AdjList));
	G = create(G);
	g = list(G, g);
	map();
	while (stop)
	{
		menu();
		printf("\n���������������һ��������");
		scanf("%d", &n);
		switch (n)
		{
		case 0:stop = 0;
			printf("\n\t���˳�\n\n"); break;
		case 1:inquiry(G);
			printf("\n"); break;
		case 2:floyd(G);
			printf("\n"); break;
		case 3:GetAllPath(G, g);
			printf("\n"); break;
		case 4:printf("����ע�����Ա!\n"); break;
		case 5:LogOn();
			if (ok)
			{
				menu();
				printf("\n���������������һ��������");
				scanf("%d", &m);
				switch (m)
				{
				case 0:stop = 0;
					printf("\n\t���˳�\n\n"); break;
				case 1:inquiry(G);
					printf("\n"); break;
				case 2:floyd(G);
					printf("\n"); break;
				case 3:GetAllPath(G, g);
					printf("\n"); break;
				case 4:update(G, fp);
					printf("\n"); break;
				case 7:printf("�Ƽ��������ȫ��·��Ϊ��\n");
					printf("ѧУ����-->ú̿¥/����¥-->��ѧ¥1-4-->ͼ���-->\n");
					printf("�ۺ�¥/�ڶ����ֲ�-->������-->��ѧ¥9-18-->�ﾶ��-->\n");
					printf("��Ӿ��-->����¥6-16-->ѧ������-->����¥1-5-->\n");
					printf("��ܰԷ������Է-->���-->ѧУ����-->end��\n");
					break;
				default:printf("error");
				}
			}
			break;
		case 6:SignUp();
			if (ok)
			{
				menu();
				printf("\n���������������һ��������");
				scanf("%d", &m);
				switch (m)
				{
				case 0:stop = 0;
					printf("\n\t���˳�\n\n"); break;
				case 1:inquiry(G);
					printf("\n"); break;
				case 2:floyd(G);
					printf("\n"); break;
				case 3:GetAllPath(G, g);
					printf("\n"); break;
				case 4:update(G, fp);
					printf("\n"); break;
				case 7:printf("�Ƽ��������ȫ��·��Ϊ��\n");
					printf("ѧУ����-->ú̿¥/����¥-->��ѧ¥1-4-->ͼ���-->\n");
					printf("�ۺ�¥/�ڶ����ֲ�-->������-->��ѧ¥9-18-->�ﾶ��-->\n");
					printf("��Ӿ��-->����¥6-16-->ѧ������-->����¥1-5-->\n");
					printf("��ܰԷ������Է-->���-->ѧУ����-->end��\n");
					break;
				default:printf("error");
				}
			}
			break;
		case 7:printf("�Ƽ��������ȫ��·��Ϊ��\n");
			printf("ѧУ����-->ú̿¥/����¥-->��ѧ¥1-4-->ͼ���-->\n");
			printf("�ۺ�¥/�ڶ����ֲ�-->������-->��ѧ¥9-18-->�ﾶ��-->\n");
			printf("��Ӿ��-->����¥6-16-->ѧ������-->����¥1-5-->\n");
			printf("��ܰԷ������Է-->���-->ѧУ����-->end��\n");
			break;
		default:printf("error!\n");
		}
	}
}
void main()
{
	run();
}