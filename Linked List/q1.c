#include <stdio.h>
#include <stdlib.h>
struct Node
{
    int data;
    struct Node *next;
} *Head = NULL;
void create(int n)
{
    int i;
    struct Node *t, *last;
    Head = (struct Node *)malloc(sizeof(struct Node));

    scanf("%d", &Head->data);
    Head->next = NULL;
    last = Head;
    for (i = 1; i < n; i++)
    {
        t = (struct Node *)malloc(sizeof(struct Node));
        scanf("%d", &t->data);
        t->next = last->next;
        last->next = t;
        last = t;
    }
}
void traverse(struct Node *p)
{
    while (p != NULL)
    {
        printf("%d", p->data);
        p = p->next;
    }
}
void check(struct Node *p)
{
    if (p->next == NULL)
        printf("List is empty\n");
    else
        printf("List is not empty\n");
}
int count(struct Node *p)
{
    int l = 0;
    while (p)
    {
        l++;
        p = p->next;
    }
    printf("%d", l);
}
int insert(struct Node *p, int index, int x)
{
    struct Node *t;
    int i;
    if (index < 0 || index > count(p))
        return 0;
    t = (struct Node *)malloc(sizeof(struct Node));
    t->data = x;
    if (index == 0)
    {
        t->next = Head;
        Head = t;
    }
    else
    {
        for (i = 0; i < index - 1; i++)
        {
            p = p->next;
            t->next = p->next;
            p->next = t;
        }
    }
}
int Delete(struct Node *p, int index)
{
    struct Node *q = NULL;
    int x = -1, i;

    if (index < 1 || index > count(p))
        return -1;
    if (index == 1)
    {
        q = Head;
        x = Head->data;
        Head = Head->next;
        free(q);
        return x;
    }
    else
    {
        for (i = 0; i < index - 1; i++)
        {
            q = p;
            p = p->next;
        }
        q->next = p->next;
        x = p->data;
        free(p);
        return x;
    }
}
int Search(struct Node *p, int key)
{
    if (p == NULL)
    {
        return 0;
    }
    if (key == p->data)
    {
        return key;
    }
    Search(p->next, key);
}
int main()
{
    int choice, data, pos, n;
    while (1)
    {
        printf("1. Create 2. Traverse 3. Insert  4. Delete 5. Search 6. Quit:\n");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            scanf("Enter the size of linked list:%d", &data);
            create(data);
            break;
        case 2:
            traverse(Head);
            break;
        case 3:
            insert(Head, 4, 2);
            break;

        case 4:
            Delete(Head, 3);
            break;
        case 5:
            Search(Head, 3);
            break;

        case 6:
            exit(1);
        default:
            printf("Enter a valid choice");
        }
    }
}
