#include<stdio.h>
#include<string.h>
#include<stdlib.h>
typedef struct Student{
    int stuid;//学生学号
	int stuAge;//学生年龄
	char stuName[100];//学生姓名
	float score;//100分制
	int weight;//
	int height;//cm
	struct Student *next;
}stu;

struct Student *head=NULL;


void add()
{
	stu *q=(stu*)malloc(sizeof(stu));
	q->next=NULL;
	printf("请输入学生学号：");
	scanf("%d",&q->stuid);
	printf("请输入学生年龄：");
	scanf("%d",&q->stuAge);
	printf("请输入学生姓名：");
	scanf("%s",q->stuName);
	printf("请输入学生分数：");
	scanf("%f",&q->score);
	printf("请输入学生体重: ");
	scanf("%d",&q->weight);
	printf("请输入学生身高：");
	scanf("%d",&q->height);
	if(head==NULL) head=q;
	else
	{
		q->next=head;
		head=q;
	}
	printf("添加成功\n");
}
void print()
{
	stu *p=head;
	while(p!=NULL)
	{
		printf("%d %d %s %f %d %d\n",p->stuid,p->stuAge,p->stuName,p->score,p->weight,p->height);
		p=p->next;
	}
	if(p==NULL)
	{
		printf("1\n");
	}
}
void find()
{
	printf("请输入要查找的名字：");
	char name[100]={'\0'};
	scanf("%s",name);
	stu *curP=head;
	while(curP!=NULL)
	{
		if(strcmp(curP->stuName,name)==0)
		{
			printf("%d %d %s %f %d %d\n",curP->stuid,curP->stuAge,curP->stuName,curP->score,curP->weight,curP->height);
			return;
		}
		else
		{
			curP=curP->next;
		}
	}
	printf("对不起，查无此人\n");
}
void delete1()
{	
	if(head==NULL)
	{
		printf("程序内没有学生信息\n");
		return;
	}
	struct Student *p,*q;
	int id;
	printf("请输入你要查找的学号：\n");
	scanf("%d",&id);
	p=head;
	while(p->stuid!=id&&p->next!=NULL)
	{
		q=p;
		p=p->next;
	}
	if(id==p->stuid)
	{
		if(p==head)
		{
			head=p->next;
		}
		else
		{
			q->next=p->next;
		}
		printf("删除成功!\n");
	}
	

}
void exit()
{
  printf("程序结束\n");
}


int main()
{
	
	int number;
	printf("欢迎使用简易学生管理系统\n");

    printf("输入数字1添加学生信息\n");
	printf("输入数字2查询学生信息\n");
    printf("输入数字3删除学生信息\n");
    printf("输入数字4打印学生信息\n");
    printf("输入数字5关闭此程序\n");
	printf("请输入以上的任意一个数字\n");
	
    while(number!=5)
	{
	scanf("%d",&number);
	switch(number)
	{
	case 1:
		add();
		break;
	case 2:
		find();
		break;
	case 3:
		delete1();
		break;
	case 4:
		print();
		break;
	case 5:
		exit();
		break;
	}
	}
	return 0;

}