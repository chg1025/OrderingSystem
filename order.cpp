#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
struct book
{
    char number[20];//编号 
    char title[20];//菜名 
    char category[20];//种类
	char price[20];//价格 
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

struct table   //餐桌 
{
	char ID[20];//餐桌编号
	char num[20];//已坐人数
	char amount[20];//可容纳人数
	struct table *next; 
};

typedef struct table Lnode, *Linklist;

//自定义函数区
 
void judge(LINKLIST headone,linklist head, Linklist Headone, int order[10][20]);//账号登录 
void user(LINKLIST headone,linklist head, Linklist Headone, int order[10][20]);//用户系统
void manger(LINKLIST headone,linklist head, Linklist Headone, int order[10][20]);//管理员系统
void input_new_book_information(linklist head);//文件录入新菜品信息
void input_a_new_book_information(linklist head);//添加菜品信息
void Browse_all_book_information(linklist head);//浏览全部菜品信息
void Delete_book_information(linklist head);//删除菜品信息
void Search_by_title(linklist head);//按菜名查询

void input_users_information(LINKLIST headone);//录入用户信息
void Create_general_reader_accounts(LINKLIST headone);//创建普通读者账号
void Delete_regular_reader_accounts(LINKLIST headone);//删除普通读者账号
void Reset_individual_user_passwords(LINKLIST headone);//修改用户密码
void Browse_all_users_information(LINKLIST headone);//浏览全部用户信息

void input_table_information(Linklist Headone);//录入餐桌信息
void Add_table(Linklist Headone);//添加餐桌
void Delete_table(Linklist Headone);//删除餐桌
void Administrator_List_Table(Linklist Headone);//餐桌列表 


void InS(linklist head);//在文件里更新菜名 
void InU(LINKLIST headone);//在文件里更新用户
void InT(Linklist Headone);//在文件里更新餐桌
void Shuchupaixu(linklist head);//输出排序

void User_Order(Linklist Headone, linklist head, int order[10][20]);//点餐 
void Sales_statistics(int order[10][20]);//销售统计
int  All(int j);//结账 
int order[10][20]={0};
 
int main()
{
	int i,j,k;
	linklist head;//餐桌信息结点
    LINKLIST headone;//用户信息结点
    Linklist Headone;//餐桌信息结点
    head=(linklist)malloc(sizeof(lnode));
    headone=(LINKLIST)malloc(sizeof(LNODE));
    Headone=(Linklist)malloc(sizeof(Lnode));
    head->next=NULL;
    headone->next=NULL;
    Headone->next = NULL;

    input_new_book_information(head);//录入菜品信息
    input_users_information(headone);//录入用户信息
    input_table_information(Headone);//录入餐桌信息

	printf("\n=========欢迎光临逸香阁==========\n");
	printf("\n=========== 请登录 ==============\n");
	printf("[1]:用户登录       [2]:管理员登陆\n");
	scanf("%d",&k);//判断要进行的操作
	switch(k)
	{
		case 1:judge(headone,head, Headone, order);break;//用户登录 
		case 2:judge(headone,head, Headone, order);break;//管理员登录 
	}
	return 0;
//	system("cls");
}

void judge(LINKLIST headone,linklist head, Linklist Headone, int order[10][20])//判断账号密码，然后进入系统
{
    char ID[20];
    char cryptogram[20],c;
    int right;
    int x=-1;
    printf("请输入您的账号:\n");
    scanf("%s",ID);
    printf("请输入您的密码:\n");
    while(x < 20&& c != 13)   //13是回车符的ASCII码
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
				printf("密码错误\n");
				judge(headone,head, Headone, order);
			}
			else
			{
				if(q->right ==0)
				{
				    printf("登陆成功\n");
				    system("pause");
				    system("cls");
					manger(headone,head, Headone, order);
				}
				else if(q->right ==1)
				{
				    printf("登陆成功\n");
				    system("pause");
				    system("cls");
					user(headone,head, Headone, order);
				}
			}
		}
		q=q->next ;
	}
}

