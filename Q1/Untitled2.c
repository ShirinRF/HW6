#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node* next;
};
void printList(struct Node* head)
{
    struct Node* ptr = head;
    while (ptr){
        printf("%d ", ptr->data);
        ptr = ptr->next;
    }
}

void push(struct Node** head, int data)
{
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = *head;
    *head = newNode;
}

void reverse(struct Node** head)
{
    struct Node* prev = NULL;       
    struct Node* current = *head;   
    
    while (current != NULL){
        struct Node* next = current->next;
        current->next = prev;  
        prev = current;
        current = next;
    }
    *head = prev;
}

int main(void)
{
    int i=0,n=0;
	int keys[251];
	for (i = 0; i < 251; i++) { 
            scanf("%d",&keys[i]);
            n++;
			if (keys[i]==0){
				break;
			}
    } 
    struct Node *head = NULL;
    for (i = n-2; i>=0; i--)
        push(&head, keys[i]);
 
    reverse(&head);
    printList(head);
    return 0;
}



