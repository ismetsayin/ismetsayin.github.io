#include <stdio.h>
#include <stdlib.h>
#include <conio.h> // #include <ncurses.h> // linux icin

typedef struct node
{
    int data;
    node *next;
    node *prev;
};
int main()
{
    node *root = (node *)malloc(sizeof(node));
    node *iter = root;
    root->prev = NULL;
    for (int i = 0; i < 10; i++)
    {
        iter->data = i * 10;
        iter->next = (node *)malloc(sizeof(node));
        iter->next->prev = iter;
        iter = iter->next;
    }
    iter->next = NULL;
    printf("inserted");
    while (iter->prev != NULL)
    {
        iter = iter->prev;
        printf("%d\n", iter->data);
    }
    getch();
    return 0;
}
