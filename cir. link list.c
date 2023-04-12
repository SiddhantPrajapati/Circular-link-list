//circular link list
#include<stdio.h>
int ins_front();
int ins_rear();
int ins_between();
int del_front();
int del_rear();
int del_between();
int disp();
int count();
int data;

struct node
{
    int val;
    struct node *link;
};
struct node *head=NULL,*tail=NULL;
int main()
{
    int ch;
    do
    {
        printf("Enter your choice \n 1)insert at begging \n 2)insert at ending \n 3)insert in between \n 4)delete at begging \n 5)delete at ending \n 6)delete n th element \n 7)display \n 8)count \n 9)exit \n");
        scanf("%d",&ch);
        switch(ch)
        {
        case 1:
            ins_front();
            break;
        case 2:
            ins_rear();
            break;
        case 3:
            ins_between();
            break;
        case 4:
            del_front();
            break;
        case 5:
            del_rear();
            break;
        case 6:
            del_between();
            break;
        case 7:
            disp();
            break;
        case 8:
            count();
            break;
        case 9:
            printf("Thank you.\n");
            break;
        default :
            printf("Enter valid choice. \n");
            break;
        }
    }
    while(ch!=9);
}
int ins_front()
{
    struct node *ptr;
    ptr=(struct node *)malloc(sizeof(struct node *));
    if(ptr==NULL)
    {
        printf("Underflow.");

    }
    else
    {
        printf("Enter value:");
        scanf("%d",&data);
        ptr->val=data;
        if(head==NULL)
        {
            ptr->link=head;
            head=tail=ptr;
        }
        else
        {
            ptr->link=head;
            head=ptr;
        }
    }
}
int disp()
{
    struct node *ptr;
    ptr=head;
    if(ptr==NULL)
    {
        printf("Nothing to print:");
    }
    else
    {

        printf("\nPrinting values...");
        while(ptr!=tail)
        {
            printf("\n%d",ptr->val);
            ptr=ptr->link;
        }
        printf("\n%d",ptr->val);
    }
    printf("\n");
}
int ins_rear()
{
    struct node *ptr,*temp=NULL;
    ptr=(struct node *)malloc(sizeof(struct node *));
    if(ptr==NULL)
    {
        printf("Underflow.");
    }
    else
    {
        printf("\n Enter value:");
        scanf("%d",&data);
        ptr->val=data;
        if(head==NULL)
        {
            ptr->link=head;
            head=tail=ptr;
        }
        else
        {
                 tail->link=ptr;
                 ptr->link=tail;
                 tail=ptr;
        }
    }
}
int ins_between()
{
    int no;
    int loc=1;
    struct node *ptr,*temp=NULL,*temp2=NULL;
        ptr=(struct node *)malloc(sizeof(struct node *));
        if(ptr==NULL)
        {
            printf("Underflow.");
        }
        else
        {
            printf("\nEnter value:");
                scanf("%d",&data);
                ptr->val=data;
            if(head==NULL)
            {
                ptr->link=head;
                head=tail=ptr;
            }
            else
            {
                printf("\nEnter the no. of place to insert value:");
                scanf("%d",&no);
                temp=head;
                while(temp!=tail)
                {
                    temp2=temp;
                    temp=temp->link;
                    loc++;
                    if(loc==no)
                        break;
                }
                temp2->link=ptr;
                ptr->link=temp;
            }
        }
}
int count()
{
    int number;
    struct node *ptr;
    ptr=head;
    if(ptr==NULL)
    {
        printf("Nothing to print:");
    }
    else
    {

        printf("\nPrinting values...");
        while(ptr!=tail)
        {
            number=number+1;
            ptr=ptr->link;
        }
        number=number+1;
    }
    printf("\n No of Nodes:%d",number);
    printf("\n");
}
int del_front()
{
    struct node *ptr;
    if(head==NULL || tail==NULL)
    {
        printf("\n Link list is empty.\n");
    }
    else
    {
        ptr=head;
        head=ptr->link;
        free(ptr);
    }
}
int del_rear()
{
    struct node *ptr,*ptr1=NULL;
    if(head==NULL || tail==NULL)
    {
        printf("\n Link list is empty.\n");
    }
    else if(head->link==tail)
    {
        ptr=head;
        ptr=tail
        ;
        free(ptr);
    }
    else
    {
       ptr=head;
       while(ptr->link==tail)
       {
           ptr1=ptr;
           ptr=ptr->link;
       }
       ptr1->link=tail;

       free(ptr);
    }
}
int del_between()
{
    int loc,i=1;
    struct node *ptr,*ptr1=NULL;
    if(head==NULL || tail==NULL)
    {
        printf("\n Link list is empty.\n");
    }
    else if(head->link==NULL)
    {
        ptr=head;
        ptr=NULL;
        free(ptr);
    }
    else
    {
        printf("\n Enter the number of place that you want to delete:");
        scanf("%d",&loc);
        ptr=head;
        while(ptr->link!=NULL)
        {
            ptr1=ptr;
            ptr=ptr->link;
            i++;
            if(i=loc)
                break;
        }
        ptr1->link=ptr->link;
        free(ptr);
    }
}