void user(LINKLIST headone,linklist head, Linklist Headone, int order[10][20])//用户系统 
	{
	int aaa;
	while(1){
	 	printf("\n============== 逸香阁 ==============\n");
		printf("[1]：点餐              [2]: 查看菜单\n");
		printf("[3]：修改密码          [4]: 退出登录\n");
		printf("请选择您需要的服务：\n");
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
 
void manger(LINKLIST headone,linklist head, Linklist Headone, int order[10][20])//管理员系统 
	{ 
	int bbb;
	while(1)
	{
		printf("\n=============== 逸香阁 ===============\n");
		printf("[1]：餐桌列表           [2]: 查看菜单\n");
		printf("[3]：添加菜品           [4]: 删除菜品\n");
        printf("[5]；添加餐桌           [6]；删除餐桌\n");
		printf("[7]: 销售统计           [8]: 用户信息\n");
		printf("[9]: 修改密码           [10]: 修改用户密码 \n");
		printf("[11]: 添加用户          [12]；删除用户\n");
		printf("[13]:退出登录\n");
		printf("请选择您需要的服务；\n");
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

void input_new_book_information(linklist head)//文件添加新菜品信息
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
void input_a_new_book_information(linklist head)//添加菜品信息
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
    printf("请输入待添加菜品信息:\n");
    printf("编号      菜名      类别        价格\n");
    printf("输入#表示输入结束\n");
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
            printf("添加成功\n");
        }
        if(s==1)
        {
            printf("该菜品编号重复!\n");
        }
    }
    system("pause");
    InS(head);
    
}

void input_users_information(LINKLIST headone)//录入用户信息
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

void Browse_all_book_information(linklist head)//浏览全部菜品信息
{
    Shuchupaixu(head);
    printf("编号      菜名                类别                价格\n");
    linklist p=head->next;
	while(p)
	{
		printf("%-10s%-20s%-20s%-10s%",p->number,p->title,p->category, p->price);
		printf("\n");
		p=p->next;
	}
	system("pause");
}
void Browse_all_users_information(LINKLIST headone)//浏览全部用户信息
{
    printf("账号         密码            身份(1为用户，0为管理员)\n");
    LINKLIST p=headone->next;
    while(p)
    {
        printf("%-15s%-15s%-10d",p->ID,p->cryptogram,p->right);
        printf("\n");
        p=p->next;
    }
    system("pause");
}
void Delete_book_information(linklist head)//删除菜品信息
{
    int s=0;
    char number[20];
    char title[20];
    char category[20];
    char price[10];
    printf("请输入要删除的菜品编号:\n");
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
	    printf("删除成功\n");
    }
	if(s==0)
    {
        printf("查无此菜品信息！\n");
    }
    system("pause");
    InS(head);
}
void Search_by_title(linklist head)//按菜名查询
{
    int s=0;
    char title[20];
    printf("请输入待查询菜品名称\n");
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
        printf("查无此菜品信息！\n");
    }
    else if(s==1)
    {
        printf("编号      菜名                类别         价格\n");
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

void Create_general_reader_accounts(LINKLIST headone)//创建用户账号
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
    printf("请输入要创建账号的账号和密码\n");
    printf("输入#表示输入结束\n");
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
        printf("创建成功\n");
        }
        else if(s==1)
        {
            printf("用户账号已存在\n");
        }
    }
	system("pause");
	InU(headone);
}
void Delete_regular_reader_accounts(LINKLIST headone)//删除用户账号
{
    int s=0;
    char ID[20];
    char cryptogram[20];
    int right;
    LINKLIST q=headone;
    printf("请输入待删除用户的账号:\n");
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
	printf("删除成功\n");
    }
    else if(s==0)
    {
        printf("账号不存在\n");
    }
    system("pause");
	InU(headone);
}
void Reset_individual_user_passwords(LINKLIST headone)//修改用户密码
{
    char ID[20];
    char cryptogram[20];
    int s=0;
    LINKLIST q=headone;
    printf("请输入要修改密码的用户账号\n");
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
        printf("用户不存在\n");
    }
    if(s==1)
    {
        printf("请输入该用户账号的新密码\n");
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
    printf("重置成功\n");
    }
    system("pause");
    InU(headone);
}

void InS(linklist head)//添加菜品 
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
void InU(LINKLIST headone)//在文件里更新用户 
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

void input_table_information(Linklist Headone)//录入餐桌信息
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

void Add_table(Linklist Headone)//添加餐桌
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
    printf("请输入要添加的餐桌号码和可容纳人数\n");
    printf("输入#表示输入结束\n");
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
        printf("餐桌添加成功\n");
        }
        else if(s==1)
        {
            printf("餐桌已存在\n");
        }
    }
	system("pause");
	InT(Headone);
}

void Delete_table(Linklist Headone)//删除餐桌
{
    int s=0;
    char ID[20];
    char num[20];
    char amount[20];
    Linklist q=Headone;
    printf("请输入待删除餐桌的号码:\n");
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
        printf("删除成功\n");
    }
    else if(s==0)
    {
        printf("餐桌不存在\n");
    }
    system("pause");
	InT(Headone);
}

void Administrator_List_Table(Linklist Headone)//餐桌列表 
{
    printf("餐桌号:        可容纳人数:        已坐人数:\n");
    Linklist p=Headone->next;
    while(p)
    {
        printf("%-20s%-20s%-20s",p->ID,p->num,p->amount);
        printf("\n");
        p=p->next;
    }
    system("pause");
}
void InT(Linklist Headone)//在文件里更新餐桌
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

void User_Order(Linklist Headone, linklist head, int order[10][20])//点餐 
{
	char ID[10];
	char amount[10];
	int s=1,i, j=0, m;
	double all = 0;
	printf("餐桌号：         可容纳人数:           已坐人数：\n");
	Linklist p=Headone->next;
	while(p)
    {
        printf("%-20s%-20s%-20s",p->ID,p->num,p->amount);
        printf("\n");
        p=p->next;
    }
    printf("请选择您的餐桌：\n");
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
    	printf("餐桌不存在！请选择其他餐桌：\n");
	}
	if(s == 1)
	{
		printf("请输入用餐人数：\n");
		scanf("%s", amount);
		while(p)
		{
			strcpy(p->amount, amount);
			break;
			p = p->next;
		}
		printf("餐桌预定成功!\n");
	}
	Shuchupaixu(head);
    printf("编号      菜名                类别                 价格\n");
    linklist q=head->next;
	while(q)
	{
		printf("%-10s%-20s%-20s%-10s%",q->number,q->title,q->category, q->price);
		printf("\n");
		q=q->next;
	}
	printf("请输入您需要的菜品编号(输入'-1'代表结束选餐)：\n");
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
	printf("选菜成功，您选择有：\n");
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
	printf("共计花费：%.2f\n", all);
	
	system("pause");
 }
 
 void Sales_statistics(int order[10][20])//销售统计
 {
 	int i, j;  
 	double m[10]={0}, n=0;
	for(i=0; i<10; i++)
	{
		if(order[i][0]==0)
			break;
		else{
			printf("%d号桌的点餐：\n", i); 
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
			printf("\n共计消费：%.2f\n", m[i]);
			n += m[i];
		}
	}
	printf("今日营业额：%.2f\n", n);
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

void Shuchupaixu(linklist head)//菜品排序
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

