#include<stdio.h>
#include<stdlib.h>
typedef struct node
{
    int number;
    struct node *next;
}node;

void main()
{
    int num,x;
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
    }             //linked list created
    printf("\nPlease enter the value that needs to be removed from the linked list");
    scanf("%d",&x);
    node *temp=numbers;
    node *ptr;
    for(ptr=numbers; ptr!=NULL; ptr=ptr->next)
    {
        if(ptr->next->number==x)
        {
            temp=ptr->next;
            ptr->next=ptr->next->next;
            free(temp);
            break;
        }
    }
    if(ptr==NULL)
    {printf("Number not found");}
    printf("Thanks for entering the numbers, here is the final list");
    for(node *new=numbers; new!=NULL; new=new->next)
    printf("%d\t",new->number);
}    