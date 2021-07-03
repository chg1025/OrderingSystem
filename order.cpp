#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
struct book
{
    char number[20];//��� 
    char title[20];//���� 
    char category[20];//����
	char price[20];//�۸� 
	struct book *next;
};

typedef struct book lnode,*linklist;

struct user
{
    char ID[20];
    char cryptogram[20];
    int right;
    struct user *next;
};

typedef struct user LNODE,*LINKLIST;

struct table   //���� 
{
	char ID[20];//�������
	char num[20];//��������
	char amount[20];//����������
	struct table *next; 
};

typedef struct table Lnode, *Linklist;

//�Զ��庯����
 
void judge(LINKLIST headone,linklist head, Linklist Headone, int order[10][20]);//�˺ŵ�¼ 
void user(LINKLIST headone,linklist head, Linklist Headone, int order[10][20]);//�û�ϵͳ
void manger(LINKLIST headone,linklist head, Linklist Headone, int order[10][20]);//����Աϵͳ
void input_new_book_information(linklist head);//�ļ�¼���²�Ʒ��Ϣ
void input_a_new_book_information(linklist head);//��Ӳ�Ʒ��Ϣ
void Browse_all_book_information(linklist head);//���ȫ����Ʒ��Ϣ
void Delete_book_information(linklist head);//ɾ����Ʒ��Ϣ
void Search_by_title(linklist head);//��������ѯ

void input_users_information(LINKLIST headone);//¼���û���Ϣ
void Create_general_reader_accounts(LINKLIST headone);//������ͨ�����˺�
void Delete_regular_reader_accounts(LINKLIST headone);//ɾ����ͨ�����˺�
void Reset_individual_user_passwords(LINKLIST headone);//�޸��û�����
void Browse_all_users_information(LINKLIST headone);//���ȫ���û���Ϣ

void input_table_information(Linklist Headone);//¼�������Ϣ
void Add_table(Linklist Headone);//��Ӳ���
void Delete_table(Linklist Headone);//ɾ������
void Administrator_List_Table(Linklist Headone);//�����б� 


void InS(linklist head);//���ļ�����²��� 
void InU(LINKLIST headone);//���ļ�������û�
void InT(Linklist Headone);//���ļ�����²���
void Shuchupaixu(linklist head);//�������

void User_Order(Linklist Headone, linklist head, int order[10][20]);//��� 
void Sales_statistics(int order[10][20]);//����ͳ��
int  All(int j);//���� 
int order[10][20]={0};
 
int main()
{
	int i,j,k;
	linklist head;//������Ϣ���
    LINKLIST headone;//�û���Ϣ���
    Linklist Headone;//������Ϣ���
    head=(linklist)malloc(sizeof(lnode));
    headone=(LINKLIST)malloc(sizeof(LNODE));
    Headone=(Linklist)malloc(sizeof(Lnode));
    head->next=NULL;
    headone->next=NULL;
    Headone->next = NULL;

    input_new_book_information(head);//¼���Ʒ��Ϣ
    input_users_information(headone);//¼���û���Ϣ
    input_table_information(Headone);//¼�������Ϣ

	printf("\n=========��ӭ���������==========\n");
	printf("\n=========== ���¼ ==============\n");
	printf("[1]:�û���¼       [2]:����Ա��½\n");
	scanf("%d",&k);//�ж�Ҫ���еĲ���
	switch(k)
	{
		case 1:judge(headone,head, Headone, order);break;//�û���¼ 
		case 2:judge(headone,head, Headone, order);break;//����Ա��¼ 
	}
	return 0;
//	system("cls");
}

