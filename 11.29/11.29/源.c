#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <conio.h>
#define maxn 100
struct node {
	char name[maxn];
	int daihao;
	int renshu;
	int fonud_year;
	char introduce[maxn];
}place[maxn];//�ص���Ϣ�ýṹ��  
int tishi();
void projcet();
void banquan();
int daihao(char *name, int n);//����������ֻ�Ϊ�ṹ������ 
int **creat_graph(int n, int m);//��������ͼ������ص���Ϣ��·�� 
int **Floyd(int **graph, int n);//���ø��������㷨����ÿ����֮������·���ľ��� 
int **Fpath(int **graph, int n);//���ø��������㷨����ÿ����֮������·����·�� 
void chaxun_luxian(int **graph, int **path, int n);//��ѯ����֮���һ����̵ļ�·��
void chaxun_jingdian(int n);//Ϊ���ÿ����ṩͼ�����⾰�������Ϣ�Ĳ�ѯ
void all_route(int **graph, int n);//�ṩͼ�����⾰��֮�������·��
void dfs(int **graph, int *stack, int *visited, int n, int a, int b, int top);//����dfs�㷨��ͼ�����������·�� 
int main()
{
	int i, j, choise, m, n;
	system("color F0");
	projcet();
	banquan();
	printf("�����뾰��������·��������\n");
	scanf("%d %d", &n, &m);//n�Ǿ������� m��·������	

	int **graph = creat_graph(n, m);
	int **fgraph = Floyd(graph, n);
	int **path = Fpath(graph, n);

	choise = tishi();
	while (choise) {
		if (choise == 1) chaxun_luxian(fgraph, path, n);
		else if (choise == 2) chaxun_jingdian(n);
		else if (choise == 3) all_route(graph, n);
		else printf("\n��������ȷ����\n");
		system("pause");
		system("cls");
		choise = tishi();
	}

	return 0;

}
int **Fpath(int **graph, int n) {//���ø��������㷨����ÿ����֮������·����·�� 
	int i, k, j, g[maxn][maxn] = { 0 };
	int **path = (int **)malloc(n * sizeof(int *));
	for (i = 0; i < n; i++)
		path[i] = (int *)malloc(n * sizeof(int));

	for (i = 0; i < n; i++)
		for (j = 0; j < n; j++) {
			g[i][j] = graph[i][j];
			path[i][j] = j;
		}

	for (k = 0; k < n; k++)
		for (i = 0; i < n; i++)
			for (j = 0; j < n; j++) {
				if (g[i][j] > g[i][k] + g[k][j]) {
					g[i][j] = g[i][k] + g[k][j];
					path[i][j] = path[i][k];
				}
			}
	return path;
}
int **Floyd(int **graph, int n) {//���ø��������㷨����ÿ����֮������·���ľ��� 

	int i, k, j;
	int **g = (int **)malloc(n * sizeof(int *));
	for (i = 0; i < n; i++)
		g[i] = (int *)malloc(n * sizeof(int));

	for (i = 0; i < n; i++)
		for (j = 0; j < n; j++) {
			g[i][j] = graph[i][j];
		}

	for (k = 0; k < n; k++)
		for (i = 0; i < n; i++)
			for (j = 0; j < n; j++) {
				if (g[i][j] > g[i][k] + g[k][j]) {
					g[i][j] = g[i][k] + g[k][j];
				}
			}
	return g;
}
void chaxun_jingdian(int n) {//Ϊ���ÿ����ṩͼ�����⾰�������Ϣ�Ĳ�ѯ
	char x[maxn];
	int i, a = -1;
	printf("\n�������ѯ���㣺\n");
	scanf("%s", &x);
	a = daihao(x, n);
	if (a == -1) {
		printf("\n��Ǹ������ѯ�ĵ�ַ����\n"); return;
	}
	printf("\n������ţ�%d\n", place[a].daihao);
	printf("����������%d\n", place[a].renshu);
	printf("����ʱ�䣺%d\n", place[a].fonud_year);
	printf("���ܣ�%s\n", place[a].introduce);
}
void chaxun_luxian(int **graph, int **path, int n) {	//��ѯ����֮���һ����̵ļ�·��
	char x[maxn], y[maxn];
	int i, a = -1, b = -1;
	printf("\n�������ѯ���㣺\n");
	scanf("%s %s", &x, &y);
	a = daihao(x, n);
	b = daihao(y, n);
	if (a == -1 || b == -1) {
		printf("\n��Ǹ������ѯ�ĵ�ַ����\n"); return;
	}
	printf("\n%s �� %s ����̾���Ϊ��%d m\n", x, y, graph[a][b]);
	printf("\n%s �� %s ����̾���·���ǣ�\n", x, y);
	printf("%s-->", place[a].name);
	while (path[a][b] != b) {
		printf("%s-->", place[path[a][b]].name);
		a = path[a][b];
	}
	printf("%s\n", place[path[a][b]].name);
}

