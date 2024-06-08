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
void fun_in_recompose(int form_r,int mem_num_r);
void fun_in_delete(int mem_num_r);
int fun_in_chose(void);

int number=3;//文档内储存的联系人个数
char key='b';
int mem_find_num=0;//查找中符合条件的对象个数
int mem_num;//符合条件的对象的脚标

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
    printf("  welcome!\n按enter键继续");
    getchar();
    fun_in_read();
    system("cls") ;
    while(key=='b')
    {
        system("cls") ;
        menu();
        printf("选择你想实现的功能:_\b");
        scanf("%d",&fun_num);
        getchar();

        switch (fun_num)
        {
            case 1:fun_call();//拨号功能
                break;
            case 2:fun_view();//查看功能
                break;
            case 3:fun_add();//添加功能
                break;
            case 4:fun_recompose();//修改功能
                break;
            case 5:fun_delete();//删除功能
                break;
            case 6:key='0';//退出
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
    printf("*********  3.添加  **********\n");
    printf("*********  4.修改  **********\n");
    printf("*********  5.删除  **********\n");
    printf("*********  6.退出  **********\n");
    printf("*****************************\n");
    printf("*****************************\n");
}

void fun_call(void)
{
    system("cls");
    int form=0;
    printf("请输入将要拨打的联系人信息");
    fun_in_chose();
    
        printf("1.拨打主电话\n2.拨打家庭电话\n3.拨打办公电话\n");
        printf("请选择你要拨打的方式：");
        scanf("%d",&form);
        getchar();
        // printf("%d,%d.%s",form,number,mem[mem_num].phonenum);
        if(form==1)
        {
            fun_in_call(mem[mem_num].phonenum);
        }
        else if(form==2)
        {
            fun_in_call(mem[mem_num].home_phonenum);
        }
        else if(form==3)
        {
            fun_in_call(mem[mem_num].office_phonenum);
        }
    
    printf("\n输入b返回主界面，按其他键结束应用");
    key=getchar();
    getchar();
}

int fun_in_chose(void)
{
    char arr[20];
    while(1)
    {
    printf("__________\b\b\b\b\b\b\b\b\b\b");
    scanf("%s",arr);
    getchar();
    mem_find_num=fun_in_find(arr);
    if(mem_find_num==0)
    {
        printf("未找到对应数据\n");
    }
    else if(mem_find_num>=2)
    {
        printf("请输入详细信息，以便找到唯一对应数据");
    }
    else if(mem_find_num==1)
    {
        return mem_num;
    }
    }
}

void fun_in_call(char phone[])
{
    system("cls");
    int n=0;
    for(n=0;phone[n]!='\0';n++)
    {
        printf("%c",phone[n]);
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
    
        fscanf(fp, "%s\n%s\n%s\n%s\n%s\n%s\n", 
        mem[num_read].name, mem[num_read].phonenum,  
        mem[num_read].home_phonenum, mem[num_read].office_phonenum,  
        mem[num_read].email, mem[num_read].group) ;
    while(!feof(fp))
    {
        num_read++;
        fscanf(fp, "%s\n%s\n%s\n%s\n%s\n%s\n", 
        mem[num_read].name, mem[num_read].phonenum,  
        mem[num_read].home_phonenum, mem[num_read].office_phonenum,  
        mem[num_read].email, mem[num_read].group) ;
    }
    number=num_read+1;
     fclose(fp);  
  
}
  
void fun_view(void)
{
    system("cls");
    int num_view=0;
    fun_in_read();

    for (num_view = 0; num_view < number; num_view++) 
    {  
        printf("___________________\n") ;
        printf("姓名：%s\n电话：%s\n家庭电话：%s\n办公电话：%s\n邮件：%s\n分组：%s\n",    
        mem[num_view].name, mem[num_view].phonenum,  
        mem[num_view].home_phonenum, mem[num_view].office_phonenum,  
        mem[num_view].email, mem[num_view].group); 
        
    }
    printf("\n按a键进行查找功能,按c键进行拨号，按b键回到主界面");
    //printf("%d",number);
    key=getchar();
    getchar();
    if(key=='a')
    {      
        fun_find();
    }  
    else if(key=='c')
    {
        fun_call();
    } 
   
}

int fun_in_find(char str[])
{
    mem_find_num=0;
    mem_num=0;
    int k=0;
    int n=0;
    // printf("%s",str);
    int num_find=0;
    for(num_find=0;num_find<number;num_find++)
    {
        k=0;
        if(strstr(mem[num_find].name,str)!=0)
        {
            printf("_______________________\n");
            printf("名字：%s\n电话：%s\n家庭电话：%s\n办公电话：%s\n邮件：%s\n分组：%s\n",  
            mem[num_find].name, mem[num_find].phonenum,  
            mem[num_find].home_phonenum, mem[num_find].office_phonenum,  
            mem[num_find].email, mem[num_find].group);
            k=1;
            goto FIND;
        }
        if(strstr(mem[num_find].phonenum,str)!=0)
        {
            printf("_______________________\n");
            printf("名字：%s\n电话：%s\n家庭电话：%s\n办公电话：%s\n邮件：%s\n分组：%s\n",  
            mem[num_find].name, mem[num_find].phonenum,  
            mem[num_find].home_phonenum, mem[num_find].office_phonenum,  
            mem[num_find].email, mem[num_find].group);  
            k=1;
            goto FIND;
        }
        if(strstr(mem[num_find].home_phonenum,str)!=0)
        {
            printf("_______________________\n");
            printf("名字：%s\n电话：%s\n家庭电话：%s\n办公电话：%s\n邮件：%s\n分组：%s\n",
            mem[num_find].name, mem[num_find].phonenum,  
            mem[num_find].home_phonenum, mem[num_find].office_phonenum,  
            mem[num_find].email, mem[num_find].group);  
            k=1;
            goto FIND;
        }
        if(strstr(mem[num_find].office_phonenum,str)!=0)
        {
            printf("_______________________\n");
            printf("名字：%s\n电话：%s\n家庭电话：%s\n办公电话：%s\n邮件：%s\n分组：%s\n", 
            mem[num_find].name, mem[num_find].phonenum,  
            mem[num_find].home_phonenum, mem[num_find].office_phonenum,  
            mem[num_find].email, mem[num_find].group); 
            k=1;
            goto FIND;
        }
        if(strstr(mem[num_find].email,str)!=0)
        {
            printf("_______________________\n");
            printf("名字：%s\n电话：%s\n家庭电话：%s\n办公电话：%s\n邮件：%s\n分组：%s\n",  
            mem[num_find].name, mem[num_find].phonenum,  
            mem[num_find].home_phonenum, mem[num_find].office_phonenum,  
            mem[num_find].email, mem[num_find].group);  
            k=1;
            goto FIND;
        }
        if(strstr(mem[num_find].group,str)!=0)
        {
            printf("_______________________\n");
            printf("名字：%s\n电话：%s\n家庭电话：%s\n办公电话：%s\n邮件：%s\n分组：%s\n",  
            mem[num_find].name, mem[num_find].phonenum,  
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
            mem_find_num++;
            
        }
    }
    return mem_find_num;
}

void fun_find()
{
    system("cls");
    char str[10];

    printf("输入你要查找的信息\n");
    scanf("%s",str);
    // printf("%s",str);
    getchar();
    fun_in_find(str);
    
    printf("按b键返回主界面，按其他键结束功能");
    key=getchar();
    getchar();
}

void fun_add(void)
{
    int ph=0;
    int n=0;
    struct member mem_add=
    {
        .name={"null"},
        .phonenum={"null"},
        .home_phonenum={"null"},
        .office_phonenum={"null"},
        .email={"null"},
        .group={"未知"}
    };
    
    system("cls");
    back1:
    printf("请输入你要保存的信息,输入完毕之后点击回车\n");
    printf("姓名：________\b\b\b\b\b\b\b\b");
    scanf("%s",mem_add.name);
    getchar();
    for(n=0;n<number;n++)
    {
        if((strstr(mem_add.name,mem[n].name))!=0)
        {
            printf("你输入的用户名和已存在的用户名发生重叠,按enter重写");
            getchar();
            goto back1;
        }
        if((strstr(mem[n].name,mem_add.name))!=0)
        {
            printf("你输入的用户名和已存在的用户名发生重叠,按enter重写");
            getchar();
            goto back1;
        }
    }

    add:
    printf("电话号码：____________\b\b\b\b\b\b\b\b\b\b\b\b");
    printf("是否填写？(y/n)\n");
    key=getchar();
    getchar();
    if(key=='y')
    {
        back2:
        printf("请输入  ");
        scanf("%s",mem_add.phonenum);
        getchar();
        ph=1;
    
    for(n=0;n<number;n++)
    {
        if((strstr(mem_add.phonenum,mem[n].phonenum))!=0)
        {
            printf("你输入的电话已存在,按enter键重新输入");
            getchar();
            goto back2;
        }
    }
    for(n=0;n<number;n++)
    {
        if(strstr(mem_add.phonenum,mem[n].home_phonenum)!=0)
        {
            printf("你输入的电话已存在,按enter键重新输入");
            getchar();
            goto back2;
        }
    }
    for(n=0;n<number;n++)
    {
        if((strstr(mem_add.phonenum,mem[n].office_phonenum))!=0)
        {
            printf("你输入的电话已存在,按enter键重新输入");
            getchar();
            goto back2;
        }
    }
    }

   
    printf("家庭号码：____________\b\b\b\b\b\b\b\b\b\b\b\b");
    printf("是否填写？(y/n)\n");
    key=getchar();
    getchar();
    if(key=='y')
    {
        back3:
        printf("请输入  ");
        scanf("%s",mem_add.home_phonenum);
        getchar();
        ph=1;
    
    for(n=0;n<number;n++)
    {
        if((strstr(mem_add.home_phonenum,mem[n].phonenum))!=0)
        {
            printf("你输入的电话已存在,按enter键重新输入");
            getchar();
            goto back3;
        }
    }
    for(n=0;n<number;n++)
    {
        if((strstr(mem_add.home_phonenum,mem[n].home_phonenum))!=0)
        {
            printf("你输入的电话已存在,按enter键重新输入");
            getchar();
            goto back3;
        }
    }
    for(n=0;n<number;n++)
    {
        if((strstr(mem_add.home_phonenum,mem[n].office_phonenum))!=0)
        {
            printf("你输入的电话已存在,按enter键重新输入");
            getchar();
            goto back3;
        }
    }
    }

    printf("办公号码：____________\b\b\b\b\b\b\b\b\b\b\b\b");
    printf("是否填写？(y/n)\n");
    key=getchar();
    getchar();
    if(key=='y')
    {
         back4:
        printf("请输入  ");
        scanf("%s",mem_add.office_phonenum);
        getchar();
        ph=1;
    
        for(n=0;n<number;n++)
    {
        if((strstr(mem_add.office_phonenum,mem[n].phonenum))!=0)
        {
            printf("你输入的电话已存在,按enter键重新输入");
            getchar();
            goto back4;
        }
    }
    for(n=0;n<number;n++)
    {
        if((strstr(mem_add.office_phonenum,mem[n].home_phonenum))!=0)
        {
            printf("你输入的电话已存在,按enter键重新输入");
            getchar();
            goto back4;
        }
    }
    for(n=0;n<number;n++)
    {
        if((strstr(mem_add.office_phonenum,mem[n].office_phonenum))!=0)
        {
            printf("你输入的电话已存在,按enter键重新输入");
            getchar();
            goto back4;
        }
    }
    }

    if(ph==0)
    {
        printf("必须输入至少一条号码，请重新填写\n");
        goto add;
    }
    

    
    printf("邮件：____________\b\b\b\b\b\b\b\b\b\b\b\b");
    printf("是否填写？(y/n)\n");
    key=getchar();
    getchar();
    if(key=='y')
    {
        back5:
        printf("请输入  ");
        scanf("%s",mem_add.email);
        getchar();
    
    for(n=0;n<number;n++)
    {
        if((strstr(mem_add.email,mem[n].email))!=0)
        {
            printf("你输入的邮件已存在,按enter键重新输入");
            getchar();
            goto back5;
        }
    }
    }
    
    printf("分组：________\b\b\b\b\b\b\b\b");
    printf("是否填写？(y/n)\n");
    key=getchar();
    getchar();
    if(key=='y')
    {
        printf("请输入  ");
        scanf("%s",mem_add.group);
        getchar();
    }

    
    number++;
    
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
    
    fclose(fp);
    fun_in_read();
    printf("输入完毕，按a继续，按b回到主界面");
    key=getchar();
    getchar();
    if(key=='a')
    {
        fun_add();
    }
    //将变量写入文件中
}

void fun_recompose()
{
    system("cls");
    int form=0;
    printf("查找你要修改的对象，请输入查找信息\n");
    fun_in_chose();

    printf("请选择你要修改的选项：\n");
    printf("1.名字2.主电话3.家庭电话4.办公电话5.邮件6.分组\n");
    scanf("%d",&form);
    getchar();
    //printf("%d%d",form,mem_num);
    fun_in_recompose(form,mem_num);

    printf("输入b返回主界面，");
    key=getchar();
    getchar();
}

void fun_in_recompose(int form_r,int mem_num_r)
{
    int n=0;
    if(form_r==1)
    {
        printf("输入该联系人的新名字");
        scanf("%s",mem[mem_num_r].name);
        getchar();

    }
    if(form_r==2)
    {
        printf("输入该联系人的新主电话");
        scanf("%s",mem[mem_num_r].phonenum);
        getchar();

    }
    if(form_r==3)
    {
        printf("输入该联系人的新家庭电话");
        scanf("%s",mem[mem_num_r].home_phonenum);
        getchar();

    }
    if(form_r==4)
    {
        printf("输入该联系人的新办公电话");
        scanf("%s",mem[mem_num_r].office_phonenum);
        getchar();

    }
    if(form_r==5)
    {
        printf("输入该联系人的新邮件");
        scanf("%s",mem[mem_num_r].email);
        getchar();

    }
    if(form_r==6)
    {
        printf("输入该联系人的新分组");
        scanf("%s",mem[mem_num_r].group);
        getchar();

    }

    FILE*fp;
    fp=fopen("D:\\dev\\phonebook\\data.txt","w");
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
    fun_in_read();
    fclose(fp);
}


void fun_delete()
{
    int form=0;
    printf("查找你要删除的对象");
    fun_in_chose();
    
    printf("你确定要删除该用户吗?(y/n)");
    key=getchar();
    getchar();
    if(key=='y')
        {
        fun_in_delete(mem_num);
        fun_in_read();
        }
    printf("输入b返回主界面，");
    key=getchar();
    getchar();
}

void fun_in_delete(int mem_num_r)
{
    int n=0;
    FILE*fp;
    fp=fopen("D:\\dev\\phonebook\\data.txt","w");
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
