#include <stdio.h>
#include <string.h>

int display_type(const char s[]);

int main(void) 
{
	display_type();
	return 1;
}

/*
Determine whether a string is of one of the above forms, and if it is, determine which form it is.
form A: n (eg 5)
form B: n+ (eg 5+)
form C: n- (eg 5-)
where n is a positive integer
*/
int display_type(const char s[]) 
{
	/* return 0 if string s is not valid */
	size_t i;
	size_t len;
	
	len = strlen(s);
	
	for(i=0; i < len - 1; i++;)
		if (!(isdigit(s[i])))
			return 0;
		
		/* return 1 if s is a positive int */
	if (isdigit(s[len - 1]))
		return 1;
	else if (s[len - 1] == '+')
		return 2;
	else if (s[len - 1] == '-')
		return 3;
	else
		return 0;
}