#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void print_main_menu();
struct stu *create_1_1();
struct stu *create_1_2();
struct stu *create_1_3();
struct stu *sort_2(struct stu * head);
struct stu *insert_3(struct stu * head);
struct stu *delete_4(struct stu * head);
void print_5_1(struct stu * head);
void print_5_2(struct stu * head);
void search_6(struct stu * head);

struct stu{
    int num;
    char name[16];
    char sex;
    int age;
    double grade;
    struct stu *next;
};

int main(){
    struct stu * head=NULL;
    int num1,num2;
    while (1){
        print_main_menu();
        scanf("%d",&num1);
        while (num1<0 || num1>9 || num1==7 || num1==8){
            printf("输入有误，重新输入\n");
            scanf("%d",&num1);
        }
        switch(num1){
            case 1:
                printf("学生信息链表的建立\n");
                printf("1 头插法\n"
                        "2 尾插法\n"
                        "3 读取文件建立链表\n"
                        "0 返回主菜单\n\n");
                printf("请选择子菜单功能\n");
                scanf("%d",&num2);
                while (num2<0 || num2>3){
                    printf("输入有误，请重新输入\n");
                    scanf("%d",&num2);
                }
                switch(num2){
                    case 1:
                        head=create_1_1();
                        break;
                    case 2:
                        head=create_1_2();
                        break;
                    case 3:
                        head=create_1_3();
                        break;
                    case 0:
                        break;
                }
                break;
            case 2:
                printf("学生信息链表的节点排序\n");
                head=sort_2(head);
                break;
            case 3:
                printf("学生信息链表的节点插入\n");
                head=insert_3(head);
                break;
            case 4:
                printf("学生信息链表的节点删除\n");
                head=delete_4(head);
                break;
            case 5:
                printf("学生信息链表的输出\n");
                printf("1 屏幕输出\n"
                        "2 保存链表至文件\n"
                        "0 返回主菜单\n\n");
                printf("请选择子菜单功能\n");
                scanf("%d",&num2);
                while (num2<0 || num2>2){
                    printf("输入有误，请重新输入\n");
                    scanf("%d",&num2);
                }
                switch(num2){
                    case 1:
                        print_5_1(head);
                        break;
                    case 2:
                        print_5_2(head);
                        break;
                    case 0:
                        break;
                }
                break;
            case 6:
                printf("学生信息链表的查询\n");
                search_6(head);
                break;
            case 9:
                system("cls");
                break;
            case 0:
                printf("再见\n");
                return 0;
        }
    }
}

void print_main_menu(){
    printf("1 学生信息链表的建立\n"
           "  1 头插法\n"
           "  2 尾插法\n"
           "  3 读取文件建立链表\n"
           "  0 返回主菜单\n"
           "2 学生信息链表的节点排序\n"
           "3 学生信息链表的节点插入\n"
           "4 学生信息链表的节点删除\n"
           "5 学生信息链表的输出\n"
           "  1 屏幕输出\n"
           "  2 保存链表至文件\n"
           "  0 返回主菜单\n"
           "6 学生信息链表的查询\n"
           "9 清屏\n"
           "0 退出\n\n"
           );
   printf("请选择菜单功能：\n");
}

//1.1学生信息链表的建立（头插法）
struct stu *create_1_1(){
    struct stu *head=NULL;
    struct stu *p=NULL;
    int num,age;
    char name[16],sex;
    double grade;
    printf("输入学号，输入0结束\n");
    scanf("%d",&num);
    while (num){
        p=(struct stu*)malloc(sizeof(struct stu));
        p->num=num;
        printf("输入姓名\n");
        scanf("%s",p->name);
        getchar();
        printf("输入性别\n");
        sex=getchar();
        getchar();
        p->sex=sex;
        printf("输入年龄\n");
        scanf("%d",&age);
        p->age=age;
        printf("输入成绩\n");
        scanf("%lf",&grade);
        p->grade=grade;
        p->next=head;
        head=p;
        printf("输入学号\n");
        scanf("%d",&num);
    }
    printf("建立链表完毕\n\n");
    return head;
}

//1.2学生信息链表的建立（尾插法）
struct stu *create_1_2(){
    struct stu *head=NULL;
    struct stu *p=NULL;
    struct stu *q=NULL;
    int num,age;
    char name[16],sex;
    double grade;
    printf("输入学号，输入0结束\n");
    scanf("%d",&num);
    while (num){
        p=(struct stu*)malloc(sizeof(struct stu));
        p->num=num;
        printf("输入姓名\n");
        scanf("%s",p->name);
        getchar();
        printf("输入性别\n");
        sex=getchar();
        getchar();
        p->sex=sex;
        printf("输入年龄\n");
        scanf("%d",&age);
        p->age=age;
        printf("输入成绩\n");
        scanf("%lf",&grade);
        p->grade=grade;
        if (head==NULL){
            head=p;
        }
        else{
            q->next=p;
        }
        q=p;
        printf("输入学号\n");
        scanf("%d",&num);
    }
    printf("建立链表完毕\n\n");
    return head;
}

