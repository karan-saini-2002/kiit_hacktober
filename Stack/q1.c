#include <stdio.h>
#include <stdlib.h>

struct Node
{
    char data;
    struct Node *next;
};
void push(struct Node **top_ref, int new_data);

int pop(struct Node **top_ref);

int isMatchingPair(char character1, char character2)
{
    if (character1 == '(' && character2 == ')')
        return 1;
    else if (character1 == '{' && character2 == '}')
        return 1;
    else if (character1 == '[' && character2 == ']')
        return 1;
    else
        return 0;
}
int areBracketsBalanced(char exp[])
{
    int i = 0;
    struct Node *stack = NULL;
    while (exp[i])
    {
        if (exp[i] == '{' || exp[i] == '(' || exp[i] == '[')
            push(&stack, exp[i]);
        if (exp[i] == '}' || exp[i] == ')' || exp[i] == ']')
        {
            if (stack == NULL)
                return 0;
            else if (!isMatchingPair(pop(&stack), exp[i]))
                return 0;
        }
        i++;
    }
    if (stack == NULL)
        return 1; // balanced
    else
        return 0; // not balanced
}
int main()
{
    char exp[100] = "{[(]}";
    if (areBracketsBalanced(exp))
        printf("Yes\n");
    else
        printf("No\n");
    return 0;
}
void push(struct Node **top_ref, int new_data)
{
    struct Node *new_Node = (struct Node *)malloc(sizeof(struct Node));
    if (new_Node == NULL)
    {
        printf("Stack overflow");
        getchar();
        exit(0);
    }
    new_Node->data = new_data;
    new_Node->next = (*top_ref);
    (*top_ref) = new_Node;
}
int pop(struct Node **top_ref)
{
    char res;
    struct Node *top;
    if (*top_ref == NULL)
    {
        printf("Stack overflow");
        getchar();
        exit(0);
    }
    else
    {
        top = *top_ref;
        res = top->data;
        *top_ref = top->next;
        free(top);
        return res;
    }
}