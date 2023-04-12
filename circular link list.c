#include<stdio.h>
#include<stdlib.h>
struct node
{
    int info;
    struct node *link;
}*head=NULL,*last=NULL,*save=NULL,*temp=NULL,*ptr=NULL,
*pred=NULL;
void cinsert_first(int x)
{
    ptr=(struct node*)malloc(sizeof(struct node));
    ptr->info=x;
    if(head==NULL)
    {
        ptr->link=ptr;
        head=last=ptr;
    }
    else
    {
        ptr->link=head;
        last->link=ptr;
        head=ptr;
    }
}
void cinsert_last(int x)
{
    ptr=(struct node*)malloc(sizeof(struct node));
    ptr->info=x;
    if(head==NULL)
    {
        ptr->link=ptr;
        head=last=ptr;
    }
    else
    {
        last->link=ptr;
        ptr->link=head;
        last=ptr;
    }
}
void cinsert_ord(int x)
{
    ptr=(struct node*)malloc(sizeof(struct node));
    ptr->info=x;
    if(head==NULL)
    {
        ptr->link=ptr;
        head=last=ptr;
    }
    if(ptr->info <= head->info)
    {
        ptr->link=head;
        last->link=ptr;
        head=ptr;
    }
    else
    {
        temp=head;
        while(temp!=last && ptr->info >= temp->info)
        {
            save=temp;
            temp=temp->link;
        }
        if(temp==last && ptr->info >= temp->info)
        {
            ptr->link=head;
            last->link=ptr;
            last=ptr;
        }
        else
        {
            ptr->link=save->link;
            save->link=ptr;
        }
    }
}
void display()
{
    temp=head;
    while(temp!=last)
    {
        printf("%d\t",temp->info);
        temp=temp->link;
    }
    printf("%d",temp->info);
}
void delete(int x)
{
    temp=head;
    if(head->info == x)
    {
        pred=head;
        head=head->link;
        free(pred);
    }
    else
    {
        while(temp!=last && temp->info != x)
        {
            pred=temp;
            temp=temp->link;
        }
        if(temp==last && temp->info==x)
        {
            pred->link=head;
            last=pred;
        }
        pred->link=temp->link;
        free(temp);
    }
}
int count()
{
    int count=0;
    temp=head;
    if(head==NULL)
    {
        return count;
    }
    while(temp->link != NULL && temp!=last)
    {
        count++;
        temp=temp->link;
    }
    if(temp==last)
        count++;
    return count;
}
int main()
{
    int ch,n,m,del,od;
    while(1)
    {
        printf("\n1:insert at first\n2:insert at last\n3:insert at ordinary place\n4:delete an element\n5:display\n6:count node\n7:exit....");

        scanf("%d",&ch);
        switch(ch)
        {
            case 1:
            printf("Enter your element :");
            scanf("%d",&n);
            cinsert_first(n);
            break;
            case 2:
            printf("Enter your element :");
            scanf("%d",&m);
            cinsert_last(m);
            break;
            case 3:
            printf("Enter your element :");
            scanf("%d",&od);
            cinsert_ord(od);
            break;
            case 4:
            printf("Enter element that you want to delete :");
            scanf("%d",&del);
            delete(del);
            break;
            case 5:
            display();
            break;
            case 6:
            n=count();
            printf("Your list has %d node",n);
            break;
            case 7:
            return 0;
            break;
            default:
            printf("Enter valid number.....");
            break;
        }
    }
}


