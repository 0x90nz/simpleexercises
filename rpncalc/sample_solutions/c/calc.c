/**
 * C implementation of the RPN calculator exercise. Note, only very primitive
 * error handling is implemented, for example no stack over/underflow is
 * checked.
 */

#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>

#define STACK_SIZE 512

typedef int stack_item_t;

struct stack {
        stack_item_t data[STACK_SIZE];
        int stack_pointer;
};

void stack_push(struct stack* stack, stack_item_t item)
{
        stack->data[stack->stack_pointer--] = item;
}

stack_item_t stack_pop(struct stack* stack)
{
        return stack->data[++stack->stack_pointer];
}

stack_item_t eval(struct stack* stack, char op)
{
        stack_item_t temp;
        switch (op) {
        case '+': return stack_pop(stack) + stack_pop(stack);
        case '*': return stack_pop(stack) * stack_pop(stack);
        case '-': temp = stack_pop(stack); return stack_pop(stack) - temp;
        case '/': temp = stack_pop(stack); return stack_pop(stack) / temp;
        }
}

bool is_numeric(const char* str)
{
        while (*str) {
                if (*str < '0' || *str > '9')
                        return false;
                str++;
        }
        return true;
}

bool is_op(char op)
{
        return op == '+'
                || op == '-'
                || op == '*'
                || op == '/';
}

void parse_line(struct stack* stack, const char* buffer)
{
        char line[256];
        strncpy(line, buffer, 256);

        char* token = strtok(line, " ");
        while (token) {
                if (is_numeric(token)) {
                        stack_push(stack, strtol(token, NULL, 0));
                } else if (strlen(token) == 1 && is_op(token[0])) {
                        stack_push(stack, eval(stack, token[0]));
                } else {
                        printf("parse error\n");
                }

                token = strtok(NULL, " ");
        }

        printf("%d\n", stack_pop(stack));
}

int main()
{
        char buffer[256];

        // Init stack
        struct stack stack;
        stack.stack_pointer = STACK_SIZE - 1;
        memset(stack.data, 0, sizeof(stack.data));

        while (1) {
                fgets(buffer, sizeof(buffer), stdin);
                if (buffer[0] == '#')
                        break;

                buffer[strcspn(buffer, "\n")] = '\0'; // strip the trailing newline if there is one
                parse_line(&stack, buffer);
        }
}