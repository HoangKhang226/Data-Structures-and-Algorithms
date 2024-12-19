#include <stdio.h>
#include <stdlib.h>
typedef struct node
{
    int data;
    struct node *next;
} node;
node *create_node(int x)
{
    node *newnode = (node *)malloc(sizeof(node));
    newnode->data = x;
    newnode->next = NULL;
    return newnode;
}
void push_front(int x, node **head)
{
    node *newnode = create_node(x);
    newnode->next = *head;
    *head = newnode;
}
void insert(node **head)
{
    node *temp = *head;
    int value=0;
    while (temp != NULL)
    {
        if ( temp->data % 2 != 0)
        {
            node *newnode = create_node(value);
            newnode->next=temp->next;
            temp->next=newnode;
            value+=2;
        }
        temp=temp->next;
    }
}
void print_list(node *head)
{
    node *temp = head;
    while (temp != NULL)
    {
        printf("%d  ", temp->data);
        temp = temp->next;
    }
}
int main()
{
    node *head = NULL;
    int n = 1;
    while (n != 0)
    {
        printf("nhap node( 0 de dung):");
        scanf("%d", &n);
        if (n != 0)
            push_front(n, &head);
    }
    print_list(head);
    insert(&head);
    printf("\n");
    print_list(head);
    return 0;
}