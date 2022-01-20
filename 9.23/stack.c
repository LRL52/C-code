#include <stdbool.h>   /* C99 only */
#include <stdio.h>
#include <stdlib.h>
#include<string.h>

#define STACK_SIZE 100

/* external variables */
char contents[STACK_SIZE];
int top = 0;
char s[1005];


void stack_overflow(void)
{
  printf("Stack overflow\n");
  exit(EXIT_FAILURE);
}

void stack_underflow(void)
{
  printf("Stack underflow\n");
  exit(EXIT_FAILURE);
}


void make_empty(void)
{
  top = 0;
}

bool is_empty(void)
{
  return top == 0;
}

bool is_full(void)
{
  return top == STACK_SIZE;
}

void push(char ch)
{
  if (is_full())
    stack_overflow();
  else
    contents[top++] = ch;
}

char pop(void)
{
  if (is_empty())
    stack_underflow();
  else
    return contents[--top];

  return '\0'; /* prevents compiler warning due to stack_underflow() call */
}


int main(void)
{
	scanf("%s", s);
	int len = strlen(s);
	for(int i = 0; i < len; ++i){
		if(s[i] == '{' || s[i] == '(') push(s[i]);
		else {
			if(is_empty()){
				puts("Parentheses/braces are NOT nested properly");
				return 0;
			}
			char t = pop();
			if((s[i] == ')'&&t == '(') ||
			   (s[i] == '}'&&t == '{')){}
			else{
				puts("Parentheses/braces are NOT nested properly");
				return 0;
			}
		}
	}
	if(!is_empty())
		puts("Parentheses/braces are NOT nested properly");
	else
	    puts("Parentheses/braces are nested properly");
	return 0;
}

