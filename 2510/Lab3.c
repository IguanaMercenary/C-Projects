#include <stdio.h>
#include <ctype.h>

void uppercase_first(void);
void uppercase_last(void);
void squeeze_spaces(void);

int main(void) {
	/*uppercase_first();*/
	uppercase_last();
	/*squeeze_spaces();*/
}

void uppercase_first(void) {
	int c, prev = ' ';
	while ((c = getchar()) != EOF){
		if (isspace(prev))
			putchar(toupper(c));
		else
			putchar(c);
		/* update prev */
		prev = c;
	}
}

void uppercase_last(void) {
	int c, prev = ' ';
	while((c = getchar()) != EOF) {
		/* if char is followed by whitespace */ 
		if (isspace(c))
			putchar(toupper(prev));
		else
			putchar(prev);
		prev = c;
	}
}

void squeeze_spaces(void) {
	int c, prev = ' ';
	while ((c = getchar()) != EOF) {
		/* we don't print if both the previous char & the current char are spaces */
		if (!(prev == ' ' && c == ' '))
			putchar(c);
		prev = c;
	}
	
}