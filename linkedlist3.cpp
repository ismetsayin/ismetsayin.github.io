#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

typedef struct node
{
    int data;
    node *next;
};

node *search(node *, int);

int main()
{
    node *root = (node *)malloc(sizeof(node));
    node *temp = root;

    for (int i = 0; i < 10; i++)
    {
        temp->data = i * 10;
        temp->next = (node *)malloc(sizeof(node));
        temp = temp->next;
    }
    temp->next = NULL;
    printf("inserted");

    temp = root;
    while (temp->next != (node *)0)
    {
        printf("\n%d", temp->data);
        temp = temp->next;
    }

    temp = search(root, 30);
    if (temp != NULL)
        printf("bulunandan sonraki : %d\n", temp->next->data);

    getch();

    return 0;
}
node *search(node *root, int searched)
{
    node *iter = root;
    while (iter != NULL)
    {
        if (iter->data == searched)
            return iter;
        iter = iter->next;
    }

    return NULL;
}