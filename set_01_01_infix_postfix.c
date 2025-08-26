// Implement a function to convert an infix arithmetic expression involving the operators +, -, /, *, (, ) and 
// single digit constant integer operands to postfix expression. Assume usual precedence of operators in 
// the order of /, *, + and -. Parentheses ( ) are used to override the precedence of operators. 

#include <stdio.h>
#include <ctype.h>   // for isdigit()

#define MAX 100

char stack[MAX];
int top = -1;

// push function
void push(char c) 
{
    stack[++top] = c;
}

// pop function
char pop() 
{
    return stack[top--];
}

// precedence function
int precedence(char c) 
{
    if (c == '*' || c == '/')
        return 2;
    if (c == '+' || c == '-')
        return 1;
    return 0;
}

// infix to postfix conversion
void infixToPostfix(char infix[], char postfix[]) 
{
    int i = 0, j = 0;
    char ch;

    while ((ch = infix[i++]) != '\0') 
    {
        if (isdigit(ch)) {           // if operand → add to postfix
            postfix[j++] = ch;
        }
        else if (ch == '(') {        // if '(' → push
            push(ch);
        }
        else if (ch == ')') 
        {        // if ')' → pop until '('
            while (top != -1 && stack[top] != '(') 
            {
                postfix[j++] = pop();
            }
            pop(); // remove '('
        }
        else 
        {                       // operator
            while (top != -1 && precedence(stack[top]) >= precedence(ch)) 
            {
                postfix[j++] = pop();
            }
            push(ch);
        }
    }

    // pop all remaining operators
    while (top != -1) {
        postfix[j++] = pop();
    }

    postfix[j] = '\0'; // null terminate
}

// main
int main() 
{
    char infix[MAX], postfix[MAX];

    printf("Enter infix expression: ");
    scanf("%s", infix);

    infixToPostfix(infix, postfix);

    printf("Postfix expression: %s\n", postfix);

    return 0;
}