void judge(LINKLIST headone,linklist head, Linklist Headone, int order[10][20])//�ж��˺����룬Ȼ�����ϵͳ
{
    char ID[20];
    char cryptogram[20],c;
    int right;
    int x=-1;
    printf("�����������˺�:\n");
    scanf("%s",ID);
    printf("��������������:\n");
    while(x < 20&& c != 13)   //13�ǻس�����ASCII��
    {
    	x++;
        c = getch();
        cryptogram[x] = c;
        if(c != 13)
        putchar('*');
    }
    cryptogram[x] = '\0';
    printf("\n");
    LINKLIST q=headone->next;
    while(q)
    {
        if(strcmp(q->ID ,ID)==0)
		{
			if(strcmp(q->cryptogram ,cryptogram)!=0)
			{
				printf("�������\n");
				judge(headone,head, Headone, order);
			}
			else
			{
				if(q->right ==0)
				{
				    printf("��½�ɹ�\n");
				    system("pause");
				    system("cls");
					manger(headone,head, Headone, order);
				}
				else if(q->right ==1)
				{
				    printf("��½�ɹ�\n");
				    system("pause");
				    system("cls");
					user(headone,head, Headone, order);
				}
			}
		}
		q=q->next ;
	}
}

void user(LINKLIST headone,linklist head, Linklist Headone, int order[10][20])//�û�ϵͳ 
	{
	int aaa;
	while(1){
	 	printf("\n============== ����� ==============\n");
		printf("[1]�����              [2]: �鿴�˵�\n");
		printf("[3]���޸�����          [4]: �˳���¼\n");
		printf("��ѡ������Ҫ�ķ���\n");
		scanf("%d", &aaa);
		switch(aaa){
			case 1:
				User_Order( Headone, head, order);
            	system("cls");
           		break;
			case 2:
				Browse_all_book_information(head);
				system("cls");
            	break;
			case 3:
				Reset_individual_user_passwords(headone);
				system("cls");
				break; 
			case 4:
				main();
				system("cls");
				break;
		}
	}
	system("cls");
}
 
void manger(LINKLIST headone,linklist head, Linklist Headone, int order[10][20])//����Աϵͳ 
	{ 
	int bbb;
	while(1)
	{
		printf("\n=============== ����� ===============\n");
		printf("[1]�������б�           [2]: �鿴�˵�\n");
		printf("[3]����Ӳ�Ʒ           [4]: ɾ����Ʒ\n");
        printf("[5]����Ӳ���           [6]��ɾ������\n");
		printf("[7]: ����ͳ��           [8]: �û���Ϣ\n");
		printf("[9]: �޸�����           [10]: �޸��û����� \n");
		printf("[11]: ����û�          [12]��ɾ���û�\n");
		printf("[13]:�˳���¼\n");
		printf("��ѡ������Ҫ�ķ���\n");
		scanf("%d", &bbb);
		switch(bbb)
		{
        	case 1:
				Administrator_List_Table(Headone);
            	system("cls");
           		break;
			case 2:
				Browse_all_book_information(head);
				system("cls");
            	break;
			case 3:
				input_a_new_book_information(head);
				system("cls");
				break; 
			case 4:	
				Delete_book_information(head);
				system("cls");
				break;			
			case 5:
                Add_table(Headone);
                system("cls");
                break;
			case 6:
                Delete_table(Headone);
                system("cls");
                break;
            case 7:
			 	Sales_statistics(order);
			 	system("cls");
			 	break;
			case 8:
				Browse_all_users_information(headone);
				system("cls");
				break;
			case 9:
				Create_general_reader_accounts(headone);
				system("cls");
				break;
			case 10:
				Reset_individual_user_passwords(headone);
				system("cls");
				break;
			case 11:
				Create_general_reader_accounts(headone);
				system("cls");
				break;
            case 12:
                Delete_regular_reader_accounts(headone);
				system("cls");
				break;
            case 13:
                main();
                system("cls");
                break;
		}
	}
} 

