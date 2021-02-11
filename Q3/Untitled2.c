#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct node
{
  char no[99];
  char number[99];
  int len;
  struct node *next;
};

struct node *new_node_creat(char no[], char number[]);
void push_back(struct node *head, struct node *newNode);

struct node *new_node_creat(char no[], char number[])
{
  struct node *ch;
  ch = (struct node *)malloc(sizeof(struct node));
  strcpy(ch->no, no);
  strcpy(ch->number, number);
  ch->next = NULL;
  return ch;
}

void push_back(struct node *head, struct node *newNode)
{
  struct node *l;
  for (l=head; l->next != NULL; l = l->next);
  l->next = newNode;
}

void remove_node(struct node *head, char no[], int tool)
{
  int i = 0, j = 0;
  struct node * a = head;
  while (a->next != NULL)
  {
    if (strcmp(a->next->no, no) == 0)
    {
      a->next = a->next->next;
      printf("%s has been removed\n", no);
      i = 1;
      break;
    }
    a = a->next;
    if (j == tool)
      break;
  }
  if (i == 0)
    printf("%s does not exist\n",no);
}

void print_list(struct node *list)
{
  int i = 1;
  struct node * current = list;
  current = current->next;
  while(current != NULL)
  {
    printf("%d)\n",i);
    printf("No: %s\n", current->no);
    printf("Phone: %s\n", current->number);
    current = current->next;
    i++;
  }
}

int main()
{
  char p[99], c[99];
  int len = 0, n;
  struct node *a;
  a = (struct node *)malloc(sizeof(struct node));
  a->next = NULL;
  while (1)
  {
    printf("1) Add\n2) Remove\n3) List\n4) Quit\n");
    scanf("%d",&n);
    getchar();
    if (n == 1)
    {
      printf("No: ");
      gets(p);
      printf("Phone: ");
      gets(c);
      len++;
      push_back(a, new_node_creat(p, c));
    }
    else if (n == 2)
    {
      printf("No: ");
      gets(p);
      remove_node(a, p, len);      
    }
    else if (n == 3)
      print_list(a);
    else if (n == 4)
      break;
  }
  return 0;
}
