#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
#include<stdlib.h>

typedef int ElemType;
/*结构体部分*/
typedef struct Node
{
	ElemType data;   //数值域
	struct Node *next;  //指针域
}Linklist;

Linklist *InitList(Linklist *L)    //初始化单链表
{
	L = (Linklist *)malloc(sizeof(Linklist));
	L->next = NULL;
	return L;
}
//创建单链表
Linklist *CreateList(int n)
{
	/*通过输入n个数据，创建一个单链表*/
	int x, i;
	Linklist *L, *r, *p;
	L = InitList(L); //构造头结点
	r = L;
	printf("input %d value: ", n);
	for (i = 0; i < n; i++)
	{
		scanf("%d", &x);
		p = (Linklist *)malloc(sizeof(Linklist));
		p->data = x;
		p->next = NULL;
		r->next = p;
		r = r->next;    //指针r始终指向链表中末数据元素所在位置

	}
	return L;
}

int InsItem1(Linklist *L, ElemType item, int x) /*给定的序号来插入*/
{
	int i = 1;
	Linklist *p, *t;
	p = L;
	t = (Linklist *)malloc(sizeof(Linklist));
	t->data = item;
	if (L->next == NULL)
	{   /*若L为空表且要求将新结点插入到第0个位置*/
		if (x == 1)
		{
			L->next = t;
			t->next = NULL;
			return 1;
		}
		/*若L为空表且要求将新结点插入到第非0个位置     ，则操作失败*/
		else
		{
			printf("wrong!\n");
			return 0;
		}
	}
	while (p->next != NULL && i < x)
		/*查找第i个节点*/
	{
		p = p->next;
		i++;
	}
	if (p->next == NULL && i < x)
		/*在表中不存在插入位置i ，找不到，则插入操作失败*/
	{
		printf("The node %d is not exist\n", x);
		return 0;
	}
	else
	{
		t->next = p->next;
		p->next = t;
		return 1;
	}
}
//插入链表
int InsItem2(Linklist *L, ElemType item, ElemType k) /*插入给定值在链表中的位置*/
{
	Linklist *q, *p, *t;
	t = (Linklist *)malloc(sizeof(Linklist));
	t->data = item;
	if (L->next == NULL)
	{
		printf("The linklist is empty\n");
		return 0;
	}
	else
	{
		q = L;
		p = L->next;
		while (p->next != NULL)/*查找值为k的结点*/
		{
			if (p->data != k)
			{
				q = p;
				p = p->next;
			}
			else
				break;
		}
		if (p == NULL)/*如p= =NULL，则没有值为k的结点，插入操作失败*/
		{
			printf("The node %d is not exist\n", k);
			return 0;
		}
		else
		{
			q->next = t;
			t->next = p;
			return 1;
		}
	}
}
//删除链表
int DelItem(Linklist *L, int x)
//在单链表中删除数据元素
{
	int i = 1;
	Linklist *p, *q;
	p = L;
	if (L->next == NULL) /*L为空表，无结点可删除*/
	{
		printf("The linklist is empty!\n");
		return 0;
	}
	while (p->next != NULL && i < x)
	{
		p = p->next;
		i++;
	}
	if (p->next == NULL)
		/*若没有第i个结点，则删除操作失败*/
	{
		printf("The node %d is not exist\n", x);
		return 0;
	}
	else
	{
		q = p->next;
		p->next = p->next->next;
		free(q);
		return 1;
	}

}
//查找链表
int LocItem(Linklist *L, ElemType x)
//查找给定值的结点位置
{
	Linklist *p, *q, *r;
	int i = 1;
	if (L->next == NULL)
	{
		printf("The linklist is empty\n");
		return 0;
	}
	else
	{
		p = L->next;
		while (p != NULL)
		{
			if (p->data != x)
			{
				i++;
				p = p->next;
			}
			else
				break;
		}
		if (p == NULL)
			/*如p= =NULL，则没有值为item的结点，删除操作失败*/
		{
			printf("The node %d is not exist\n", x);
			return 0;
		}
		/*若找到该节点返回该节点的位置*/
		else
			return i;
	}
}
//输出函数
void put(Linklist *L) //输出
{
	Linklist *p;
	p = L->next;
	printf("output element: \n");
	for (; p != NULL; p = p->next)
	{
		printf(" %d ", p->data);
	}
	printf("\n");
}
//主函数
int main()
{
	ElemType x = 5;
	ElemType k;
	Linklist *L;
	L = CreateList(x);
	put(L);
	printf("请输入一个数字:");
	scanf("%d", &k);
	InsItem1(L, k, 2);
	put(L);
	InsItem1(L, k, 4);
	put(L);
	DelItem(L, k);
	put(L);
	printf("%d的位置是: %d",k,LocItem(L, k));
}
