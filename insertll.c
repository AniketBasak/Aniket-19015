#include<stdio.h>
#include<stdlib.h>

typedef struct node
{
    int number;
    struct node *next;
}node;

void main()
{
    int num,x,y;
    node *numbers=NULL;
    while(1)
    {
        printf("Create a linked list and enter 0 to finish");
        scanf("%d", &num);
        if(num==0)
        break;
        node *n=malloc(sizeof(node));
        n->number=num;
        n->next=NULL;
        if(numbers)
        {
            for(node *ptr=numbers; ptr!=NULL; ptr=ptr->next)
            if(ptr->next==NULL)
            {
                ptr->next=n;
                break;
            }
        }
        else {
        numbers=n;
        }
    }
    printf("Thanks for creating the ll, kindly enter the position where you want to insert a new number");
    scanf("%d",&x);
    printf("\nEnter the number to be inserted");
    scanf("%d",&y);
    node *n=malloc(sizeof(node));
    node *ptr=numbers;
    for(int i=1;i<x-1;i++)
    {
        ptr=ptr->next;
    }
    n->number=y;
    n->next=ptr->next;
    ptr->next=n;

    printf("Thanks for entering the numbers, here are the digits you entered");
    for(node *ptr=numbers; ptr!=NULL; ptr=ptr->next)
    printf("%d\t",ptr->number);
}