void input_new_book_information(linklist head)//�ļ�����²�Ʒ��Ϣ
{
    char number[20];
    char title[20];
    char category[20];
    char price[10]; 
    FILE *fp;
    if((fp=fopen("meau.txt","r"))==NULL)
    {
        printf("error!\n");
        exit(0);
    }
    linklist p,rear=head;
    while(fscanf(fp,"%s",number)!=EOF)
    {
        fscanf(fp,"%s",title);
        fscanf(fp,"%s",category);
        fscanf(fp, "%s", price);
        p=(linklist)malloc(sizeof(lnode));
        strcpy(p->number,number);
        strcpy(p->title,title);
        strcpy(p->category,category);
        strcpy(p->price, price);
        rear->next=p;
        rear=p;
    }
    rear->next=NULL;
    fclose(fp);
}
void input_a_new_book_information(linklist head)//��Ӳ�Ʒ��Ϣ
{
    linklist prt=head,pre=head->next,p;
    linklist q;
	while(pre)
	{
		prt=prt->next ;
		pre=pre->next ;
	}
    char number[20];
    char title[20];
    char category[20];
    char price[10];
    printf("���������Ӳ�Ʒ��Ϣ:\n");
    printf("���      ����      ���        �۸�\n");
    printf("����#��ʾ�������\n");
    while(scanf("%s",number),strcmp(number,"#")!=0)
    {
        int s=0;
        linklist q=head->next;
        while(q)
        {
            if(strcmp(q->number,number)==0)
            {
                s=1;
                break;
            }
            q=q->next;
        }
        if(s==0)
        {
            scanf("%s",title);
            scanf("%s",category);
            scanf("%s", price); 
	        p=(linklist)malloc(sizeof(lnode));
	        strcpy(p->number,number);
            strcpy(p->title,title);
            strcpy(p->category,category);
            strcpy(p->price, price);
			p->next=prt->next;
            prt->next=p;
            printf("��ӳɹ�\n");
        }
        if(s==1)
        {
            printf("�ò�Ʒ����ظ�!\n");
        }
    }
    system("pause");
    InS(head);
    
}

void input_users_information(LINKLIST headone)//¼���û���Ϣ
{
    char ID[20];
    char cryptogram[20];
    int right;
    FILE *fp;
    if((fp=fopen("user.txt","r"))==NULL)
    {
        printf("error!\n");
        exit(0);
    }
    LINKLIST p,rear=headone;
    while(fscanf(fp,"%s",ID)!=EOF)
    {
        fscanf(fp,"%s",cryptogram);
        fscanf(fp,"%d",&right);
        p=(LINKLIST)malloc(sizeof(LNODE));
        strcpy(p->ID,ID);
        strcpy(p->cryptogram,cryptogram);
        p->right=right;
        rear->next=p;
        rear=p;
    }
    rear->next=NULL;
    fclose(fp);
}

void Browse_all_book_information(linklist head)//���ȫ����Ʒ��Ϣ
{
    Shuchupaixu(head);
    printf("���      ����                ���                �۸�\n");
    linklist p=head->next;
	while(p)
	{
		printf("%-10s%-20s%-20s%-10s%",p->number,p->title,p->category, p->price);
		printf("\n");
		p=p->next;
	}
	system("pause");
}
void Browse_all_users_information(LINKLIST headone)//���ȫ���û���Ϣ
{
    printf("�˺�         ����            ���(1Ϊ�û���0Ϊ����Ա)\n");
    LINKLIST p=headone->next;
    while(p)
    {
        printf("%-15s%-15s%-10d",p->ID,p->cryptogram,p->right);
        printf("\n");
        p=p->next;
    }
    system("pause");
}
void Delete_book_information(linklist head)//ɾ����Ʒ��Ϣ
{
    int s=0;
    char number[20];
    char title[20];
    char category[20];
    char price[10];
    printf("������Ҫɾ���Ĳ�Ʒ���:\n");
    scanf("%s",number);
    linklist p,pre=head->next,prt=head;
	while(pre)
	{
		if(strcmp(pre->number,number)==0)
		{
		    s=1;
			break;
		}
		pre=pre->next;
		prt=prt->next;
	}
	if(s==1)
    {
        p=prt->next;
	    prt->next=p->next ;
	    strcpy(number,p->number);
	    strcpy(title,p->title);
	    strcpy(category,p->category);
	    strcpy(price, p->price);
	    free(p);
	    printf("ɾ���ɹ�\n");
    }
	if(s==0)
    {
        printf("���޴˲�Ʒ��Ϣ��\n");
    }
    system("pause");
    InS(head);
}
void Search_by_title(linklist head)//��������ѯ
{
    int s=0;
    char title[20];
    printf("���������ѯ��Ʒ����\n");
    scanf("%s",title);
    linklist p=head->next;
    linklist q=head->next;
    while(p)
    {
        if(strcmp(p->title,title)==0)
        {
            s=1;
            break;
        }
        p=p->next;
    }
    if(s==0)
    {
        printf("���޴˲�Ʒ��Ϣ��\n");
    }
    else if(s==1)
    {
        printf("���      ����                ���         �۸�\n");
        while(q)
        {
            if(strcmp(q->title,title)==0)
            {
                printf("%-10s%-20s%-20s%-10s%",q->number,q->title,q->category, q->price);
		    printf("\n");
            }
            q=q->next;
        }
    }
    system("pause");
}

