#include<stdio.h>
#include<stdlib.h>
#include<conio.h>

typedef struct Node {
    int data;
    struct Node *next;
    struct Node *prev;
} Node;

Node* replicate(Node* root) {
    Node *tmp = root, *prev = NULL, *next = NULL;

    while (tmp) {
        next = tmp->next;
        tmp->next = prev;
        tmp->prev = next;
        prev = tmp;
        tmp = next;
    }
    return prev;
}

int main() {
    int data, size = 0;
    Node *root=NULL;
    
    while(1) {
        printf("Enter the data (Enter 0 to exit): ");
        scanf("%d", &data);
        if(data==0) {
            if (size < 7) {
                printf("The linked list must be of size atleast 7. Current size: %d\n", size);
                continue;
            } else {
                break;
            }
        }

        Node *n= (Node*) malloc(sizeof(Node));
        n->data=data;
        n->next=NULL;
        n->prev=NULL;

        if(root) {
            for(Node *ptr=root; ptr!= NULL; ptr=ptr->next) {
                if(ptr->next==NULL) {
                    ptr->next=n;
                    n->prev=ptr;
                    break;
                }
            }
        } else {
            root=n;
        }
        size++;
    }

    printf("Thanks for entering the data.\nThis is the generated Linked List: ");
    for(Node *ptr=root; ptr!=NULL; ptr=ptr->next)
        printf("%d->",ptr->data);
    printf("NULL\n");
    
    Node *nroot = replicate(root);
    printf("Linked list in reversed order: ");
    for(Node *ptr=nroot; ptr!=NULL; ptr=ptr->next)
        printf("%d->",ptr->data);
    printf("NULL\n");
    
    return 0;
}