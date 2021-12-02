#include<stdio.h>
#include<stdlib.h>


typedef struct Node {
    int data;
    struct Node *next;
} Node;

Node* replicate(Node* root) {
    Node *tmp = root, *prev = NULL, *next = NULL;

    while (1) {
        next = tmp->next;
        tmp->next = prev;
        prev = tmp;
        tmp = next;
        
        if (tmp == root) {
            tmp->next = prev;
            break;
        }
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
        if(root) {
            for(Node *ptr=root; ; ptr=ptr->next) {
                if(ptr->next==root) {
                    ptr->next=n;
                    n->next = root;
                    break;
                }
            }
        } else {
            root=n;
            n->next = root;
        }
        size++;
    }

    printf("Thanks for entering the data.\nThis is the generated Linked List: ");
    for(Node *ptr=root; ; ptr=ptr->next) {
        printf("%d->",ptr->data);
    
        if (ptr->next == root)
            break;
    }
    printf("ROOT\n");
    
    Node *nroot = replicate(root);
    printf("Linked list in reversed order: ");
    for(Node *ptr=nroot; ; ptr=ptr->next) {
        printf("%d->",ptr->data);
    
        if (ptr->next == nroot)
            break;
    }
    printf("ROOT\n");
    
    return 0;
}