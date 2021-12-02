#include<stdio.h>
#include<stdlib.h>

typedef struct node
{
    int number;
    struct node *next;
    struct node *prev;
}node;

void main()
{
    int num;
    node *numbers=NULL;

    while(1)
    {
        printf("Enter the elements and press 0 to stop");
        scanf("%d", &num);
        if(num==0)
        {
            break;
        }
        node *n=malloc(sizeof(node));
        n->number=num;
        n->prev=NULL;
        n->next=NULL;
        if(numbers)
        {
            for(node *ptr=numbers; ptr!=NULL; ptr=ptr->next)
                if(ptr->next==NULL)
                {
                    ptr->next=n;
                    ptr->next->prev=ptr;
                    break;
                }
        }
        else {
        numbers=n;
        }
    }
    printf("\nThanks! Here's the doubly linked list you created\n");
    for(node *ptr=numbers; ptr!=NULL; ptr=ptr->next)
    printf("%d\t",ptr->number);
}