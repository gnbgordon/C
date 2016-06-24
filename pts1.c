#include<stdio.h>
#include<string.h>
#include<malloc.h>
#include<stdlib.h>
#define null 0    
typedef struct 
{
    char num[5];       /*员工编号*/
    char name[8];      /*员工姓名*/ 
    char phone[9];     /*办公室电话号码*/
    char call[12];     /*手机号码*/
}DataType;
/*通讯录单链表的结点类型*/
typedef struct node
{   DataType data;   /*结点的数据域*/
    struct node *next;   /*结点的指针域*/
}ListNode,*LinkList;

LinkList CreatList(void) /*建立一个通讯录链表*/
{  LinkList head,s,p;
   char ch;
   head=(ListNode *)malloc(sizeof(ListNode)); /*创建头结点*/
   head->next=NULL;
   p=head;
   do
	 {
	   s=(ListNode *)malloc(sizeof(ListNode)); /*创建一个记录结点*/
	   printf("请输入姓名:");
	   scanf("%s",s->data.name);
	   printf("请输入编号:");
	   scanf("%s",s->data.num);
	   printf("请输入电话号码:");
	   scanf("%s",s->data.phone);
      printf("请输入手机号码:");
	   scanf("%s",s->data.call);
	   s->next=p->next;
	   p->next=s;
	   printf("继续输入下一记录吗(y/n)?");
	   scanf("\n%c",&ch);
	  } while(ch=='y'|| ch=='Y');
   return head;   /*返回头结点指针*/
}

ListNode *SearchList(LinkList head) /*查询函数*/
{
    ListNode *p;
    int x; /* 按照编号或姓名在链表中查找由x的值决定*/
    char num[5];   /*员工编号*/
char name[8];  /*员工姓名*/ 
    printf("1. 按编号查询    2.按姓名查询\n");
    printf("请选择:");
    scanf("%d",&x);
    if(x==1)
    {   printf("请输入待查人的编号:");
	    scanf("%s",num);
        for(p=head;p!=NULL&&strcmp(p->data.num,num)!=0;p=p->next);
    }
    else if(x==2)
    {   printf("请输入待查人的姓名:");
	    scanf("%s",name);
        for(p=head;p!=NULL&&strcmp(p->data.name,name)!=0;p=p->next);
    }
    return p;   /*返回查指向找到的记录的指针，若没查找到，返回的是空指针*/
}

void InsertList(LinkList head,ListNode *p)
{
         p->next=head->next;
         head->next=p;
}

void DelNode(LinkList head)
{
        LinkList p,q;
        char ch;
        p=SearchList(head);
        if(!p)
        {   printf("没有找到此人的记录\n");
            return;
         }
       printf("确定要删除吗?(y/n)");
       scanf("\n%c",&ch);
       if(ch=='n')  return;
       for(q=head;q!=NULL&&q->next!=p;q=q->next);
           q->next=p->next;
       free(p);
       printf("删除成功\n");
}

void PrintList(LinkList head)
{
        LinkList p;
        p=head->next;
		printf("  编号          姓名             电话号码            手机号码\n");
        while(p!=NULL) 
        {  
        printf("  %s          %s            %s             %s\n",
        p->data.num,p->data.name,p->data.phone,p->data.call);
            p=p->next;
        }
}

void Menu()    /*显示菜单函数*/
{
        printf("     *********软件公司员工通讯录**********\n");
        printf("1-通讯录建立  2-查看全部记录 3-查询  4-插入新员工  5-删除离开员工 0-退出\n");
        printf("请选择(输入0--5):");
}
void main()
{
        int t;
        LinkList head,p;
        while(1)
       {
           Menu();
           scanf("%d",&t);  /*选择系统子功能*/
           switch(t)
          {    case 1:
               printf("建立通讯录\n");
               head=CreatList();
               break;
               case 2:
               printf("查看全部记录\n");
             PrintList(head);
             break;
             case 3:
             printf("查询\n");
             p=SearchList(head);
	         if(p)
			 {  printf("编号        姓名        电话号码       手机号码\n");
                printf("  %s          %s            %s             %s\n",
                p->data.num,p->data.name,p->data.phone,p->data.call);
               }
             else printf("无此人\n");
             break;
             case 4:
	         printf("插入\n");
             p=(ListNode *)malloc(sizeof(ListNode));
	         printf("请输入姓名:");
	         scanf("%s",p->data.name);
	         printf("请输入编号:");
	         scanf("%s",p->data.num);
	         printf("请输入电话号码:");
	         scanf("%s",p->data.phone);
             printf("请输入手机号码:");
	         scanf("%s",p->data.call);
             InsertList(head,p);
             break;
             case 5:
	         printf("删除\n");
             DelNode(head);
             break;
             case 0:
	         printf("退出\n");
             return;
            }
         }
}