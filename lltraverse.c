#include<stdio.h>
#include<stdlib.h>
typedef struct node
{
    int number;
    struct node *next;
}node;

void main()
{
    int num;
    node *numbers=NULL;
    
    while(1)
    {
        printf("enter the number");
        scanf("%d", &num);
        if(num==0)
        {
            break;
        }
        node *n=malloc(sizeof(node));
        n->number=num;
        n->next=NULL;
        if(numbers)
        {
            for(node *ptr=numbers; ptr!= NULL; ptr=ptr->next)
            if(ptr->next==NULL)
            {ptr->next=n;
            break;}
        }
        else {
        numbers=n;
        }
    }
    printf("Thanks for entering the numbers, here are the digits you entered");
    for(node *ptr=numbers; ptr!=NULL; ptr=ptr->next)
    printf("%d\t",ptr->number);
}