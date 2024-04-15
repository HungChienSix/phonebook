#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void menu(void);
void fun_call(void);
void fun_view(void);

void fun_edit(void);
void fun_add(void);
void fun_recompose(void);
void fun_delete(void);

int number=3;

struct member
{
    char name[20];
    char phonenum[15]; 
    char home_phonenum[15];
    char office_phonenum[15];
    char email[20];
    char group[10];
};//结构体的定义

int main()
{
    int fun_num;
    printf("welcome!\n");
    getchar();
    system("cls") ;

    menu();
    printf("选择你想实现的功能");
    scanf("%d",&fun_num);
    getchar();

    if(fun_num<=5&&fun_num>=0)
    {
        switch (fun_num)
    {
        case 1:fun_call();//拨号
            break;
        case 2:fun_view();//添加
            break;
        //case 3:fun_find();//查找
        //    break;
        case 4:fun_add();//修改
            break;
        case 5:fun_recompose();
            break;
        case 6:fun_delete();
            break;
        case 7://退出
            break;
        default :printf("\n输入错误\n");

    }
    }
}

void menu(void)
{
    printf("***********************\n");
    printf("***********************\n");
    printf("******  1.拨号  *******\n");
    printf("******  2.查看  *******\n");
    printf("******  3.查找  *******\n");
    printf("******  4.添加  *******\n");
    printf("******  5.修改  *******\n");
    printf("******  6.删除  ********\n");
    printf("******  7.退出  *******\n");
    printf("***********************\n");
}

void fun_call(void)
{
    system("cls");
    printf("输入你想拨打的电话号码或联系人");
}

  
void fun_view(void)
{
    void fun_find(void);
    struct member mem[20];
    int num_view=0;

    system("cls");

    FILE*fp;
    fp=fopen("D:\\dev\\phonebook\\data.txt","a+");
    if(fp==0)
    {
        printf("ERROR:文件打开失败");
        exit(1);
    } 
    
    for (num_view = 0; num_view < number; num_view++)
    {  
        fscanf(fp, "%s\n%ld\n%ld\n%ld\n%s\n%s\n",  
        mem[num_view].name, &mem[num_view].phonenum,  
        &mem[num_view].home_phonenum, &mem[num_view].office_phonenum,  
        mem[num_view].email, mem[num_view].group) ;
    }  
  
    for (num_view = 0; num_view < number; num_view++) 
    {  
        printf("%s\n%ld\n%ld\n%ld\n%s\n%s\n",  
        mem[num_view].name, mem[num_view].phonenum,  
        mem[num_view].home_phonenum, mem[num_view].office_phonenum,  
        mem[num_view].email, mem[num_view].group);  
    }
    printf("按a键进行查找功能");
    if(getchar()=='a')
        {
        getchar();
        int num_find;
        system("cls");
        char str[10];

        printf("输入你要查找的信息\n");
        scanf("%s",str);
        for(num_find=0;num_find<number;num_find++)
        {
            if(strstr(mem[num_find].name,str)!=0)
            {
                printf("%s\n%ld\n%ld\n%ld\n%s\n%s\n",  
                mem[num_find].name, mem[num_find].phonenum,  
                mem[num_find].home_phonenum, mem[num_find].office_phonenum,  
                mem[num_find].email, mem[num_find].group);  
            }
            if(strstr(mem[num_find].name,str)!=0)
            {
                printf("%s\n%ld\n%ld\n%ld\n%s\n%s\n",  
                mem[num_find].name, mem[num_find].phonenum,  
                mem[num_find].home_phonenum, mem[num_find].office_phonenum,  
                mem[num_find].email, mem[num_find].group);  
            }
            if(strstr(mem[num_find].name,str)!=0)
            {
                printf("%s\n%ld\n%ld\n%ld\n%s\n%s\n",  
                mem[num_find].name, mem[num_find].phonenum,  
                mem[num_find].home_phonenum, mem[num_find].office_phonenum,  
                mem[num_find].email, mem[num_find].group);  
            }
            if(strstr(mem[num_find].name,str)!=0)
            {
                printf("%s\n%ld\n%ld\n%ld\n%s\n%s\n",  
                mem[num_find].name, mem[num_find].phonenum,  
                mem[num_find].home_phonenum, mem[num_find].office_phonenum,  
                mem[num_find].email, mem[num_find].group);  
            }
            if(strstr(mem[num_find].name,str)!=0)
            {
                printf("%s\n%ld\n%ld\n%ld\n%s\n%s\n",  
                mem[num_find].name, mem[num_find].phonenum,  
                mem[num_find].home_phonenum, mem[num_find].office_phonenum,  
                mem[num_find].email, mem[num_find].group);  
            }
            if(strstr(mem[num_find].name,str)!=0)
            {
                printf("%s\n%ld\n%ld\n%ld\n%s\n%s\n",  
                mem[num_find].name, mem[num_find].phonenum,  
                mem[num_find].home_phonenum, mem[num_find].office_phonenum,  
                mem[num_find].email, mem[num_find].group);  
            }
        }
    
        }
    
    fclose(fp);  
}
    //int file_size;
    //char *tmp;
    //struct member mem;

 // fseek(fp, 0, SEEK_END);  
        // file_size = ftell(fp);  
        // char* tmp = (char*)malloc(file_size * sizeof(char)); // 正确声明和转换类型  
        // if (tmp == NULL) {  
        //     // 处理内存分配失败的情况  
        //     printf("ERROR: 内存分配失败\n");  
        //     fclose(fp);  
        //     exit(1);  
        // }  
        // memset(tmp, '\0', file_size); // 正确使用tmp  
        // fseek(fp, 0, SEEK_SET);  
        // fread(tmp, sizeof(char), file_size, fp); // 正确使用tmp  
        // printf("文件内容为\n%s", tmp);  

//void fun_find()



void fun_add(void)
{
    struct member mem;
    printf("请输入你要保存的信息,输入完毕之后点击回车\n");
    printf("姓名：________\b\b\b\b\b\b\b\b");
    scanf("%s",mem.name);
    getchar();
    printf("电话号码：________\b\b\b\b\b\b\b\b");
    scanf("%ld",&mem.phonenum);
    getchar();
    printf("家庭号码：________\b\b\b\b\b\b\b\b");
    scanf("%ld",&mem.home_phonenum);
    getchar();
    printf("办公号码：________\b\b\b\b\b\b\b\b");
    scanf("%ld",&mem.office_phonenum);
    getchar();
    printf("邮件：________\b\b\b\b\b\b\b\b");
    scanf("%s",&mem.email);
    getchar();
    printf("分组：________\b\b\b\b\b\b\b\b");
    scanf("%s",&mem.group);
    getchar();
    number++;
    printf("输入完毕，按a键继续");
    if(getchar()=='a')
        fun_add();
    
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
        fprintf(fp,"%s\n%ld\n%ld\n%ld\n%s\n%s\n",mem.name,mem.phonenum,mem.home_phonenum,mem.office_phonenum,mem.email,mem.group);
    }
    fclose(fp);
    //将变量写入文件中
}

void fun_recompose()
{
    
}

void fun_delete()
{
    
}
