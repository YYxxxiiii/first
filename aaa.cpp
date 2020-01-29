#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int n=0;
struct worker 
{
    char name[20];            //名字
    char num[20];             //职工号
    char bumen[20];           //职工部门
    char zhiwei[20];          //职工职位
    int wage;                 //工资
}s[10];
void add()                    //添加
{
	loop1:
	int p;
    printf("请输入学生基本信息：\n姓名：");
    scanf("%s",&s[n].name);
    printf("职工号：");
    scanf("%s",&s[n].num);
    printf("职工部门：");
    scanf("%s",&s[n].bumen);
    printf("职工职位：");
    scanf("%s",&s[n].zhiwei);
    printf("工资：");
    scanf("%d",&s[n].wage);
    printf("是否继续输入职员信息？继续请输入1，停止请输入0。\n");
    scanf("%d",&p);
    if(p==1)
    {
    	n++;
    	goto loop1;
	}
	else if(p==0)
	{
		printf("您输入的信息已被保存!\n");
	}
	else
	{
		printf("错误！请输入1或0！");
	}
}
void print()
{
    int i;
    for(i=0;i<10;i++)
    {
        printf("姓名：%s  ",s[i].name);
        printf("职工号：%s  ",s[i].num);
        printf("职工部门：%s  ",s[i].bumen);
        printf("职工职位：%s  ",s[i].zhiwei);
        printf("工资：%d  ",s[i].wage);
        printf("\n");
    }
    printf("\n信息显示完毕!\n");
}
void find()           //查找
{
    void find1();
    void find2();
    int a;
    printf("1.按姓名查找\n2.按职工号查询\n");
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
void Delete()         //删除
{
    int i;
    char a[20];
    printf("请输入要删除的职工号:\n");
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
    printf("删除程序执行完毕！\n");
}
void find1()
{
    int i;
    char a[20];
    printf("您选择按姓名查询，请输入要查询的姓名：\n");
    scanf("%s",&a);
    for(i=0;i<n;i++)
    {
        if(strcmp(a,s[i].name)==0)
        {
            printf("姓名：%s\n",s[i].name);
          	printf("职工号：%s\n",s[i].num);
            printf("职工部门：%s\n",s[i].bumen);
            printf("职工职位：%s\n",s[i].zhiwei);
            printf("工资：%d\n",s[i].wage);
            printf("\n");
        }
    }
 
}
void find2()
{
    int i;
    char a[20];
    printf("您选择按职工号查询，请输入要查询的职工号：\n");
    scanf("%s",&a);
    for(i=0;i<n;i++)
    {
        if(strcmp(a,s[i].num)==0)
        {
            printf("姓名：%s\n",s[i].name);
          	printf("职工号：%s\n",s[i].num);
            printf("职工部门：%s\n",s[i].bumen);
            printf("职工职位：%s\n",s[i].zhiwei);
            printf("工资：%d\n",s[i].wage);
            printf("\n");
        }
    }
}
int main()       //主函数
{
    int a=1;
    while(1)
    {
        if(a>=1&&a<=5)
        {
        	printf("------------------------------------------------------------\n");
			printf("★★★★★★★★欢迎进入公司职工信息管理程序★★★★★★★★\n");
			printf("------------------------------------------------------------\n");
			printf("▁▂▃▅▆▇▇▅▃▂▁输入您的菜单序号:▁▂▃▅▆▇▇▅▃▂▁\n");
			printf("		      1. 增加职工信息\n");
            printf("		      2. 显示职工信息\n");
            printf("		      3. 查找职工信息\n");
            printf("		      4. 删除职工信息\n");
            printf("		      5. 退出管理程序\n");
			printf("请选择：");
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
            printf("您输入的不符合要求，请输入符合要求的数字返回主菜单!");
            scanf("%d",&a);
        }
    }
}


