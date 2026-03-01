#include <stdio.h>
#include <ctype.h>
#define MAX 200
char st[MAX];
int top = -1;
int isFull(){
    return top==MAX-1;
}
int isEmpty(){
    return top==-1;
}
void push(char ch){
    if(!isFull())
        st[++top] = ch;
}
char pop(){
    if(isEmpty())
        return '\0';
    else
        return st[top--];
}
int prec(char ch){
    if(ch=='+'||ch=='-')return 1;
    if(ch=='*'||ch=='/'||ch=='%')return 2;
    if(ch=='^')return 3;
    return 0;
}
int right_assoc(char ch){
    return ch=='^';
}
int main(){
    char inf[MAX], post[MAX];
    int i=0,j=0;
    printf("Enter the equation to convert: ");
    scanf("%s",inf);
    for(i = 0;inf[i]!='\0';i++){
        char ch = inf[i];
        if(isalnum((unsigned char)ch))
            post[j++] = ch;
        else if(ch=='(')
            push(ch);
        else if(ch==')'){
            while(top!=-1 && st[top]!='(')
                post[j++] = pop();
            if(top!=-1)
                pop();
        }
        else{
            while(top!=-1 && st[top]!='('&& (prec(st[top])>prec(ch) || (prec(st[top]) == prec(ch) && !right_assoc(ch))))
                post[j++] = pop();
            push(ch);
        }
    }
    while(top!=-1){
        post[j++] = pop();
    }
    post[j] = '\0';
    printf("The converted equation is: \n%s",post);
}
