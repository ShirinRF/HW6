#include <stdio.h>
#include <stdlib.h>

struct Node {
	int data;
	struct Node* next;
};
typedef struct Node node;

void push(node** head_ref, int new_data)
{
	node* new_node = (node*)malloc(sizeof(struct Node));
	new_node->data = new_data;
	new_node->next = (*head_ref);
	(*head_ref) = new_node;
}
void printList(node* node)
{
	while (node != NULL) {
		printf("%d ", node->data);
		node = node->next;
	}
}
void swapPointer(node** a, node** b)
{
	node* t = *a;
	*a = *b;
	*b = t;
}

int getSize(node* node)
{
	int size = 0;
	while (node != NULL) {
		node = node->next;
		size++;
	}
	return size;
}
node* addSameSize(node* head1,node* head2, int* carry)
{
	if (head1 == NULL)
		return NULL;

	int sum;
	node* result = (node*)malloc(sizeof(node));
	result->next = addSameSize(head1->next, head2->next, carry);
	sum = head1->data + head2->data + *carry;
	*carry = sum / 10;
	sum = sum % 10;
	result->data = sum;
	return result;
}
void addCarryToRemaining(node* head1, node* cur, int* carry, node** result)
{
	int sum;
	if (head1 != cur) {
		addCarryToRemaining(head1->next, cur, carry, result);
		sum = head1->data + *carry;
		*carry = sum / 10;
		sum %= 10;
		push(result, sum);
	}
}
void addList(node* head1, node* head2, node** result)
{
	node* cur;
	if (head1 == NULL) {
		*result = head2;
		return;
	}
	else if (head2 == NULL)
	{
		*result = head1;
		return;
	}

	int size1 = getSize(head1);
	int size2 = getSize(head2);
	int carry = 0;
	if (size1 == size2)
		*result = addSameSize(head1, head2, &carry);

	else {
		int diff = abs(size1 - size2);
		if (size1 < size2)
			swapPointer(&head1, &head2);

		for (cur = head1; diff--; cur = cur->next);
		*result = addSameSize(cur, head2, &carry);
		addCarryToRemaining(head1, cur, &carry, result);
	}
	if (carry)
		push(result, carry);
}
int main(){
	int i,n=0,m=0;
	int arr1[35] ;
	int arr2[35] ;
	node *head1 = NULL, *head2 = NULL, *result = NULL;
	for (i = 0; i < 35; i++) { 
            scanf("%d",&arr1[i]);
            n++;
			if (arr1[i]==-1){
				break;
			}
    } 
    for (i = 0; i < 35; i++) { 
            scanf("%d",&arr2[i]);
            m++;
			if (arr2[i]==-1){
				break;
			}
    } 
	for (i = n - 2; i >= 0; --i)
		push(&head1, arr1[i]);

	for (i = m - 2; i >= 0; --i)
		push(&head2, arr2[i]);

	addList(head1, head2, &result);
	printList(result);
	return 0;
}

