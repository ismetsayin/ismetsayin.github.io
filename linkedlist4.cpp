#include <stdio.h>
#include <stdlib.h>
#include <conio.h> // #include <ncurses.h> // linux icin

typedef struct node
{
    int data;
    node *next;
};
int main()
{
    node *root = (node *)malloc(sizeof(node));
    root->data = 0;
    root->next = root;
    node *iter = root;

    for (int i = 0; i < 10; i++)
    {
        iter->data = i * 10;
        iter->next = (node *)malloc(sizeof(node));
        iter = iter->next;
        iter->next = root;
    }
    printf("inserted");
    iter = root;
    while (iter->next != root)
    {
        printf("%d\n", iter->data);
        iter = iter->next;
    }
    getch();
    return 0;
}