void Create_general_reader_accounts(LINKLIST headone)//�����û��˺�
{
    LINKLIST prt=headone;
    LINKLIST pre=headone->next;
    LINKLIST q;
    while(pre)
    {
        prt=prt->next;
        pre=pre->next;
    }
    char ID[20];
    char cryptogram[20];
    int right=1;
    printf("������Ҫ�����˺ŵ��˺ź�����\n");
    printf("����#��ʾ�������\n");
    while(scanf("%s",ID),strcmp(ID,"#")!=0)
    {
        LINKLIST p=headone->next;
        int s=0;
        while(p)
        {
            if(strcmp(p->ID,ID)==0)
            {
                s=1;
                break;
            }
            p=p->next;
        }
        if(s==0)
        {
        scanf("%s",cryptogram);
        q=(LINKLIST)malloc(sizeof(LNODE));
        strcpy(q->ID,ID);
        strcpy(q->cryptogram,cryptogram);
        q->right=right;
        q->next=prt->next;
        prt->next=q;
        printf("�����ɹ�\n");
        }
        else if(s==1)
        {
            printf("�û��˺��Ѵ���\n");
        }
    }
	system("pause");
	InU(headone);
}
void Delete_regular_reader_accounts(LINKLIST headone)//ɾ���û��˺�
{
    int s=0;
    char ID[20];
    char cryptogram[20];
    int right;
    LINKLIST q=headone;
    printf("�������ɾ���û����˺�:\n");
    scanf("%s",ID);
    LINKLIST p,pre=headone->next,prt=headone;
    while(pre)
	{
		if(strcmp(pre->ID,ID)==0)
		{
		    s=1;
			break;
		}
		pre=pre->next;
		prt=prt->next;
	}
	if(s==1)
    {
        p=prt->next;
	prt->next=p->next ;
	strcpy(ID,p->ID);
	strcpy(cryptogram,p->cryptogram);
	right=p->right;
	free(p);
	printf("ɾ���ɹ�\n");
    }
    else if(s==0)
    {
        printf("�˺Ų�����\n");
    }
    system("pause");
	InU(headone);
}
void Reset_individual_user_passwords(LINKLIST headone)//�޸��û�����
{
    char ID[20];
    char cryptogram[20];
    int s=0;
    LINKLIST q=headone;
    printf("������Ҫ�޸�������û��˺�\n");
    scanf("%s",ID);
    while(q)
    {
        if(strcmp(q->ID,ID)==0)
        {
            s=1;
            break;
        }
        q=q->next;
    }
    if(s==0)
    {
        printf("�û�������\n");
    }
    if(s==1)
    {
        printf("��������û��˺ŵ�������\n");
    scanf("%s",cryptogram);
    LINKLIST p=headone->next;
    while(p)
    {
        if(strcmp(p->ID,ID)==0)
        {
            strcpy(p->cryptogram,cryptogram);
            break;
        }
        p=p->next;
    }
    printf("���óɹ�\n");
    }
    system("pause");
    InU(headone);
}

void InS(linklist head)//��Ӳ�Ʒ 
{
    Shuchupaixu(head);
    FILE *fp;
    if((fp=fopen("meau.txt","r"))==NULL)
    {
        printf("error!\n");
        exit(0);
    }
    fp=fopen("meau.txt","w");
    fclose(fp);
    linklist p=head->next;
    if((fp=fopen("meau.txt","w"))==NULL)
    {
        printf("error!\n");
        exit(0);
    }
    while(p)
    {
        fprintf(fp,"%-10s",p->number);
        fprintf(fp,"%-20s",p->title);
        fprintf(fp,"%-20s",p->category);
        fprintf(fp, "-10s", p->price);
        p=p->next;
    }
    fclose(fp);
}
void InU(LINKLIST headone)//���ļ�������û� 
{
    FILE *fp;
    if((fp=fopen("user.txt","r"))==NULL)
    {
        printf("error!\n");
        exit(0);
    }
    fp=fopen("user.txt","w");
    fclose(fp);
    LINKLIST p=headone->next;
    if((fp=fopen("user.txt","w"))==NULL)
    {
        printf("error!\n");
        exit(0);
    }
    while(p)
    {
        fprintf(fp,"%-10s",p->ID);
        fprintf(fp,"%-10s",p->cryptogram);
        fprintf(fp,"%-10d\n",p->right);
        p=p->next;
    }
    fclose(fp);
}

