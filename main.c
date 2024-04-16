#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<windows.h>

void menu(void);
void fun_call(void);
void fun_view(void);
void fun_find(void);
void fun_edit(void);
void fun_add(void);
void fun_recompose(void);
void fun_delete(void);
void fun_in_read(void);
int fun_in_find(char str[]);
void fun_in_call(char phone[]);
void fun_in_recompose(int,int);
void fun_in_delete(int,int);

int number=3;
char key='b';
char call_phone[15];
char call_home_phone[15];
char call_office_phone[15];
int mem_find_num=0;
int mem_num;
int swi=0;

struct member
{
    char name[20];
    char phonenum[15]; 
    char home_phonenum[15];
    char office_phonenum[15];
    char email[20];
    char group[10];
};//结构体的定义

struct member mem[20];
struct member mem_find[20];

int main()
{
    int fun_num;
    printf("welcome!\n按enter键继续");
    getchar();
    fun_in_read();
    system("cls") ;
    while(key=='b')
    {
        system("cls") ;
        menu();
        printf("选择你想实现的功能:_\b\n");
        scanf("%d",&fun_num);
        getchar();

        switch (fun_num)
        {
            case 1:fun_call();//拨号
                break;
            case 2:fun_view();//查看
                break;
            case 3:fun_find();//查找
                break;
            case 4:fun_add();//添加
                break;
            case 5:fun_recompose();
                break;
            case 6:fun_delete();
                break;
            case 7:key='0';//退出
                break;
            default :printf("输入错误\n");
                printf("按enter键重新输入");
                getchar();
        }
    }
}

void menu(void)
{
    printf("*****************************\n");
    printf("*****************************\n");
    printf("*********  1.拨号  **********\n");
    printf("*********  2.查看  **********\n");
    printf("*********  3.查找  **********\n");
    printf("*********  4.添加  **********\n");
    printf("*********  5.修改  **********\n");
    printf("*********  6.删除  **********\n");
    printf("*********  7.退出  **********\n");
    printf("*****************************\n");
    printf("*****************************\n");
}

void fun_call(void)
{
    system("cls");
    int form=0;
    char str[10];
    system("cls");
    back:
    printf("输入你想拨打的电话号码或联系人:_______\b\b\b\b\b");
    scanf("%s",str);
    getchar();
    mem_find_num=fun_in_find(str);
    if(mem_find_num==0)
    {
        printf("查找不到有关信息");
    }
    else if(mem_find_num==1)
    {
        printf("请选择你要拨打的方式：\n");
        printf("1.拨打主电话2.拨打家庭电话3.拨打办公电话");
        scanf("%d",&form);
        getchar();
        if(form==1)
        {
            fun_in_call(call_phone);
        }
        else if(form==2)
        {
            fun_in_call(call_home_phone);
        }
        else if(form==3)
        {
            fun_in_call(call_office_phone);
        }
    }
    else if(mem_find_num>=2)
    {
        printf("请输入更为详细的信息，以便我能确定你所拨打的对象");
        goto back;
    }
    printf("输入b返回主界面，");
    key=getchar();
    getchar();
}

void fun_in_call(char phone[])
{
    int n=0;
    for(n=0;phone[n]!='\0';);
    {
        printf("%c",&phone[n]);
        Sleep(1000);
    }
    printf("\n拨号中");
    for(n=0;n<=5;n++)
    {
        printf(".");
        Sleep(1000);
    }
}

void fun_in_read()
{
    int num_read=0;

    FILE*fp;
    fp=fopen("D:\\dev\\phonebook\\data.txt","r");
    if(fp==0)
    {
        printf("ERROR:文件打开失败");
        exit(1);
    } 
    
    for (num_read = 0; num_read < number; num_read++)
    {  
        fscanf(fp, "%s\n%s\n%s\n%s\n%s\n%s\n", 
        mem[num_read].name, mem[num_read].phonenum,  
        mem[num_read].home_phonenum, mem[num_read].office_phonenum,  
        mem[num_read].email, mem[num_read].group) ;
    }  
     fclose(fp);  
  
}
  
void fun_view(void)
{
    int num_view=0;
    fun_in_read();

    for (num_view = 0; num_view < number; num_view++) 
    {  
        printf("%s\n%s\n%s\n%s\n%s\n%s\n",    
        mem[num_view].name, mem[num_view].phonenum,  
        mem[num_view].home_phonenum, mem[num_view].office_phonenum,  
        mem[num_view].email, mem[num_view].group);  
    }
    printf("按a键进行查找功能,按c键进行拨号，按b键回到主界面");
    key=getchar();
    getchar();
    if(key=='a')
    {      
        fun_find();
    }  
    else if(key=='c')
    {
        fun_call;
    } 
   
}

