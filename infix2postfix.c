#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#define STKSZ 100

struct stack { char items[STKSZ]; int top} stk;

void push(char ele)
{
	if (stk.top + 1 == STKSZ) {
		printf("\n[E] Stack Overflow!\n");
		exit(1);
	}
	stk.items[++stk.top] = ele;
}

char pop()
{
	if (stk.top == -1) {
		printf("\n[E] Stack Underflow!\n");
		exit(1);
	}
	return (stk.items[stk.top--]);
}


int priority(char c)
{
	switch (c)
	{
	case '(': return 0;
	case '+': case '-': return 1;
	case '*': case '/': return 2;
	case '$': return 3;
	}
}

void append(char* s, char c) {
        int len = strlen(s);
        s[len] = c;
        s[len+1] = '\0';
}

main()
{
    char number;
    FILE *infile,*outfile;
	char expr[100],*e, x,c;
	stk.top = -1;
	infile = fopen("tokenizer.txt","r");
	outfile=fopen("postfix.txt","w+");
	c= fgetc(infile );
	while (c!=EOF)
            {
                append(expr,c);
                c=fgetc(infile);
            }
    for (e = expr; *e != '\0'; e++)
	{
		if (isalnum(*e))
			fprintf(outfile,"%c", *e);
		else if (*e == ')')
		{
			while ( (x = pop()) != '(')
				fprintf(outfile,"%c", x);
		}
		else if (*e == '(')
			push(*e);
		else
		{
			while ( priority(stk.items[stk.top]) >= priority(*e) )
				fprintf(outfile,"%c", pop());
			push(*e);
		}
	}

	while (stk.top != -1)
		fprintf(outfile,"%c", pop());
	putchar('\n');
    fclose(infile);
    fclose(outfile);
}