void input_table_information(Linklist Headone)//¼�������Ϣ
{
    char ID[20];
    char num[20];
    char amount[20];
    FILE *fp;
    if((fp=fopen("table.txt","r"))==NULL)
    {
        printf("error!\n");
        exit(0);
    }
    Linklist p,rear=Headone;
    while(fscanf(fp, "%s", ID) != EOF)
    {
        fscanf(fp, "%s", num);
        fscanf(fp, "%s", amount);
        p=(Linklist)malloc(sizeof(Lnode));
        strcpy(p->ID,ID);
        strcpy(p->num,num);
        strcpy(p->amount, amount);
        rear->next=p;
        rear=p;
    }
    rear->next=NULL;
    fclose(fp);
}

void Add_table(Linklist Headone)//��Ӳ���
{
    Linklist prt=Headone;
    Linklist pre=Headone->next;
    Linklist q;
    while(pre)
    {
        prt=prt->next;
        pre=pre->next;
    }
    char ID[20];
    char num[20];
    char amount[20];
    printf("������Ҫ��ӵĲ�������Ϳ���������\n");
    printf("����#��ʾ�������\n");
    while(scanf("%s",ID),strcmp(ID,"#")!=0)
    {
        Linklist p=Headone->next;
        int s=0;
        while(p)
        {
            if(strcmp(p->ID,ID)==0)
            {
                s=1;
                break;
            }
            p=p->next;
        }
        if(s==0)
        {
        scanf("%s",num);
        scanf("%s", amount);
        q=(Linklist)malloc(sizeof(Lnode));
        strcpy(q->ID,ID);
        strcpy(q->num,num);
        strcpy(q->amount, amount);

        q->next=prt->next;
        prt->next=q;
        printf("������ӳɹ�\n");
        }
        else if(s==1)
        {
            printf("�����Ѵ���\n");
        }
    }
	system("pause");
	InT(Headone);
}

void Delete_table(Linklist Headone)//ɾ������
{
    int s=0;
    char ID[20];
    char num[20];
    char amount[20];
    Linklist q=Headone;
    printf("�������ɾ�������ĺ���:\n");
    scanf("%s",ID);
    Linklist p,pre=Headone->next,prt=Headone;
    while(pre)
	{
		if(strcmp(pre->ID,ID)==0)
		{
		    s=1;
			break;
		}
		pre=pre->next;
		prt=prt->next;
	}
	if(s==1)
    {
        p=prt->next;
        prt->next=p->next ;
        strcpy(ID,p->ID);
        strcpy(num,p->num);
        strcpy(amount, p->amount);
        free(p);
        printf("ɾ���ɹ�\n");
    }
    else if(s==0)
    {
        printf("����������\n");
    }
    system("pause");
	InT(Headone);
}

void Administrator_List_Table(Linklist Headone)//�����б� 
{
    printf("������:        ����������:        ��������:\n");
    Linklist p=Headone->next;
    while(p)
    {
        printf("%-20s%-20s%-20s",p->ID,p->num,p->amount);
        printf("\n");
        p=p->next;
    }
    system("pause");
}
void InT(Linklist Headone)//���ļ�����²���
{
    FILE *fp;
    if((fp=fopen("table.txt","r"))==NULL)
    {
        printf("error!\n");
        exit(0);
    }
    fp=fopen("table.txt","w");
    fclose(fp);
    Linklist p=Headone->next;
    if((fp=fopen("table.txt","w"))==NULL)
    {
        printf("error!\n");
        exit(0);
    }
    while(p)
    {
        fprintf(fp,"%-20s",p->ID);
        fprintf(fp,"%-20s",p->num);
        fprintf(fp,"%-20s\n",p->amount);
        p=p->next;
    }
    fclose(fp);
}