int fun_in_find(char str[])
{
    mem_find_num=0;
    int k=0;
    int n=0;
    printf("%s",str);
    int num_find;
    for(num_find=0;num_find<number;num_find++)
    {
        k=0;
        if(strstr(mem[num_find].name,str)!=0)
        {
            printf("%s\n%s\n%s\n%s\n%s\n%s\n",  
            mem[num_find].name, mem[num_find].phonenum,  
            mem[num_find].home_phonenum, mem[num_find].office_phonenum,  
            mem[num_find].email, mem[num_find].group);
            k=1;
            goto FIND;
        }
        if(strstr(mem[num_find].phonenum,str)!=0)
        {
            printf("%s\n%s\n%s\n%s\n%s\n%s\n",    
            mem[num_find].name, mem[num_find].phonenum,  
            mem[num_find].home_phonenum, mem[num_find].office_phonenum,  
            mem[num_find].email, mem[num_find].group);  
            k=1;
            goto FIND;
        }
        if(strstr(mem[num_find].home_phonenum,str)!=0)
        {
            printf("%s\n%s\n%s\n%s\n%s\n%s\n",   
            mem[num_find].name, mem[num_find].phonenum,  
            mem[num_find].home_phonenum, mem[num_find].office_phonenum,  
            mem[num_find].email, mem[num_find].group);  
            k=1;
            goto FIND;
        }
        if(strstr(mem[num_find].office_phonenum,str)!=0)
        {
            printf("%s\n%s\n%s\n%s\n%s\n%s\n",  
            mem[num_find].name, mem[num_find].phonenum,  
            mem[num_find].home_phonenum, mem[num_find].office_phonenum,  
            mem[num_find].email, mem[num_find].group); 
            k=1;
            goto FIND;
        }
        if(strstr(mem[num_find].email,str)!=0)
        {
            printf("%s\n%s\n%s\n%s\n%s\n%s\n",  
            mem[num_find].name, mem[num_find].phonenum,  
            mem[num_find].home_phonenum, mem[num_find].office_phonenum,  
            mem[num_find].email, mem[num_find].group);  
            k=1;
            goto FIND;
        }
        if(strstr(mem[num_find].group,str)!=0)
        {
            printf("%s\n%s\n%s\n%s\n%s\n%s\n"  
            ,mem[num_find].name, mem[num_find].phonenum,  
            mem[num_find].home_phonenum, mem[num_find].office_phonenum,  
            mem[num_find].email, mem[num_find].group);  
            k=1;
            goto FIND;
        }
        FIND:
        if(k)
        {
            strcpy(mem_find[n].name,mem[num_find].phonenum);
            strcpy(mem_find[n].phonenum,mem[num_find].home_phonenum);
            strcpy(mem_find[n].home_phonenum,mem[num_find].office_phonenum);
            strcpy(mem_find[n].office_phonenum,mem[num_find].phonenum);
            strcpy(mem_find[n].email,mem[num_find].home_phonenum);
            strcpy(mem_find[n].group,mem[num_find].office_phonenum);
            mem_num=num_find;
            strcpy(call_phone,mem[num_find].phonenum);
            strcpy(call_home_phone,mem[num_find].home_phonenum);
            strcpy(call_office_phone,mem[num_find].office_phonenum);
            mem_find_num++;
            
        }
    }
    //if()

    
    return mem_find_num;
}
void fun_find()
{

    
    system("cls");
    char str[10];

    printf("输入你要查找的信息\n");
    scanf("%s",str);
    printf("%s",str);
    getchar();
    fun_in_find(str);
    
    printf("按b键返回主界面，按其他键结束功能");
    key=getchar();
    getchar();
}