//1.3学生信息链表的建立（读取文件建立链表）
struct stu *create_1_3(){
    struct stu *p,*q,*head=NULL;
    FILE *fp;
    char fname[50];
    printf("输入要读取的文件名：\n");
    fflush(stdin);
    gets(fname);
    if ((fp=fopen(fname,"r"))==NULL){
        printf("文件无法打开，读取失败\n");
        return NULL;
    }
    while (1){
        p=(struct stu *)malloc(sizeof(struct stu));
        int result = fscanf(fp,"%d %s %c %d %lf",&p->num,p->name,&p->sex,&p->age,&p->grade);
        if (result<5){
            free(p);
            break;
        }
        p->next=NULL;
        if (head==NULL){
            head=p;
            q=p;
        }
        else{
            q->next=p;
            q=p;
        }
    }
    fclose(fp);
    printf("建立链表完毕\n\n");
    return head;
}

//2.学生信息链表的节点排序
struct stu *sort_2(struct stu * head){
    struct stu *p=NULL;
    struct stu *pre=NULL;
    int flag=1;
    while (flag){
        flag=0;
        if (head->grade<head->next->grade){
            struct stu *temp=head->next;
            head->next=temp->next;
            temp->next=head;
            head=temp;
            flag=1;
        }
        p=head->next;
        pre=head;
        while (p->next){
            if (p->grade<p->next->grade){
                flag=1;
                struct stu *temp=p->next;
                p->next=temp->next;
                temp->next=p;
                pre->next=temp;
            }
            p=p->next;
            pre=p;
        }
    }
    printf("排序完毕！\n");
    return head;
}

//3.学生信息链表的节点插入
struct stu *insert_3(struct stu * head){
    int order=0;
    int flag=1;
    struct stu *p=head;
    if (p==NULL || p->next==NULL){
        printf("有序\n");
    }
    else{
        while (p->next){
            if (order==0){
                if (p->grade>p->next->grade){
                    order=-1;
                }
                if (p->grade<p->next->grade){
                    order=1;
                }
            }
            else if (order==1 && p->grade>p->next->grade){
                printf("无序\n");
                flag=0;
                break;
            }
            else if (order==-1 && p->grade<p->next->grade){
                printf("无序\n");
                flag=0;
                break;
            }
            p=p->next;
        }
        if (flag){
            printf("有序\n");
        }
    }
    struct stu *key=(struct stu *)malloc(sizeof(struct stu));
    printf("输入要插入节点的学号、姓名、性别、年龄、成绩（用空格隔开）\n");
    scanf("%d %s %c %d %lf",&key->num,key->name,&key->sex,&key->age,&key->grade);
    p=head;
    struct stu *pre=NULL;
    if (flag){
        while (p && (key->grade)*order>(p->grade)*order){
            pre=p;
            p=p->next;
        }
        if (p==head){
            head=key;
            key->next=p;
        }
        else{
            pre->next=key;
            key->next=p;
        }
        printf("有序链表，插入后依然有序\n");
        return head;
    }
    else{
        while (p->next){
            p=p->next;
        }
        p->next=key;
        key->next=NULL;
        printf("无序链表插入到末尾\n");
        return head;
    }
}

//4.学生信息链表的节点删除
struct stu *delete_4(struct stu * head){
    printf("输入要删除的学生的学号\n");
    int num;
    scanf("%d",&num);
    int flag=1;
    while (head->num==num){
        flag=0;
        head=head->next;
    }
    struct stu *pre=head;
    struct stu *p=head->next;
    while (p){
        if (p->num==num){
            pre->next=p->next;
            free(p);
            flag=0;
            if (pre->next==NULL){
                break;
            }
        }
        pre=pre->next;
        p=pre->next;
    }
    if (flag){
        printf("该学生不存在\n");
    }
    else{
        printf("已删除\n");
    }
    return head;
}

//5.1学生信息链表的输出（屏幕输出）
void print_5_1(struct stu *head){
    struct stu *p=head;
    while (p){
        printf("%d\t%s\t%c\t%d\t%lf\n",p->num,p->name,p->sex,p->age,p->grade);
        p=p->next;
    }
}

//5.2学生信息链表的输出（保存链表至文件）
void print_5_2(struct stu * head){
    printf("输入要写入链表的文件名\n");
    char fname[50];
    struct stu *p=head;
    fflush(stdin);
    gets(fname);
    FILE *fp;
    if ((fp=fopen(fname,"w"))==NULL){
        printf("文件无法打开，读取失败\n");
        exit(1);
    }
    while (p){
        fprintf(fp,"%d\t%s\t%c\t%d\t%lf\n",p->num,p->name,p->sex,p->age,p->grade);
        p=p->next;
    }
    printf("已写入%s文件\n",fname);
    fclose(fp);
}

//6.学生信息链表的查询
void search_6(struct stu * head){
    struct stu *p=head;
    printf("输入要查找的学生的学号\n");
    int num;
    scanf("%d",&num);
    int flag=1;
    while (p){
        if (p->num==num){
            printf("%d\t%s\t%c\t%d\t%lf\n",p->num,p->name,p->sex,p->age,p->grade);
            flag=0;
        }
        p=p->next;
    }
    if (flag){
        printf("未找到\n");
    }
}
