#include <stdio.h>
#include "my.h"

void eval();
char stack[50];
int s[50];
char post[50];
int p = -1;
int top = -1;
int rtop = -1;
int xtop=-1;

void xpush(int elem)
{
    s[++xtop]=elem;
}

int xpop()
{
    return(s[xtop--]);
}

void push(char x)
{
    stack[++top] = x;
}

char pop()
{
    if(top == -1)
        return -1;
    else
        return stack[top--];
}

int priority(char x)
{
    if(x == '(')
        return 0;
    if(x == '+' || x == '-')
        return 1;
    if(x == '*' || x == '/')
        return 2;
}

int main(int ac, char **av)
{
    if (ac == 2) {
        my_put_nbr(eval_expr(av[1]));
        my_putchar('\n');
        return (0);
    }
    return (84);
}

int eval_expr(char const *str)
{
    p=-1;
    char *e;
    char x;
    e = str;
    
    while(*e != '\0') {
        if(my_isalnum(*e)){
            post[++p]=*e;
        }
        else if(*e == '(')
            push(*e);
        else if(*e == ')') {
            while((x = pop()) != '(') {
                post[++p]=x;
            }
        }
        else {
            while(priority(stack[top]) >= priority(*e)) {
                char a;
                a= pop();
                post[++p]=a;
            }
            push(*e);
        }
        e++;
    }
    while(top != -1) {
        char b;
        b=pop();
        post[++p]=b;
    }
    eval();
    return s[xtop];
}

void eval()
{
    int i=0;
    int op1;
    int op2;
    char ch;
    
    while(i != (p+1)) {
        ch=post[i];
        i++;
        if(my_isdigit(ch))
            xpush(ch-'0');
        else {
            op2=xpop();
            op1=xpop();
            switch(ch) {
            case '+':
                xpush(op1+op2);
                break;
            case '-':
                xpush(op1-op2);
                break;
            case '*':
                xpush(op1*op2);
                break;
            case '/':
                xpush(op1/op2);
                break;
            case '%':
                xpush(op1%op2);
                break;
            }
        }
    }
}
