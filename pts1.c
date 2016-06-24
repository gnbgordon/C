#include<stdio.h>
#include<string.h>
#include<malloc.h>
#include<stdlib.h>
#define null 0    
typedef struct 
{
    char num[5];       /*Ա�����*/
    char name[8];      /*Ա������*/ 
    char phone[9];     /*�칫�ҵ绰����*/
    char call[12];     /*�ֻ�����*/
}DataType;
/*ͨѶ¼������Ľ������*/
typedef struct node
{   DataType data;   /*����������*/
    struct node *next;   /*����ָ����*/
}ListNode,*LinkList;

LinkList CreatList(void) /*����һ��ͨѶ¼����*/
{  LinkList head,s,p;
   char ch;
   head=(ListNode *)malloc(sizeof(ListNode)); /*����ͷ���*/
   head->next=NULL;
   p=head;
   do
	 {
	   s=(ListNode *)malloc(sizeof(ListNode)); /*����һ����¼���*/
	   printf("����������:");
	   scanf("%s",s->data.name);
	   printf("��������:");
	   scanf("%s",s->data.num);
	   printf("������绰����:");
	   scanf("%s",s->data.phone);
      printf("�������ֻ�����:");
	   scanf("%s",s->data.call);
	   s->next=p->next;
	   p->next=s;
	   printf("����������һ��¼��(y/n)?");
	   scanf("\n%c",&ch);
	  } while(ch=='y'|| ch=='Y');
   return head;   /*����ͷ���ָ��*/
}

ListNode *SearchList(LinkList head) /*��ѯ����*/
{
    ListNode *p;
    int x; /* ���ձ�Ż������������в�����x��ֵ����*/
    char num[5];   /*Ա�����*/
char name[8];  /*Ա������*/ 
    printf("1. ����Ų�ѯ    2.��������ѯ\n");
    printf("��ѡ��:");
    scanf("%d",&x);
    if(x==1)
    {   printf("����������˵ı��:");
	    scanf("%s",num);
        for(p=head;p!=NULL&&strcmp(p->data.num,num)!=0;p=p->next);
    }
    else if(x==2)
    {   printf("����������˵�����:");
	    scanf("%s",name);
        for(p=head;p!=NULL&&strcmp(p->data.name,name)!=0;p=p->next);
    }
    return p;   /*���ز�ָ���ҵ��ļ�¼��ָ�룬��û���ҵ������ص��ǿ�ָ��*/
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
        {   printf("û���ҵ����˵ļ�¼\n");
            return;
         }
       printf("ȷ��Ҫɾ����?(y/n)");
       scanf("\n%c",&ch);
       if(ch=='n')  return;
       for(q=head;q!=NULL&&q->next!=p;q=q->next);
           q->next=p->next;
       free(p);
       printf("ɾ���ɹ�\n");
}

void PrintList(LinkList head)
{
        LinkList p;
        p=head->next;
		printf("  ���          ����             �绰����            �ֻ�����\n");
        while(p!=NULL) 
        {  
        printf("  %s          %s            %s             %s\n",
        p->data.num,p->data.name,p->data.phone,p->data.call);
            p=p->next;
        }
}

void Menu()    /*��ʾ�˵�����*/
{
        printf("     *********�����˾Ա��ͨѶ¼**********\n");
        printf("1-ͨѶ¼����  2-�鿴ȫ����¼ 3-��ѯ  4-������Ա��  5-ɾ���뿪Ա�� 0-�˳�\n");
        printf("��ѡ��(����0--5):");
}
void main()
{
        int t;
        LinkList head,p;
        while(1)
       {
           Menu();
           scanf("%d",&t);  /*ѡ��ϵͳ�ӹ���*/
           switch(t)
          {    case 1:
               printf("����ͨѶ¼\n");
               head=CreatList();
               break;
               case 2:
               printf("�鿴ȫ����¼\n");
             PrintList(head);
             break;
             case 3:
             printf("��ѯ\n");
             p=SearchList(head);
	         if(p)
			 {  printf("���        ����        �绰����       �ֻ�����\n");
                printf("  %s          %s            %s             %s\n",
                p->data.num,p->data.name,p->data.phone,p->data.call);
               }
             else printf("�޴���\n");
             break;
             case 4:
	         printf("����\n");
             p=(ListNode *)malloc(sizeof(ListNode));
	         printf("����������:");
	         scanf("%s",p->data.name);
	         printf("��������:");
	         scanf("%s",p->data.num);
	         printf("������绰����:");
	         scanf("%s",p->data.phone);
             printf("�������ֻ�����:");
	         scanf("%s",p->data.call);
             InsertList(head,p);
             break;
             case 5:
	         printf("ɾ��\n");
             DelNode(head);
             break;
             case 0:
	         printf("�˳�\n");
             return;
            }
         }
}