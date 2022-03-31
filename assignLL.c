#include<stdio.h>
#include<stdlib.h>
typedef struct st
{
        int data;
        struct st *next;
}st;
int cnt=0;
void add_end(st **ptr)
{
        st*temp=(st*)malloc(sizeof(st));
        printf("enter the data\n");
        scanf(" %d",&temp->data);
        cnt++;
//linked list
#if 0
        if(*ptr==NULL)
        {
                temp->next=*ptr;
                *ptr=temp;
        }
        else
        {
                st*last=*ptr;
                while(last->next!=0)
                last=last->next;

                temp->next=last->next;
                last->next=temp;
        }
#endif
//circular linked list
#if 1
        if(*ptr==NULL)
        {
                *ptr=temp;
                temp->next=*ptr;
        }
        else
        {
                st*last=*ptr;
                while(last->next!=*ptr)
                last=last->next;

                temp->next=last->next;
                last->next=temp;
        }
#endif
}
void print(st *ptr)
{
        while(ptr!=NULL)
        {
        printf("%d\n",ptr->data);
        ptr=ptr->next;
        }
}
void add_begin(st **ptr)
{
        st *temp=(st*)malloc(sizeof(st));
        scanf(" %d",&temp->data);
        temp->next=*ptr;
        *ptr=temp;
}
int count(st*ptr)
{
        int c=0;
        st*temp=ptr;
        while(ptr!=NULL)
        {
                c++;
                ptr=ptr->next;
        }
        return c;
}
void reverse(st *ptr)
{
        int c=count(ptr),i;
        st **temp=(st**)malloc(c*sizeof(st*));
        for(i=0;i<c;i++)
        {
                temp[i]=ptr;
                ptr=ptr->next;
        }
        for(i=c-1;i>=0;i--)
        {
                printf("%d ",temp[i]->data);
        }
}
void odd(st*ptr)
{
        st*temp=ptr;
        while(temp!=NULL)
        {
                if(temp->data%2!=0)
                printf("odd numbers are:%d\n",temp->data);

                temp=temp->next;
        }
}
void add_second(st*ptr)
{
        st*temp=(st*)malloc(sizeof(st));
        scanf(" %d",&temp->data);
        st*last=ptr;
        last=last->next;
        temp->next=last->next;
        last->next=temp;
}
void check(st*ptr)
{
        int n=1;
        while(n!=cnt)
        {
                ptr=ptr->next;
                n++;
        }
        if(ptr->next!=NULL)
        printf("it is a circular linked list\n");
        else
        printf("it is not a circular linked list\n");
}
int main()
{
        st *hptr=0;
        char op;
        int o;
        printf("1.write fn to add node after second node\n");
        printf("2.write fn to print node numbers and value if the value is odd\n");
        printf("3.write fn to reverse the linked list\n");
        printf("4.write fn add node at the head\n");
        printf("5.chk if given ll is circular or not using fn\n");
        printf("select the program 1--2--3--4--5 which is given assignment\n");
        scanf("%d",&o);
        printf("start to enter the datas\n");
        switch(o)
        {
                case 1: do
                       {
                               add_end(&hptr);
                               printf("do u want to add another node press 'y'\n");
                               scanf(" %c",&op);
                       }while(op=='y');
                       print(hptr);
 printf("insert one number it will add after second node\n");
                       add_second(hptr);
                       print(hptr);
                       break;
                case 2: do
                        {
                                add_end(&hptr);
                                printf("do u want to add another node press 'y'\n");
                                scanf(" %c",&op);
                        }while(op=='y');
                        print(hptr);
                        odd(hptr);
                        break;
                case 3:do
                        {
                                add_end(&hptr);
                                printf("do u want to add another node press 'y'\n");
                                scanf(" %c",&op);
                        }while(op=='y');
                        print(hptr);
                        reverse(hptr);
                        break;
                 case 4:do
                        {
                                add_end(&hptr);
                                printf("do u want to add another node press 'y'\n");
                                scanf(" %c",&op);
                        }while(op=='y');
                        add_begin(&hptr);
                        print(hptr);
                        break;
                 case 5:do
                        {
                                add_end(&hptr);
                                printf("do u want to add another node press 'y'\n");
                                scanf(" %c",&op);
                        }while(op=='y');
                        check(hptr);
                        break;
                 default:printf("invalid option\n");
                         return 0;

        }
}

