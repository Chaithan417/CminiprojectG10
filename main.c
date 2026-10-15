#include <stdio.h>
#include <ctype.h>
#include "stack.h"

int main()
{
    char infix[50], postfix[50];
    int i, j = 0;
    char x;

    printf("Enter infix: ");
    scanf("%s", infix);

    for (i = 0; infix[i] != '\0'; i++)
    {
        x = infix[i];

        if (isalnum(x))
        {
            postfix[j++] = x;
        }
        else if (x == '(')
        {
            push(x);
        }
        else if (x == ')')
        {
            while (top != -1 && stack[top] != '(')
            {
                postfix[j++] = pop();
            }
            if (top != -1)
            {
                pop();
            }
        }
        else
        {
            while (top != -1 &&
                   ((x == '^' && priority(stack[top]) > priority(x)) ||
                    (x != '^' && priority(stack[top]) >= priority(x))))
            {
                postfix[j++] = pop();
            }

            push(x);
        }
    }

    while (top != -1)
    {
        postfix[j++] = pop();
    }

    postfix[j] = '\0';

    printf("Postfix: %s\n", postfix);

    return 0;
}
