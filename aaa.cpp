#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int n=0;
struct worker 
{
    char name[20];            //����
    char num[20];             //ְ����
    char bumen[20];           //ְ������
    char zhiwei[20];          //ְ��ְλ
    int wage;                 //����
}s[10];
void add()                    //���
{
	loop1:
	int p;
    printf("������ѧ��������Ϣ��\n������");
    scanf("%s",&s[n].name);
    printf("ְ���ţ�");
    scanf("%s",&s[n].num);
    printf("ְ�����ţ�");
    scanf("%s",&s[n].bumen);
    printf("ְ��ְλ��");
    scanf("%s",&s[n].zhiwei);
    printf("���ʣ�");
    scanf("%d",&s[n].wage);
    printf("�Ƿ��������ְԱ��Ϣ������������1��ֹͣ������0��\n");
    scanf("%d",&p);
    if(p==1)
    {
    	n++;
    	goto loop1;
	}
	else if(p==0)
	{
		printf("���������Ϣ�ѱ�����!\n");
	}
	else
	{
		printf("����������1��0��");
	}
}
void print()
{
    int i;
    for(i=0;i<10;i++)
    {
        printf("������%s  ",s[i].name);
        printf("ְ���ţ�%s  ",s[i].num);
        printf("ְ�����ţ�%s  ",s[i].bumen);
        printf("ְ��ְλ��%s  ",s[i].zhiwei);
        printf("���ʣ�%d  ",s[i].wage);
        printf("\n");
    }
    printf("\n��Ϣ��ʾ���!\n");
}
void find()           //����
{
    void find1();
    void find2();
    int a;
    printf("1.����������\n2.��ְ���Ų�ѯ\n");
    scanf("%d",&a);
    switch(a)
    {
    case 1:
        find1();
        break;
    case 2:
        find2();
        break;
    }
}
void Delete()         //ɾ��
{
    int i;
    char a[20];
    printf("������Ҫɾ����ְ����:\n");
    scanf("%s",&a);
    for(i=0;i<n;i++)
        if(strcmp(a,s[i].num)==0)
        {
            while(i<n)
            {
                s[i]=s[i+1];
                i++;
            }
            n-=1;
        }
    printf("ɾ������ִ����ϣ�\n");
}
void find1()
{
    int i;
    char a[20];
    printf("��ѡ��������ѯ��������Ҫ��ѯ��������\n");
    scanf("%s",&a);
    for(i=0;i<n;i++)
    {
        if(strcmp(a,s[i].name)==0)
        {
            printf("������%s\n",s[i].name);
          	printf("ְ���ţ�%s\n",s[i].num);
            printf("ְ�����ţ�%s\n",s[i].bumen);
            printf("ְ��ְλ��%s\n",s[i].zhiwei);
            printf("���ʣ�%d\n",s[i].wage);
            printf("\n");
        }
    }
 
}
void find2()
{
    int i;
    char a[20];
    printf("��ѡ��ְ���Ų�ѯ��������Ҫ��ѯ��ְ���ţ�\n");
    scanf("%s",&a);
    for(i=0;i<n;i++)
    {
        if(strcmp(a,s[i].num)==0)
        {
            printf("������%s\n",s[i].name);
          	printf("ְ���ţ�%s\n",s[i].num);
            printf("ְ�����ţ�%s\n",s[i].bumen);
            printf("ְ��ְλ��%s\n",s[i].zhiwei);
            printf("���ʣ�%d\n",s[i].wage);
            printf("\n");
        }
    }
}
int main()       //������
{
    int a=1;
    while(1)
    {
        if(a>=1&&a<=5)
        {
        	printf("------------------------------------------------------------\n");
			printf("��������ﻶӭ���빫˾ְ����Ϣ���������������\n");
			printf("------------------------------------------------------------\n");
			printf("�x�y�z�|�}�~�~�|�z�y�x�������Ĳ˵����:�x�y�z�|�}�~�~�|�z�y�x\n");
			printf("		      1. ����ְ����Ϣ\n");
            printf("		      2. ��ʾְ����Ϣ\n");
            printf("		      3. ����ְ����Ϣ\n");
            printf("		      4. ɾ��ְ����Ϣ\n");
            printf("		      5. �˳��������\n");
			printf("��ѡ��");
            scanf("%d",&a);
            switch(a)
            {
            case 1:
                add();
                break;
            case 2:
                print();
                break;
            case 3:
                find();
                break;
            case 4:
                Delete();
                break;                                                                     
		    case 5:
                return 0;
            }
        }
        else
        {
            printf("������Ĳ�����Ҫ�����������Ҫ������ַ������˵�!");
            scanf("%d",&a);
        }
    }
}