void fun_add(void)
{
    struct member mem_add;
    printf("请输入你要保存的信息,输入完毕之后点击回车\n");
    printf("姓名：________\b\b\b\b\b\b\b\b");
    scanf("%s",mem_add.name);
    getchar();
    printf("电话号码：________\b\b\b\b\b\b\b\b");
    scanf("%s",mem_add.phonenum);
    getchar();
    printf("家庭号码：________\b\b\b\b\b\b\b\b");
    scanf("%s",mem_add.home_phonenum);
    getchar();
    printf("办公号码：________\b\b\b\b\b\b\b\b");
    scanf("%s",mem_add.office_phonenum);
    getchar();
    printf("邮件：________\b\b\b\b\b\b\b\b");
    scanf("%s",mem_add.email);
    getchar();
    printf("分组：________\b\b\b\b\b\b\b\b");
    scanf("%s",mem_add.group);
    getchar();
    number++;
    printf("输入完毕，按a键继续");
   
    //将数据输入到结构体变量中


    FILE*fp;
    fp=fopen("D:\\dev\\phonebook\\data.txt","a+");
    if(fp==0)
    {
        printf("ERROR:文件打开失败");
        exit(1);
    }
    else
    {
        fprintf(fp,"%s\n%s\n%s\n%s\n%s\n%s\n"
        ,mem_add.name,mem_add.phonenum,mem_add.home_phonenum,mem_add.office_phonenum,mem_add.email,mem_add.group);
    }
    if(getchar()=='a')
    {
        fun_add();
    }
    
    fclose(fp);
    //将变量写入文件中
}

void fun_recompose()
{
    int form=0;
    char str[10];
    recom:
    printf("输入你想的电话号码或联系人:_______\b\b\b\b\b");
    scanf("%s",str);
    getchar();
    mem_find_num=fun_in_find(str);
    if(mem_find_num==0)
    {
        printf("查找不到有关信息");
    }
    else if(mem_find_num==1)
    {

        printf("请选择你要修改的选项：\n");
        printf("1.名字2.主电话3.家庭电话4.办公电话5.邮件6.分组");
        scanf("%d",&form);
        getchar();
        fun_in_recompose(form,mem_num);
    }
    else if(mem_find_num>=2)
    {
        printf("请输入更为详细的信息，以便我能确定你所拨打的对象");
        goto recom;
    }
    printf("输入b返回主界面，");
    key=getchar();
    getchar();
}

void fun_in_recompose(int form_r,int mem_num_r)
{
    int n=0;
    if(form_r==1)
    {
        scanf("%s",mem[mem_num_r].name);
        getchar();

    }
    if(form_r==2)
    {
        scanf("%s",mem[mem_num_r].phonenum);
        getchar();

    }
    if(form_r==3)
    {
        scanf("%s",mem[mem_num_r].home_phonenum);
        getchar();

    }
    if(form_r==4)
    {
        scanf("%s",mem[mem_num_r].office_phonenum);
        getchar();

    }
    if(form_r==5)
    {
        scanf("%s",mem[mem_num_r].email);
        getchar();

    }
    if(form_r==6)
    {
        scanf("%s",mem[mem_num_r].group);
        getchar();

    }

    FILE*fp;
    fp=fopen("D:\\dev\\phonebook\\data.txt","r+");
    if(fp==0)
    {
        printf("ERROR:文件打开失败");
        exit(1);
    }
    for(n=0;n<number;n++)
    {
        fprintf(fp,"%s\n%s\n%s\n%s\n%s\n%s\n"
        ,mem[n].name,mem[n].phonenum,mem[n].home_phonenum,mem[n].office_phonenum,mem[n].email,mem[n].group);
    }
    fclose(fp);
}


void fun_delete()
{
        int form=0;
    char str[10];
    recom:
    printf("输入你想的电话号码或联系人:_______\b\b\b\b\b");
    scanf("%s",str);
    getchar();
    mem_find_num=fun_in_find(str);
    if(mem_find_num==0)
    {
        printf("查找不到有关信息");
    }
    else if(mem_find_num==1)
    {

        printf("请选择你要修改的选项：\n");
        printf("1.名字2.主电话3.家庭电话4.办公电话5.邮件6.分组");
        scanf("%d",&form);
        getchar();
        fun_in_delete(form,mem_num);
    }
    else if(mem_find_num>=2)
    {
        printf("请输入更为详细的信息，以便我能确定你所拨打的对象");
        goto recom;
    }
    printf("输入b返回主界面，");
    key=getchar();
    getchar();
}

void fun_in_delete(int form_r,int mem_num_r)
{
    int n=0;
    FILE*fp;
    fp=fopen("D:\\dev\\phonebook\\data.txt","r+");
    if(fp==0)
    {
        printf("ERROR:文件打开失败");
        exit(1);
    }
    for(n=0;n<number;n++)
    {
        if(n!=mem_num_r)
        {
            fprintf(fp,"%s\n%s\n%s\n%s\n%s\n%s\n"
        ,mem[n].name,mem[n].phonenum,mem[n].home_phonenum,mem[n].office_phonenum,mem[n].email,mem[n].group);
        }
    }
    number--;
    fun_in_read();
    fclose(fp);
}
