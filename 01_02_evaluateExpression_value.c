// Implement a function to read an arithmetic expression (as given in the previous problem) from the 
// command line and display the computed value of the expression. 

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define MAX 100

char stackOp[MAX];  // operator stack
int topOp = -1;
int stackVal[MAX];  // value stack
int topVal = -1;

void pushOp(char c) { 
    stackOp[++topOp] = c; 
  }

char popOp() { 
    return stackOp[topOp--]; 
}
char peekOp() { 
    return stackOp[topOp]; 
}

int isEmptyOp() { 
    return topOp == -1; 
}

void pushVal(int v) {
     stackVal[++topVal] = v; 
}

int popVal() {
     return stackVal[topVal--]; 
    }

int precedence(char op) {
    if (op == '*' || op == '/') return 2;
    if (op == '+' || op == '-') return 1;
    return 0;
}

// apply operator on two values
int applyOp(int a, int b, char op) 
{
    switch (op) {
        case '+': return a+b;
        case '-': return a-b;
        case '*': return a*b;
        case '/': return a/b;
    }
    return 0;
}

// evaluate infix expression directly
int evaluate(char exp[]) 
{
    for (int i=0; exp[i]; i++)
     {
        char ch = exp[i];

        if (isdigit(ch)) {
            pushVal(ch - '0'); // convert char digit to int
        }

        else if (ch == '(') {
            pushOp(ch);
        }

        else if (ch == ')') 
        {
            while (!isEmptyOp() && peekOp() != '(') 
            {
                int b = popVal();
                int a = popVal();
                char op = popOp();
                pushVal(applyOp(a,b,op));
            }
            popOp(); // remove '('
        }
        else
         { // operator
            while (!isEmptyOp() && precedence(peekOp()) >= precedence(ch))
             {
                int b = popVal();
                int a = popVal();
                char op = popOp();
                pushVal(applyOp(a,b,op));
            }
            pushOp(ch);
        }
    }

    // remaining operators
    while (!isEmptyOp())
     {
        int b = popVal();
        int a = popVal();
        char op = popOp();
        pushVal(applyOp(a,b,op));
    }

    return popVal();
}

int main(int argc, char *argv[]) 
{
    if (argc != 2) {
        printf("Usage: %s <expression>\n", argv[0]);
        return 1;
    }

    int result = evaluate(argv[1]);
    printf("Result = %d\n", result);

    return 0;
}
