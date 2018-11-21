#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <conio.h>
#define MAX 20
int N = 0;
typedef struct student//ѧ����Ϣ�ṹ������
{
	char name[20];
	char num[9];
	char sex[8];
	int age;
	char Class[20];
	char phone[20];
	char addr[20];
}STUDENT;
int read_file (STUDENT stu[])//���ݶ�д
{
	FILE *fp;
	int i=0;
	int stuCount = 0;
	if((fp=fopen("student.txt","rb"))==NULL)
	{
		printf("\n\n ********��ʱ��û���κ�ѧ����Ϣ����������������˵�ѡ�������Ϣ��¼�룡********\n");
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
void save_file (STUDENT stu[])//���ݴ洢
{
	FILE *fp;
	int i;
	if((fp=fopen("student.txt","wb"))==NULL)
	{
		printf("���ļ�����!\n");
		return;
	}
	for(i=0;i<N;i++)
	if(fwrite(&stu[i],sizeof(STUDENT),1,fp)!=1)
	printf("д�ļ�����\n");
	fclose(fp);
}
int input (STUDENT stu[])//����¼��
{
	int i=0,flag;
	char choice;
	system("cls");
	printf("\n ¼��ѧ������Ϣ:\n",i);
	printf ("* * * * * * * * * * * * \n");
	do
	{
    printf("\n��%d��ѧ������Ϣ:\n",i+1);
	printf("\n����:");
	flushall();//���������
	scanf("%s",stu[i].name);
	printf("\nѧ��:");
	flushall();
	scanf("%s",stu[i].num);
	printf("\n�Ա�:");
	flushall();
	scanf("%s",&stu[i].sex);
    printf("\n����:");
	flushall();
    scanf("%d",&stu[i].age);
	printf("\n�༶:");
	flushall();
	scanf("%s",stu[i].Class);
	printf("\n��ϵ�绰:");
	flushall();
	scanf("%s",stu[i].phone);
	printf("\n��ͥסַ:");
	flushall();
	scanf("%s",stu[i].addr);
	N=i+1;
    i++;
	printf("������?(Y/N)");
	choice=getch();
	if (choice=='y'||choice=='Y')
	{
		flag=1;
		printf("\n����!\n");
	}
	else flag=0;
	}while(flag==1);
	printf ("\n**ѧ����Ϣ������ϣ�**\n\n");
	printf ("\n ��������������˵���");
    getchar();
	return i;
}
void output (STUDENT stu[])//�������
{
	int i=0;
	system("cls");
	printf(" ���� \t   ѧ��        �Ա�      ����      �༶     ��ϵ�绰    ��ͥסַ\n  ");
	printf("-----------------------------------------------------------------------");
	do
	{	
		printf("\n %s \t%s\t%s\t  %d\t   %s\t      %s\t  %s\n",stu[i].name,stu[i].num,stu[i].sex,stu[i].age,stu[i].Class,stu[i].phone,stu[i].addr);
	    i++;
	} while (i<N);
	printf ("��������������˵���");
	flushall();getchar();
}
void append (STUDENT stu[])//��Ϣ���
{
	int i = N,flag=0;
	char choice;
	system("cls");
	printf("\n\n         �������ѧ������Ϣ\n");
	printf("         -----------------------\n");
	do
	{
		printf("\n         ���뱻���ѧ������Ϣ\n");
		printf("\n               ������");
		flushall();scanf("%s",stu[i].name);
		printf("\n               ѧ�ţ�");
		flushall();scanf("%s",stu[i].num);
		printf("\n               �Ա�");
		flushall();scanf("%s",&stu[i].sex);
		printf("\n               ���䣺");
		flushall();scanf("%d",&stu[i].age);
		printf("\n               �༶��");
		flushall();scanf("%s",stu[i].Class);
		printf("\n               ��ϵ�绰��");
		flushall();scanf("%s",stu[i].phone);
		printf("\n               ��ͥסַ��");
		flushall();scanf("%s",stu[i].addr);
		printf("\n               Ҫ������?(Y/N)");
		flushall();choice=getchar();
		N++;
		
		if (choice=='y'||choice=='Y')
		{
			printf("\n            ����!\n");
			i++;
			flag=1;
		}
		else flag=0;
	}while(flag==1);
	printf("\n               ��������������˵���");
	flushall();flushall();flushall();flushall();flushall();flushall();flushall();flushall();flushall();getchar();
}
void modify (STUDENT stu[])//��Ϣ�޸�
{
	int i=0,choice,flag;
	char modify_num[9];
	do
	{
		system("cls");
		printf("\n����Ҫ�޸�ѧ����ѧ�ţ�");
		scanf ("%s",modify_num);
		for (i=0;i<N;i++)
			if (strcmp(stu[i].num,modify_num)==0)
			{
				printf("\n--ѧ����Ϣ--\n");
				printf(" ���� \t   ѧ��        �Ա�      ����      �༶     ��ϵ�绰    ��ͥסַ\n  ");
		        printf("-----------------------------------------------------------------\n");
				printf("\n %s \t%s\t%s\t  %d\t   %s\t      %s\t  %s\n",stu[i].name,stu[i].num,stu[i].sex,stu[i].age,stu[i].Class,stu[i].phone,stu[i].addr);
				printf("\n�����޸���һ��?\n");
				printf("\n1.����\n");
				printf("\n2.ѧ��\n");
				printf("\n3.�Ա�\n");
				printf("\n4.����\n");
				printf("\n5.�༶\n");
				printf("\n6.��ϵ�绰\n");
				printf("\n7.��ͥסַ\n");
				printf("\n��ѡ��(1-7):");
				flushall();scanf("%d",&choice);
				switch(choice)
				{
				case 1:printf("\n�����޸ĺ������:");
					flushall();
					scanf("%s",stu[i].name);break;
				case 2:printf("\n�����޸ĺ��ѧ��:");
					flushall();
					scanf("%s",stu[i].num);break;
				case 3:printf("\n�����޸ĺ���Ա�:");
					flushall();
					scanf("%s",stu[i].sex);break;
				case 4:printf("\n�����޸ĺ������:");
					flushall();
					scanf("%d",&stu[i].age);break;
				case 5:printf("\n�����޸ĺ�İ༶:");
					flushall();
					scanf("%s",stu[i].Class);break;
				case 6:printf("\n�����޸ĺ����ϵ�绰:");
					flushall();
					scanf("%s",stu[i].phone);break;
				case 7:printf("\n�����޸ĺ�ļ�ͥסַ:");
					flushall();
					scanf("%s",stu[i].addr);break;
				}
				printf("\n--ѧ����Ϣ--\n");
				printf(" ���� \t   ѧ��        �Ա�      ����      �༶     ��ϵ�绰    ��ͥסַ\n  ");
		        printf("-----------------------------------------------------------------\n");
				printf("\n %s \t%s\t%s\t  %d\t   %s\t      %s\t  %s\n",stu[i].name,stu[i].num,stu[i].sex,stu[i].age,stu[i].Class,stu[i].phone,stu[i].addr);
				break;
			}
			if(i==N)
			{
				printf("\n��ѧ�������ڣ�");
				getchar();
			}
			printf("\n\n������޸���?(Y/N)");
			choice=getch();
			if (choice=='y'||choice=='Y')
			{
				flag=1;
				printf("\n����!\n");
			}
			else flag=0;
	}while(flag==1);
	printf("\n��������������˵�!");
	getchar();
}
void del (STUDENT stu[])//��Ϣɾ��
{
	int i;
	char del_num[9];
	printf("��������Ҫɾ����ѧ��ѧ��:");
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
			printf("ɾ���ɹ�!\n\n");
			return;
		}
		else 
		{
			printf("δ�ҵ���ѧ��!\n");
			flushall();flushall();flushall();flushall();flushall();flushall();flushall();flushall();flushall();getchar();
		}
}
void inquire (STUDENT stu[])//��Ϣ��ѯ
{
	int n,i;
	char inquire_num[9];
	char inquire_name[20];
	char inquire_Class[20];
	int inquire_age;
	printf("********************************************************************************\n\n");
    printf("\n��ѡ����ҷ�ʽ:\n\n");
	printf("\t\t1.��ѧ����������\n\n");
    printf("\t\t2.��ѧ��ѧ�Ų���\n\n");
    printf("\t\t3.��ѧ���İ༶����\n\n");
    printf("\t\t4.��ѧ�������䷶Χ����\n\n");
    printf("\t\t0.����\n");
	printf("��������Ҫ�Ĳ�ѯ��ʽ:");
	scanf("%d",&n);//��ȡ���ҷ�ʽ
	switch(n)
	{
	case 1:
		    printf("����������ѯ��ѧ������:");
            scanf("%s",inquire_name);
		    for (i=0;i<N;i++)
			{
				if (strcmp(stu[i].name,inquire_name)==0)
				{
					printf(" ���� \t   ѧ��        �Ա�      ����      �༶     ��ϵ�绰    ��ͥסַ\n  ");
		            printf("-----------------------------------------------------------------\n");
			     	printf("\n %s \t%s\t%s\t  %d\t   %s\t      %s\t  %s\n",stu[i].name,stu[i].num,stu[i].sex,stu[i].age,stu[i].Class,stu[i].phone,stu[i].addr);
				}
				else 
					printf("\t%s\n","û�в�ѯ����ѧ����Ϣ����������:");
			}
				flushall();getchar();
				break;
	case 2:
			printf("����������ѯ��ѧ��ѧ��:");
            scanf("%s",inquire_num);	
			for (i=0;i<N;i++)
			{
				if (strcmp(stu[i].num,inquire_num)==0)
				{
					printf(" ���� \t   ѧ��        �Ա�      ����      �༶     ��ϵ�绰    ��ͥסַ\n  ");
					printf("-----------------------------------------------------------------\n"); 
					printf("\n %s \t%s\t%s\t  %d\t   %s\t      %s\t  %s\n",stu[i].name,stu[i].num,stu[i].sex,stu[i].age,stu[i].Class,stu[i].phone,stu[i].addr);
				}
			else
				printf("\t%s\n","û�в�ѯ����ѧ����Ϣ����������:");
			}
			flushall();getchar();
			break;
	case 3:
			printf("����������ѯ��ѧ���༶:");
            scanf("%s",inquire_Class);	
			for (i=0;i<N;i++)
			{
				if (strcmp(stu[i].Class,inquire_Class)==0)
				{
					printf(" ���� \t   ѧ��        �Ա�      ����      �༶     ��ϵ�绰    ��ͥסַ\n  ");
					printf("-----------------------------------------------------------------\n"); 
					printf("\n %s \t%s\t%s\t  %d\t   %s\t      %s\t  %s\n",stu[i].name,stu[i].num,stu[i].sex,stu[i].age,stu[i].Class,stu[i].phone,stu[i].addr);
				}
			else
				printf("\t%s\n","û�в�ѯ����ѧ����Ϣ����������:");
			}
			flushall();getchar();
			break;
	case 4:
		    printf("����������ѯ��ѧ������:");
            scanf("%d",&inquire_age);	
			for (i=0;i<N;i++)
			{
				if (stu[i].age==inquire_age)
				{
					printf(" ���� \t   ѧ��        �Ա�      ����      �༶     ��ϵ�绰    ��ͥסַ\n  ");
					printf("-----------------------------------------------------------------\n"); 
					printf("\n %s \t%s\t%s\t  %d\t   %s\t      %s\t  %s\n",stu[i].name,stu[i].num,stu[i].sex,stu[i].age,stu[i].Class,stu[i].phone,stu[i].addr);
				}
			else
				printf("\t%s\n","û�в�ѯ����ѧ����Ϣ����������:");
			}
			flushall();getchar();
			break;
	case 0:
		break;
	}
}
void count (STUDENT stu[])//��Ϣͳ��
{
	int choice,s=0,C=0,i;
	char sex[8];
	char Class[20];
	system("cls");
	printf("********************************************************************************\n\n");
	printf("\t\t================1.�Ա�=================\n\n");
	printf("\t\t================2.�༶=================\n\n");
	printf("\t\t================0.����=================\n\n");
    printf("********************************************************************************\n");
	printf("������Ҫͳ�Ƶ�����:");
	flushall();scanf("%d",&choice);
	switch(choice)
	{
	case 1:
		printf("��������Ҫͳ�Ƶ��Ա�:");
		flushall();
		scanf("%s",sex);
		for(i=0;i<N;i++) 
		if(strcmp(stu[i].sex,sex)==0)
			s++;
		printf("\n\n   ���Ա�������:%d\n",s);
		printf("\n\n   ��������˳�!");
		flushall();getchar();
		break;
	case 2:
		printf("��������Ҫͳ�Ƶİ༶:");
		flushall();
		scanf("%s",Class);
		for(i=0;i<N;i++) 
		if(strcmp(stu[i].Class,Class)==0)
			C++;
		printf("\n\t\t�ð༶��������:%d\n",C);
		printf("\n \t��������˳�!");
		flushall();getchar();
		break;
	case 0:
		break;
	}
}
void sort(STUDENT stu[])//��������
{
	STUDENT temp;
	int m,i,j;
	printf("********************************************************************************\n");
    printf("\t\t================1.����=================\n\n");
	printf("\t\t================2.ѧ��=================\n\n");
	printf("\t\t================3.����=================\n\n");
	printf("********************************************************************************\n");
	scanf ("%d",&m);
	if (m==1)
	{
		for (i=0;i<N-1;i++)
		{
			for (j=i+1;j<N;j++)
				if (strcmp(stu[i].name,stu[j].name)>0) //��ѧ����������������
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
				if (strcmp(stu[i].num,stu[j].num)<0) //��ѧ����ѧ�Ž�������
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
				if (stu[i].age>stu[j].age) //��ѧ����������������
				{
					temp=stu[i];
					stu[i]=stu[j];
					stu[j]=temp;
				}
		}
	}
	else 
	{
		printf("���ļ�������������˳�!");
		getch();
		exit(1);
	}
	output (stu);
	getchar();
	return ;
}
main ()//���˵�
{

	STUDENT stu[MAX];
	int choice;
	char password[7] = {0};
	int i = 0;
    printf("\n\n********************************************************************************\n\n\n\n");
	printf("\t\t\t��ӭ����ѧ����Ϣ����ϵͳ\n"); //�����¼ 
	printf("\n\n\t\t\t����������:");
    for(i = 0; i < 6; i++){
		password[i] = getch();
		printf("*");
	}
	printf("\n\n\n********************************************************************************");
	if(strcmp(password,"000000")==0)
	{
		printf("\n\n\t\t\t������ȷ�������������ϵͳ��\n");
		flushall();flushall();flushall();flushall();flushall();flushall();flushall();flushall();flushall();getchar();
	}
	else 
	{
		printf("\n\n\t\t\t�����������\n");
		return 0;
	}
	N=read_file(stu);
	flushall();flushall();flushall();flushall();flushall();flushall();flushall();flushall();flushall();getchar();
	if (N==0)
	{
		printf("************************¼�����ѧ����Ϣ�������������!************************\n");
		getch();
		N=input(stu);
	}
	do
	{
		system("cls");
		printf("\n*******************************��ӭʹ��ѧ����Ϣ����ϵͳ*************************\n\n");
		printf("\t\t==============1.���ѧ����Ϣ===============\n\n");
     	printf("\t\t==============2.�޸�ѧ����Ϣ===============\n\n");
        printf("\t\t==============3.ɾ��ѧ����Ϣ===============\n\n");
	    printf("\t\t==============4.���ѧ����Ϣ===============\n\n");
     	printf("\t\t==============5.��ѯѧ����Ϣ===============\n\n");
	    printf("\t\t==============6.ͳ��ѧ����Ϣ===============\n\n");
		printf("\t\t==============7.ѧ����Ϣ����===============\n\n");
	    printf("\t\t==============0.�˳�ϵͳ===================\n\n");
        printf("********************************************************************************\n");
	    printf("������������Ҫ�Ĳ������(�س�ȷ��)");
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
		

																
