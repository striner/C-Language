#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <conio.h>
#define MAX 20
int N = 0;
typedef struct student//学生信息结构体类型
{
	char name[20];
	char num[9];
	char sex[8];
	int age;
	char Class[20];
	char phone[20];
	char addr[20];
}STUDENT;
int read_file (STUDENT stu[])//数据读写
{
	FILE *fp;
	int i=0;
	int stuCount = 0;
	if((fp=fopen("student.txt","rb"))==NULL)
	{
		printf("\n\n ********暂时还没有任何学生信息，按任意键进入主菜单选择基本信息的录入！********\n");
		getch();
		return 0;
	}

	fread(&stu[i], sizeof(STUDENT), 1, fp);
	while(!feof(fp)){
		i++;
		stuCount++;
		fread(&stu[i], sizeof(STUDENT), 1, fp);
	}
    fclose(fp);
	return stuCount;
}
void save_file (STUDENT stu[])//数据存储
{
	FILE *fp;
	int i;
	if((fp=fopen("student.txt","wb"))==NULL)
	{
		printf("读文件错误!\n");
		return;
	}
	for(i=0;i<N;i++)
	if(fwrite(&stu[i],sizeof(STUDENT),1,fp)!=1)
	printf("写文件错误！\n");
	fclose(fp);
}
int input (STUDENT stu[])//数据录入
{
	int i=0,flag;
	char choice;
	system("cls");
	printf("\n 录入学生的信息:\n",i);
	printf ("* * * * * * * * * * * * \n");
	do
	{
    printf("\n第%d个学生的信息:\n",i+1);
	printf("\n姓名:");
	flushall();//清除缓存区
	scanf("%s",stu[i].name);
	printf("\n学号:");
	flushall();
	scanf("%s",stu[i].num);
	printf("\n性别:");
	flushall();
	scanf("%s",&stu[i].sex);
    printf("\n年龄:");
	flushall();
    scanf("%d",&stu[i].age);
	printf("\n班级:");
	flushall();
	scanf("%s",stu[i].Class);
	printf("\n联系电话:");
	flushall();
	scanf("%s",stu[i].phone);
	printf("\n家庭住址:");
	flushall();
	scanf("%s",stu[i].addr);
	N=i+1;
    i++;
	printf("继续吗?(Y/N)");
	choice=getch();
	if (choice=='y'||choice=='Y')
	{
		flag=1;
		printf("\n继续!\n");
	}
	else flag=0;
	}while(flag==1);
	printf ("\n**学生信息输入完毕！**\n\n");
	printf ("\n 按任意键返回主菜单！");
    getchar();
	return i;
}
void output (STUDENT stu[])//数据输出
{
	int i=0;
	system("cls");
	printf(" 姓名 \t   学号        性别      年龄      班级     联系电话    家庭住址\n  ");
	printf("-----------------------------------------------------------------------");
	do
	{	
		printf("\n %s \t%s\t%s\t  %d\t   %s\t      %s\t  %s\n",stu[i].name,stu[i].num,stu[i].sex,stu[i].age,stu[i].Class,stu[i].phone,stu[i].addr);
	    i++;
	} while (i<N);
	printf ("按任意键返回主菜单！");
	flushall();getchar();
}
void append (STUDENT stu[])//信息添加
{
	int i = N,flag=0;
	char choice;
	system("cls");
	printf("\n\n         输入添加学生的信息\n");
	printf("         -----------------------\n");
	do
	{
		printf("\n         输入被添加学生的信息\n");
		printf("\n               姓名：");
		flushall();scanf("%s",stu[i].name);
		printf("\n               学号：");
		flushall();scanf("%s",stu[i].num);
		printf("\n               性别：");
		flushall();scanf("%s",&stu[i].sex);
		printf("\n               年龄：");
		flushall();scanf("%d",&stu[i].age);
		printf("\n               班级：");
		flushall();scanf("%s",stu[i].Class);
		printf("\n               联系电话：");
		flushall();scanf("%s",stu[i].phone);
		printf("\n               家庭住址：");
		flushall();scanf("%s",stu[i].addr);
		printf("\n               要继续吗?(Y/N)");
		flushall();choice=getchar();
		N++;
		
		if (choice=='y'||choice=='Y')
		{
			printf("\n            继续!\n");
			i++;
			flag=1;
		}
		else flag=0;
	}while(flag==1);
	printf("\n               按任意键返回主菜单！");
	flushall();flushall();flushall();flushall();flushall();flushall();flushall();flushall();flushall();getchar();
}
void modify (STUDENT stu[])//信息修改
{
	int i=0,choice,flag;
	char modify_num[9];
	do
	{
		system("cls");
		printf("\n输入要修改学生的学号：");
		scanf ("%s",modify_num);
		for (i=0;i<N;i++)
			if (strcmp(stu[i].num,modify_num)==0)
			{
				printf("\n--学生信息--\n");
				printf(" 姓名 \t   学号        性别      年龄      班级     联系电话    家庭住址\n  ");
		        printf("-----------------------------------------------------------------\n");
				printf("\n %s \t%s\t%s\t  %d\t   %s\t      %s\t  %s\n",stu[i].name,stu[i].num,stu[i].sex,stu[i].age,stu[i].Class,stu[i].phone,stu[i].addr);
				printf("\n你想修改哪一项?\n");
				printf("\n1.姓名\n");
				printf("\n2.学号\n");
				printf("\n3.性别\n");
				printf("\n4.年龄\n");
				printf("\n5.班级\n");
				printf("\n6.联系电话\n");
				printf("\n7.家庭住址\n");
				printf("\n请选择(1-7):");
				flushall();scanf("%d",&choice);
				switch(choice)
				{
				case 1:printf("\n输入修改后的姓名:");
					flushall();
					scanf("%s",stu[i].name);break;
				case 2:printf("\n输入修改后的学号:");
					flushall();
					scanf("%s",stu[i].num);break;
				case 3:printf("\n输入修改后的性别:");
					flushall();
					scanf("%s",stu[i].sex);break;
				case 4:printf("\n输入修改后的年龄:");
					flushall();
					scanf("%d",&stu[i].age);break;
				case 5:printf("\n输入修改后的班级:");
					flushall();
					scanf("%s",stu[i].Class);break;
				case 6:printf("\n输入修改后的联系电话:");
					flushall();
					scanf("%s",stu[i].phone);break;
				case 7:printf("\n输入修改后的家庭住址:");
					flushall();
					scanf("%s",stu[i].addr);break;
				}
				printf("\n--学生信息--\n");
				printf(" 姓名 \t   学号        性别      年龄      班级     联系电话    家庭住址\n  ");
		        printf("-----------------------------------------------------------------\n");
				printf("\n %s \t%s\t%s\t  %d\t   %s\t      %s\t  %s\n",stu[i].name,stu[i].num,stu[i].sex,stu[i].age,stu[i].Class,stu[i].phone,stu[i].addr);
				break;
			}
			if(i==N)
			{
				printf("\n该学生不存在！");
				getchar();
			}
			printf("\n\n想继续修改吗?(Y/N)");
			choice=getch();
			if (choice=='y'||choice=='Y')
			{
				flag=1;
				printf("\n继续!\n");
			}
			else flag=0;
	}while(flag==1);
	printf("\n按任意键返回主菜单!");
	getchar();
}
void del (STUDENT stu[])//信息删除
{
	int i;
	char del_num[9];
	printf("请输入所要删除的学生学号:");
	scanf("%s",del_num);
	for (i=0;i<N;i++)
		if (strcmp(stu[i].num,del_num)==0)
		{
			strcpy(stu[i].name,"o");
			strcpy(stu[i].num,"o");
			strcpy(stu[i].Class,"o");
			strcpy(stu[i].sex,"o");
			stu[i].age=0;
			strcpy(stu[i].addr,"o");
			strcpy(stu[i].phone,"o");
			printf("删除成功!\n\n");
			return;
		}
		else 
		{
			printf("未找到该学生!\n");
			flushall();flushall();flushall();flushall();flushall();flushall();flushall();flushall();flushall();getchar();
		}
}
void inquire (STUDENT stu[])//信息查询
{
	int n,i;
	char inquire_num[9];
	char inquire_name[20];
	char inquire_Class[20];
	int inquire_age;
	printf("********************************************************************************\n\n");
    printf("\n请选择查找方式:\n\n");
	printf("\t\t1.按学生姓名查找\n\n");
    printf("\t\t2.按学生学号查找\n\n");
    printf("\t\t3.按学生的班级查找\n\n");
    printf("\t\t4.按学生的年龄范围查找\n\n");
    printf("\t\t0.返回\n");
	printf("请输入需要的查询方式:");
	scanf("%d",&n);//读取查找方式
	switch(n)
	{
	case 1:
		    printf("请输入所查询的学生姓名:");
            scanf("%s",inquire_name);
		    for (i=0;i<N;i++)
			{
				if (strcmp(stu[i].name,inquire_name)==0)
				{
					printf(" 姓名 \t   学号        性别      年龄      班级     联系电话    家庭住址\n  ");
		            printf("-----------------------------------------------------------------\n");
			     	printf("\n %s \t%s\t%s\t  %d\t   %s\t      %s\t  %s\n",stu[i].name,stu[i].num,stu[i].sex,stu[i].age,stu[i].Class,stu[i].phone,stu[i].addr);
				}
				else 
					printf("\t%s\n","没有查询到该学生信息，请检查输入:");
			}
				flushall();getchar();
				break;
	case 2:
			printf("请输入所查询的学生学号:");
            scanf("%s",inquire_num);	
			for (i=0;i<N;i++)
			{
				if (strcmp(stu[i].num,inquire_num)==0)
				{
					printf(" 姓名 \t   学号        性别      年龄      班级     联系电话    家庭住址\n  ");
					printf("-----------------------------------------------------------------\n"); 
					printf("\n %s \t%s\t%s\t  %d\t   %s\t      %s\t  %s\n",stu[i].name,stu[i].num,stu[i].sex,stu[i].age,stu[i].Class,stu[i].phone,stu[i].addr);
				}
			else
				printf("\t%s\n","没有查询到该学生信息，请检查输入:");
			}
			flushall();getchar();
			break;
	case 3:
			printf("请输入所查询的学生班级:");
            scanf("%s",inquire_Class);	
			for (i=0;i<N;i++)
			{
				if (strcmp(stu[i].Class,inquire_Class)==0)
				{
					printf(" 姓名 \t   学号        性别      年龄      班级     联系电话    家庭住址\n  ");
					printf("-----------------------------------------------------------------\n"); 
					printf("\n %s \t%s\t%s\t  %d\t   %s\t      %s\t  %s\n",stu[i].name,stu[i].num,stu[i].sex,stu[i].age,stu[i].Class,stu[i].phone,stu[i].addr);
				}
			else
				printf("\t%s\n","没有查询到该学生信息，请检查输入:");
			}
			flushall();getchar();
			break;
	case 4:
		    printf("请输入所查询的学生年龄:");
            scanf("%d",&inquire_age);	
			for (i=0;i<N;i++)
			{
				if (stu[i].age==inquire_age)
				{
					printf(" 姓名 \t   学号        性别      年龄      班级     联系电话    家庭住址\n  ");
					printf("-----------------------------------------------------------------\n"); 
					printf("\n %s \t%s\t%s\t  %d\t   %s\t      %s\t  %s\n",stu[i].name,stu[i].num,stu[i].sex,stu[i].age,stu[i].Class,stu[i].phone,stu[i].addr);
				}
			else
				printf("\t%s\n","没有查询到该学生信息，请检查输入:");
			}
			flushall();getchar();
			break;
	case 0:
		break;
	}
}
void count (STUDENT stu[])//信息统计
{
	int choice,s=0,C=0,i;
	char sex[8];
	char Class[20];
	system("cls");
	printf("********************************************************************************\n\n");
	printf("\t\t================1.性别=================\n\n");
	printf("\t\t================2.班级=================\n\n");
	printf("\t\t================0.返回=================\n\n");
    printf("********************************************************************************\n");
	printf("输入需要统计的内容:");
	flushall();scanf("%d",&choice);
	switch(choice)
	{
	case 1:
		printf("请输入所要统计的性别:");
		flushall();
		scanf("%s",sex);
		for(i=0;i<N;i++) 
		if(strcmp(stu[i].sex,sex)==0)
			s++;
		printf("\n\n   该性别人数是:%d\n",s);
		printf("\n\n   按任意键退出!");
		flushall();getchar();
		break;
	case 2:
		printf("请输入您要统计的班级:");
		flushall();
		scanf("%s",Class);
		for(i=0;i<N;i++) 
		if(strcmp(stu[i].Class,Class)==0)
			C++;
		printf("\n\t\t该班级的人数是:%d\n",C);
		printf("\n \t按任意键退出!");
		flushall();getchar();
		break;
	case 0:
		break;
	}
}
void sort(STUDENT stu[])//数据排序
{
	STUDENT temp;
	int m,i,j;
	printf("********************************************************************************\n");
    printf("\t\t================1.姓名=================\n\n");
	printf("\t\t================2.学号=================\n\n");
	printf("\t\t================3.年龄=================\n\n");
	printf("********************************************************************************\n");
	scanf ("%d",&m);
	if (m==1)
	{
		for (i=0;i<N-1;i++)
		{
			for (j=i+1;j<N;j++)
				if (strcmp(stu[i].name,stu[j].name)>0) //将学生按姓名升序排序
				{
					temp=stu[i];
					stu[i]=stu[j];
					stu[j]=temp;
				}
		}
	}
	else if (m==2)
	{
		for (i=0;i<N-1;i++)
		{
			for (j=i+1;j<N;j++)
				if (strcmp(stu[i].num,stu[j].num)<0) //将学生按学号降序排序
				{
					temp=stu[i];
					stu[i]=stu[j];
					stu[j]=temp;
				}
		}
	}
	else if (m==3)
	{
		for (i=0;i<N-1;i++)
		{
			for (j=i+1;j<N;j++)
				if (stu[i].age>stu[j].age) //将学生按年龄升序排序
				{
					temp=stu[i];
					stu[i]=stu[j];
					stu[j]=temp;
				}
		}
	}
	else 
	{
		printf("读文件出错，按任意键退出!");
		getch();
		exit(1);
	}
	output (stu);
	getchar();
	return ;
}
main ()//主菜单
{

	STUDENT stu[MAX];
	int choice;
	char password[7] = {0};
	int i = 0;
    printf("\n\n********************************************************************************\n\n\n\n");
	printf("\t\t\t欢迎进入学生信息管理系统\n"); //密码登录 
	printf("\n\n\t\t\t请输入密码:");
    for(i = 0; i < 6; i++){
		password[i] = getch();
		printf("*");
	}
	printf("\n\n\n********************************************************************************");
	if(strcmp(password,"000000")==0)
	{
		printf("\n\n\t\t\t密码正确，按任意键进入系统！\n");
		flushall();flushall();flushall();flushall();flushall();flushall();flushall();flushall();flushall();getchar();
	}
	else 
	{
		printf("\n\n\t\t\t密码输入错误！\n");
		return 0;
	}
	N=read_file(stu);
	flushall();flushall();flushall();flushall();flushall();flushall();flushall();flushall();flushall();getchar();
	if (N==0)
	{
		printf("************************录入基本学生信息，按任意键继续!************************\n");
		getch();
		N=input(stu);
	}
	do
	{
		system("cls");
		printf("\n*******************************欢迎使用学生信息管理系统*************************\n\n");
		printf("\t\t==============1.添加学生信息===============\n\n");
     	printf("\t\t==============2.修改学生信息===============\n\n");
        printf("\t\t==============3.删除学生信息===============\n\n");
	    printf("\t\t==============4.输出学生信息===============\n\n");
     	printf("\t\t==============5.查询学生信息===============\n\n");
	    printf("\t\t==============6.统计学生信息===============\n\n");
		printf("\t\t==============7.学生信息排行===============\n\n");
	    printf("\t\t==============0.退出系统===================\n\n");
        printf("********************************************************************************\n");
	    printf("请输入您所需要的操作编号(回车确定)");
        scanf("%d",&choice);
		switch(choice)
		{
		case 1:append (stu);break;
		case 2:modify (stu);break;
		case 3:del (stu);break;
		case 4:output (stu);break;
		case 5:inquire (stu);break;
		case 6:count (stu);break;
		case 7:sort (stu);break;
		case 0:	break;
		}
	}while(choice!=0);
	save_file (stu);
	return 0;
}
		

																