void User_Order(Linklist Headone, linklist head, int order[10][20])//��� 
{
	char ID[10];
	char amount[10];
	int s=1,i, j=0, m;
	double all = 0;
	printf("�����ţ�         ����������:           ����������\n");
	Linklist p=Headone->next;
	while(p)
    {
        printf("%-20s%-20s%-20s",p->ID,p->num,p->amount);
        printf("\n");
        p=p->next;
    }
    printf("��ѡ�����Ĳ�����\n");
    scanf("%s", ID);
    while(p)
	{
    	if(strcmp(p->ID,ID) == 0 )
    	{
    		s=1;
    		break;
		}
		p=p->next;
	}
    if(s == 0)
    {
    	printf("���������ڣ���ѡ������������\n");
	}
	if(s == 1)
	{
		printf("�������ò�������\n");
		scanf("%s", amount);
		while(p)
		{
			strcpy(p->amount, amount);
			break;
			p = p->next;
		}
		printf("����Ԥ���ɹ�!\n");
	}
	Shuchupaixu(head);
    printf("���      ����                ���                 �۸�\n");
    linklist q=head->next;
	while(q)
	{
		printf("%-10s%-20s%-20s%-10s%",q->number,q->title,q->category, q->price);
		printf("\n");
		q=q->next;
	}
	printf("����������Ҫ�Ĳ�Ʒ���(����'-1'�������ѡ��)��\n");
	while(1)
	{
		scanf("%d", &m);
		i= atoi(ID);
		if(m == -1)
			break;
		else
			order[i][j]=m;
		j++;
	}
	printf("ѡ�˳ɹ�����ѡ���У�\n");
	for(j=0; j<20; j++)
	{
		if(order[i][j] == 0)
			break;
		else
		{
			printf("%d ", order[i][j]);
			all += All(j);
		}
	}
	printf("\n");
	printf("���ƻ��ѣ�%.2f\n", all);
	
	system("pause");
 }
 
 void Sales_statistics(int order[10][20])//����ͳ��
 {
 	int i, j;  
 	double m[10]={0}, n=0;
	for(i=0; i<10; i++)
	{
		if(order[i][0]==0)
			break;
		else{
			printf("%d�����ĵ�ͣ�\n", i); 
			for(j=0; j<20; j++)
			{
				if(order[i][j] == 0)
					break;
				else
				{		
					printf("%d ", order[i][j]);
					m[i] += All(order[i][j]);
				}
			}
			printf("\n�������ѣ�%.2f\n", m[i]);
			n += m[i];
		}
	}
	printf("����Ӫҵ�%.2f\n", n);
	system("pause");
 }
 int All(int j)
 {
 	double price[50];
 	price[1] = 49.00;
	price[2] = 49.00; 
	price[3] = 59.00;
	price[4] = 49.00;
	price[5] = 39.00;
	price[6] = 19.00;
	price[7] = 16.00;
	price[8] = 13.00;
	price[9] = 13.00;
	price[10] = 19.00;
	price[11] = price[12] = price[14] = 1.00;
	price[13] = 6.00;
	return price[j];
 	
 }

void Shuchupaixu(linklist head)//��Ʒ����
{
    int i;
    char number[20];
    char title[20];
    char category[20];
    char price[10];
    linklist p,q;
    for(p=head->next;p!=NULL;p=p->next)
    {
        for(q=p->next;q!=NULL;q=q->next)
        {
            if(strcmp(p->number,q->number)>0)
            {
                strcpy(number,p->number);
                strcpy(title,p->title);
                strcpy(category,p->category);
                strcpy(price, p->price);
                strcpy(p->number,q->number);
                strcpy(p->title,q->title);
                strcpy(p->category,q->category);
                strcpy(p->price, q->price);
                strcpy(q->number,number);
                strcpy(q->title,title);
                strcpy(q->category,category);
                strcpy(q->price, price);
            }
        }
    }
}