void all_route(int **graph, int n) {//�ṩͼ�����⾰��֮�������·��
	char x[maxn], y[maxn];
	int i, j, a = -1, b = -1, top;
	printf("\n�������ѯ���㣺\n");
	scanf("%s %s", &x, &y);
	a = daihao(x, n);
	b = daihao(y, n);
	if (a == -1 || b == -1) {
		printf("\n��Ǹ������ѯ�ĵ�ַ����"); return;
	}
	top = 0;
	int *stack = (int *)malloc(sizeof(int)*maxn);
	int *visited = (int *)malloc(sizeof(int)*maxn);
	memset(visited, 0, sizeof(int)*maxn);
	printf("\n%s �� %s ������·���ǣ�\n", x, y);
	dfs(graph, stack, visited, n, a, b, top);

}
void dfs(int **graph, int *stack, int *visited, int n, int a, int b, int top) {//����dfs�㷨��ͼ�����������·�� 
	int i, j;
	stack[top++] = a;
	visited[a] = 1;//��Ǳ����ʹ� 
	for (i = 0; i < n; i++) {
		if (graph[a][i] < maxn) {

			if (i == b) {	// �ҵ��յ�	
				for (j = 0; j < top; j++)
					printf("%s-->", place[stack[j]].name);
				printf("%s\n", place[b].name);
				top--;
				visited[a] = 0;
				break;
			}
			if (!visited[i]) {// δ�����ʹ� 
				dfs(graph, stack, visited, n, i, b, top);
			}
		}

		if (i == n - 1) {// ����ö������������� 
			top--;
			visited[a] = 0;
		}
	}
	void projcet() {
		printf("******************\n");
		printf("*  У԰������ѯ  *\n");
		printf("******************\n\n");
	}
	void banquan() {
		printf("��һ��\n");
		printf("\t184804013 ����\n");
		printf("\t184804005 ��С��\n");
		printf("\t184804010 ��پ��\n\n");
	}
	int tishi() {
		int choise;
		projcet();
		printf("\n��ѡ�����Ĳ�����\n");
		printf("|=============================|\n");
		printf("|(1) ��ѯ�����������·��-----|\n");
		printf("|(2) ��ѯ������Ϣ-------------|\n");
		printf("|(3) ��ѯ������������·��-----|\n");
		printf("|(0) �˳�---------------------|\n");
		printf("|=============================|\n\n");
		scanf("%d", &choise);
		return choise;
	}
	int daihao(char *name, int n) { //����������ֻ�Ϊ�ṹ������
		int i, a;
		for (i = 0; i < n; i++) {
			if (!strcmp(name, place[i].name))
				a = i;
		}
		return a;
	}
	int **creat_graph(int n, int m) {//��������ͼ������ص���Ϣ��·�� 
		int i, j, t, f, x, y, k, distance;

		int **graph = (int **)malloc(n * sizeof(int *));
		for (i = 0; i < n; i++)
			graph[i] = (int *)malloc(n * sizeof(int));

		for (i = 0; i < n; i++)
			for (j = 0; j < n; j++) {
				graph[i][j] = maxn;
			}	//��ʼ��

		printf("\n������ص���Ϣ\n");
		for (i = 0; i < n; i++) {
			scanf("%s %d %d %d %s", &place[i].name, &place[i].daihao, &place[i].renshu, &place[i].fonud_year, &place[i].introduce);
		}	//����ص���Ϣ	
		printf("\n���������ͨ·��\n");
		for (i = 0; i < m; i++) {
			scanf("%d %d %d", &x, &y, &distance);
			graph[x][y] = graph[y][x] = distance;
		} 	//����·����Ϣ 

		system("pause");
		system("cls");
		return graph;

	}
}