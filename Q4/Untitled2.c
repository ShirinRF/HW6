#include <stdio.h>
#include <stdlib.h>

//void sort(struct node *heada, struct node *headb, struct node *headc);
struct node *new_node_creat(int value);
void push_back(struct node *head, struct node *newNode);

struct node
{
  int value;
  struct node *next;
};

struct nodecp
{
  int value;
  struct node *next;
};


void print_list(struct node *list)
{
  int i = 1;
  struct node * current = list;
  current = current->next;
  while(current != NULL)
  {
    printf("%d ", current->value, i);
    current = current->next;
    i++;
  }
}

void sort(struct node *heada, struct node *headb, struct node *headc)
{
  int i = 0, j, k, z;
  struct node *a = heada, *b = headb, *c = headc;
  a = a->next;
  b = b->next;
  while (a != NULL && b != NULL)
  {
    if (a->value > b->value)
    {
      push_back(c, new_node_creat(a->value));
      a = a->next;
    }
    else
    {
      push_back(c, new_node_creat(b->value));
      b = b->next;
    }
    i++;
  }
  while (a != NULL)
  {
    push_back(c, new_node_creat(a->value));
    a = a->next;
    i++;
  }
  while (b != NULL)
  {
    push_back(c, new_node_creat(b->value));
    b = b->next;
    i++;
  }
  print_list(c);
}

struct node *new_node_creat(int value)
{
  struct node *ch;
  ch = (struct node *)malloc(sizeof(struct node));
  ch->value = value;
  ch->next = NULL;
  return ch;
}

void push_back(struct node *head, struct node *newNode)
{
  struct node *l;
  for (l=head; l->next != NULL; l = l->next);
  l->next = newNode;
}

int main()
{
  int i = 0, j = 0, n;
  struct node *a;
  a = (struct node *)malloc(sizeof(struct node));
  a->value = 0;
  a->next =NULL;
  struct node *b;
  b = (struct node *)malloc(sizeof(struct node));
  b->value = 0;
  b->next =NULL;
  struct node *c;
  c = (struct node *)malloc(sizeof(struct node));
  c->value = 0;
  c->next =NULL;
  while (1)
  {
    scanf("%d",&n);
    if (n == (-1))
      break;
    push_back(a, new_node_creat(n));
    i++;
  }
  while (1)
  {
    scanf("%d",&n);
    if (n == (-1))
      break;
    push_back(b, new_node_creat(n));
    i++;
  }
  sort(a, b, c);
  return 0;
}
